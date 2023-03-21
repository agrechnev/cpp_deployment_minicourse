// OpenCV ONNX inference

#include <iostream>
#include <string>
#include <array>

#include <opencv2/opencv.hpp>


/// Divide an 1 x 3 x H x W (channel-first) cv::Mat by std
void divByStd(cv::Mat &m, const std::array<float, 3> &s) {
    CV_Assert(m.total() % 3 == 0 && m.type() == CV_32F);
    int n = m.total() / 3;
    float *p = (float *) m.data;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            p[n*i + j] /= s[i];
        }
    }
}


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
    
    
    /// This is totally wrong, the OpenCV tutorial is wrong !!!
//     divide(blob, Scalar(0.229, 0.224, 0.225), blob);
    
    /// This is the correct division
    divByStd(blob, {0.229, 0.224, 0.225});

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
