// Fun 9: opencv

#include <thread>
#include <vector>
#include <iostream>

#include <emscripten.h>

#include <opencv2/opencv.hpp>


extern "C" {
    
    
    EMSCRIPTEN_KEEPALIVE
    void processImage(uint8_t *buffer, size_t size, int width, int height){
        using namespace std;
        using namespace cv;
        
        cout << "OpenCV version = " << CV_VERSION << endl;
        CV_Assert(4 * width*height == size);
        
        // Wrap buffer with a cv::Mat (no copying)
        Mat m1(height, width, CV_8UC4, buffer);
        
        // Convert RGBA->BGR
        Mat m2;
        cvtColor(m1, m2, COLOR_RGBA2BGR);
        
        // Modify the BGR image with OpenCV
        int w13 = width / 3;
        int h13 = height / 3;
        Mat m(m2, Range(h13, 2*h13), Range(w13, 2*w13));
        bitwise_not(m, m);
        
        // Convert BGR->GRBA
        cvtColor(m2, m1, COLOR_BGR2RGBA);
        
    }
    
}
