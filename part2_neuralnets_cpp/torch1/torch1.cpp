// Torch example 1: Load resnet50 (traced) and run inference
// For simplicity, we use CPU

#include <iostream>
#include <string>

#include <torch/script.h>

#include <opencv2/opencv.hpp>

//======================================================================================================================
void printMe(const at::Tensor &t, const std::string &name) {
    using namespace std;
    cout << name << " : (";
    for (int i = 0; i < t.ndimension(); ++i) {
        if (i > 0)
            cout << ",";
        cout << t.size(i);
    }
    cout << ") " << t.dtype() << " ";
    cout << t.min().item() << " " << t.to(torch::ScalarType::Float).mean().item() << " " << t.max().item();
//    cout << t.min().item() << " " << t.max().item();
    cout << endl;
}

//======================================================================================================================
/// Convert an RGB (!) uint8 image to torch tensor 1x3xHxW with imagenet normalization
at::Tensor img2tensor(const cv::Mat &img) {
    using namespace std;
    // Note: from_blob does not copy the data ! Thus t does not own the uint8 data
    // But once we transform it to float, t becomes a data-owning tensor
    int imW = img.cols, imH = img.rows, imC = img.channels();
    CV_Assert(imC == 3);
    at::Tensor t = torch::from_blob(img.data, {imH, imW, imC}, torch::TensorOptions(torch::ScalarType::Byte));
    t = t.to(torch::ScalarType::Float) / 255.;
    at::Tensor tMean = torch::tensor({0.485, 0.456, 0.406});
    at::Tensor tStd = torch::tensor({0.229, 0.224, 0.225});
    t = (t - tMean) / tStd;
    t = t.permute({2, 0, 1}).unsqueeze(0);
    return t;
}

//======================================================================================================================
int main() {
    using namespace std;

    // Load model
    torch::jit::script::Module model;
    model = torch::jit::load("resnet50_traced.pt");

    // Load image, convert to RGB, downsize
    cv::Mat img = cv::imread("../../images/gpig1.jpg");
    cv::Mat imgInf;
    cv::cvtColor(img, imgInf, cv::COLOR_BGR2RGB);
    cv::resize(imgInf, imgInf, {224, 224});

    // Convert image to torch tensor
    at::Tensor tIn = img2tensor(imgInf);
    printMe(tIn, "tIn");

    // Run the inference
    at::Tensor tOut = model.forward({tIn}).toTensor();
    printMe(tOut, "tOut");

    cout << "PREDICTED CLASS = " << tOut.squeeze().argmax().item() << endl;   // Should be 338

    return 0;
}
