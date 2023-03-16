// TFLITE1: AN (almost) minimal C++ TFLITE example, runs ResNet50 on an image
#include <iostream>
#include <algorithm>

#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"
#include "tensorflow/lite/optional_debug_tools.h"

#include <opencv2/opencv.hpp>

//======================================================================================================================
cv::Mat img2tensor(cv::Mat &img) {
    using namespace std;
    using namespace cv;
    Mat t;
    img.convertTo(t, CV_32FC3);
    // Subtract channel means
    t -= Scalar(103.939, 116.779, 123.68);
    return t;
}

//======================================================================================================================
inline void printTensInfo(const TfLiteTensor *t) {
    using namespace std;
    cout << "name=\"" << t->name << "\", dtype=" << t->type << ", dims=";
    for (int i = 0; i < t->dims->size; ++i) {
        if (i > 0)
            cout << "x";
        cout << t->dims->data[i];
    }
    cout << endl;
}

void printModel(const tflite::Interpreter &interpreter) {
    using namespace std;
    cout << "=======================================" << endl;
    cout << "INPUTS :" << endl;
    for (int idx: interpreter.inputs()) {
        cout << idx << " : ";
        const TfLiteTensor *t = interpreter.tensor(idx);
        printTensInfo(t);
    }

    cout << "OUTPUTS :" << endl;
    for (int idx: interpreter.outputs()) {
        cout << idx << " : ";
        const TfLiteTensor *t = interpreter.tensor(idx);
        printTensInfo(t);
    }
    cout << "=======================================" << endl;
}

//======================================================================================================================
int main() {
    using namespace std;
    using namespace cv;
    // Load TFLITE model
    std::unique_ptr<tflite::FlatBufferModel> model = tflite::FlatBufferModel::BuildFromFile("./resnet50.tflite");
    CV_Assert(model != nullptr);

    // Build interpreter, allocate tensors
    tflite::ops::builtin::BuiltinOpResolver resolver;
    tflite::InterpreterBuilder builder(*model, resolver);
    std::unique_ptr<tflite::Interpreter> interpreter;
    builder(&interpreter);
    CV_Assert(interpreter != nullptr);
    CV_Assert(interpreter->AllocateTensors() == kTfLiteOk);
//    tflite::PrintInterpreterState(interpreter.get());

    // Optional: print model information
    printModel(*interpreter);

    // Load image
    Mat img = imread("../../images/gpig1.jpg");
//    imshow("img", img);
//    waitKey(0);

    // Downsize to 224x224, convert to RGB, convert to tensor
    Mat imgInf;
    resize(img, imgInf, {224, 224});
    cvtColor(imgInf, imgInf, COLOR_BGR2RGB);
    Mat imgTens = img2tensor(imgInf);

    // Prepare tensors
    float *bufIn = interpreter->typed_input_tensor<float>(0);
    float *bufOut = interpreter->typed_output_tensor<float>(0);
    memcpy(bufIn, imgTens.data, imgTens.channels() * imgTens.total() * sizeof(float));

    // Run the actual inference
    CV_Assert(interpreter->Invoke() == kTfLiteOk);

    // Print the result
    int pred = max_element(bufOut, bufOut + 1000) - bufOut;
    cout << "PREDICTED CLASS = " << pred << endl;   // 338

    return 0;
}
