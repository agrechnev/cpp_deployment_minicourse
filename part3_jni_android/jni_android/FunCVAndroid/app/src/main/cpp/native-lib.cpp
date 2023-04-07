#include <string>
#include <sstream>

#include <jni.h>
#include <android/log.h>
#include <android/bitmap.h>

#include <opencv2/opencv.hpp>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_funcvandroid_MainActivity_modifyBitmap(JNIEnv *env, jobject thiz, jobject bm) {
    using namespace cv;

    // Get image size from bitmap
    AndroidBitmapInfo info;
    AndroidBitmap_getInfo(env, bm, &info);
    int imW = info.width, imH = info.height;
//    __android_log_print(ANDROID_LOG_INFO, "BRIANNA", "bitmap C++ %d x %d", imW, imH);

    // "Lock pixels", so that we can modify them
    // This can fail (e.g. with immutable bitmap)
    // The pixels are in RGBA !
    void *p;
    if (AndroidBitmap_lockPixels(env, bm, &p)) {
        __android_log_print(ANDROID_LOG_ERROR, "BRIANNA", "AndroidBitmap_lockPixels failure !");
        return;
    }

    // Wrap the pixels with cv::Mat
    Mat imgOrig(imH, imW, CV_8UC4, p);

    // RGBA -> BGR
    Mat img;
    cvtColor(imgOrig, img, COLOR_RGBA2BGR);

    // Modify the image img with OpenCV
    Mat m(img, Rect2i(imW /3, imH / 3, imW /3, imH / 3));
    bitwise_not(m, m);
//    m = Scalar(255, 0, 0); // Blue: test for RGBA pixels

    // BGR -> RGBA
    cvtColor(img, imgOrig, COLOR_BGR2RGBA);

    // Unlock pixels
    AndroidBitmap_unlockPixels(env, bm);
}