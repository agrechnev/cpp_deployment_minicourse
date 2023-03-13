// Example 2: ONNX inference of resenet50 in C++

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include <opencv2/opencv.hpp>

#include <onnxruntime/core/session/onnxruntime_cxx_api.h>

//======================================================================================================================
template<typename T>
void print(const T &t, char sep = ' ') {
    for (const auto &el: t)
        std::cout << el << sep;
}

//======================================================================================================================
/// Print tensor inputs/outputs name and shape
void printModel(const Ort::Session &sess) {
    using namespace std;
    Ort::AllocatorWithDefaultOptions allocator;

    // Note: For older ORT versions, use sess.GetInputName() instead !
    int nIn = sess.GetInputCount();
    cout << "Inputs: " << nIn << " : " << endl;
    for (int i = 0; i < nIn; ++i) {
        auto tInfo = sess.GetInputTypeInfo(i);
        auto ti = tInfo.GetTensorTypeAndShapeInfo();
//        cout << "count=" << ti.GetDimensionsCount() << endl;

        vector<int64_t> shape = ti.GetShape();
        cout << i << " : " << sess.GetInputNameAllocated(i, allocator).get() << ", shape=";
        print(shape, ' ');
        cout << endl;
    }

    int nOut = sess.GetOutputCount();
    cout << "Outputs: " << nOut << " : " << endl;
    for (int i = 0; i < nOut; ++i) {
        auto tInfo = sess.GetOutputTypeInfo(i);
        auto ti = tInfo.GetTensorTypeAndShapeInfo();
//        cout << "count=" << ti.GetDimensionsCount() << endl;
        vector<int64_t> shape = ti.GetShape();
        cout << i << " : " << sess.GetOutputNameAllocated(i, allocator).get() << ", shape=";
        print(shape, ' ');
        cout << endl;
    }
}

//======================================================================================================================
/// Print some info on a matrix (min, mean, max)
void printMe(const cv::Mat &mat, const std::string &name) {
    using namespace std;
    using namespace cv;

    double minVal, maxVal;
    minMaxLoc(mat, &minVal, &maxVal);
    cout << name << " : " << minVal << " " << mean(mat)[0] << " " << maxVal << endl;
}

//======================================================================================================================
/// Convert one channel from uint8 to normalized float32
cv::Mat tensorize(const cv::Mat &in, float m, float s) {
    using namespace std;
    using namespace cv;

//    printMe(in, "in");

    Mat tmp1;
    in.convertTo(tmp1, CV_32F, 1. / 255);
    tmp1 -= m;
    tmp1 /= s;
//    printMe(tmp1, "tmp1");
    return tmp1;
}

//======================================================================================================================
/// Convert cv::Mat BGR (!) image to tensor
std::vector<float> img2tensor(const cv::Mat &img) {
    using namespace std;
    using namespace cv;

    int imW = img.cols, imH = img.rows;
    // Split into BGR channels
    vector<Mat> channels;
    split(img, channels);
    CV_Assert(channels.size() == 3);

    // Imagenet mean, std
    vector<float> vM{0.485, 0.456, 0.406};
    vector<float> vS{0.229, 0.224, 0.225};

    // Tensorize each channel
    vector<Mat> channelsT;
    for (int i = 0; i < 3; ++i) {
        int iBGR = 2 - i;  // BGR index
        channelsT.push_back(tensorize(channels[iBGR], vM[i], vS[i]));
    }

    // Put them all together
    vector<float> res(3 * imW * imH);
    for (int i = 0; i < 3; ++i) {
        memcpy(res.data() + imW * imH, channelsT[i].data, imW * imH * sizeof(float));
    }
    return res;
}

//======================================================================================================================
/// Multiply elements in a vector
template <typename T>
T mulVec(const std::vector<T> & v) {
    return std::accumulate(v.cbegin(), v.cend(), 1, std::multiplies<T>());
}

//======================================================================================================================
int main() {
    using namespace std;
    using namespace cv;

    // Create the "environment" with logger
    // Change this ORT_LOGGING_LEVEL_INFO and see what happens !
    Ort::Env env(ORT_LOGGING_LEVEL_WARNING);

    // Create session and load the ONNX file
    Ort::Session sess(env, "./resnet50.onnx", Ort::SessionOptions());

    // Optional: Print inputs and outputs to the console
    printModel(sess);

    // Get input/output size from the model
    auto tInfoIn = sess.GetInputTypeInfo(0);
    auto tTSIn = tInfoIn.GetTensorTypeAndShapeInfo();
    vector<int64_t> shapeIn = tTSIn.GetShape();  // {1, 3, 224, 224}
    auto tInfoOut = sess.GetOutputTypeInfo(0);
    auto tTSOut = tInfoOut.GetTensorTypeAndShapeInfo();
    vector<int64_t> shapeOut = tTSOut.GetShape(); // {1, 1000}

    // Load image
    Mat img = imread("../../images/gpig1.jpg");
//    imshow("img", img);
//    waitKey(0);

    //  downsize to inference size
    Mat imgInf;
    resize(img, imgInf, {(int)shapeIn[3], (int)shapeIn[2]});

    // Convert to tensor
    vector<float> x = img2tensor(imgInf);
    vector<float> y(mulVec(shapeOut));
    CV_Assert(x.size() == mulVec(shapeIn));

    // Wrap the data with ORT tensors (no copying)
    vector<Ort::Value> inputTensors;
    vector<Ort::Value> outputTensors;
    Ort::MemoryInfo memoryInfo = Ort::MemoryInfo::CreateCpu(OrtAllocatorType::OrtArenaAllocator,
                                                            OrtMemType::OrtMemTypeDefault);
    inputTensors.push_back(Ort::Value::CreateTensor<float>(memoryInfo, x.data(), mulVec(shapeIn), shapeIn.data(), shapeIn.size()));
    outputTensors.push_back(Ort::Value::CreateTensor<float>(memoryInfo, y.data(), mulVec(shapeOut), shapeOut.data(), shapeOut.size()));

    vector<const char *> inputNames{"input1"};
    vector<const char *> outputNames{"output1"};

    sess.Run(Ort::RunOptions{nullptr}, inputNames.data(), inputTensors.data(), 1, outputNames.data(),
             outputTensors.data(), 1);

    // Print the result
    int pred = max_element(y.cbegin(), y.cend()) - y.cbegin();
    cout << "PREDICTED CLASS = " << pred << endl;  // Should be 338
    cout << "Should be 338" << endl;

    return 0;
}
