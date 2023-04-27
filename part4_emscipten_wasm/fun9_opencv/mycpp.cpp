// Fun 9: opencv

#include <thread>
#include <vector>
#include <iostream>

#include <emscripten.h>

#include <opencv2/opencv.hpp>


extern "C" {
    
    
    EMSCRIPTEN_KEEPALIVE void cpp_fun() {
        using namespace std;
        
        cv::Mat m = cv::Mat::ones(23, 34, CV_8UC3);
        cout << m.size << endl;
        
    }
    
}
