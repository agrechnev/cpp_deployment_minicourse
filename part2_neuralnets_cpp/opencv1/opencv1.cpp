// OpenCV ONNX inference

#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

int main(){
    using namespace std;
    using namespace cv;

    // Load the ONNX model
    dnn::Net net = dnn::readNet("resnet50.onnx");
    
    // Optional: print the model
//     cout << net.dump() << endl;

    // LOad image
    string imgPath = "../../images/gpig1.jpg";
    Mat img = imread(imgPath);
//    imshow("img", img);
//    waitKey(0);

    // Convert to the 1x3x224x224 tensor
    Mat blob;
    dnn::blobFromImage(img, blob, 1.0 / 255, {224, 224}, {0.485, 0.456, 0.406}, true, false);
    blob /= Scalar(0.229, 0.224, 0.225);

    cout << "blob : " << blob.size << endl;

    // Run the actual inference
    net.setInput(blob);
    Mat prob = net.forward();

    // Print the result (should be 338)
    Point2i clz;
    minMaxLoc(prob, 0, 0, 0, &clz);
    cout << "clz =" << clz << endl;

    return 0;
}
