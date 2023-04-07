#include <jni.h>
#include <android/log.h>
#include <android/bitmap.h>


/// Modify pixels in pure C++
void modifyPix(unsigned int *p, int imW, int imH) {
    // Central 1/9 rect boundaries
    int x1 = imW / 3;
    int x2 = 2 * x1;
    int y1 = imH / 3;
    int y2 = 2 * y1;

//    unsigned char *pc = (unsigned char *) (p + imW * 100 + 100);
//    __android_log_print(ANDROID_LOG_INFO, "BRIANNA", "pix = %d %d %d %d", pc[0], pc[1], pc[2], pc[3]);

    // Apply photo negative to RGBA
    for (int iy = y1; iy < y2; ++iy) {
        unsigned int *row = p + imW * iy;
        for (int ix = x1; ix < x2; ++ix) {
            row[ix] ^= 0x00ffffff;
//            row[ix] = 0xffff0000;
        }
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_app3_MainActivity_modifyPixels(JNIEnv *env, jobject thisObj, jintArray pix,
                                                jint imW,
                                                jint imH) {
    // Get array length (N of elements)
    jsize n = env->GetArrayLength(pix);

    if (n != imW * imH) {
        __android_log_print(ANDROID_LOG_ERROR, "BRIANNA", "modifyPixels: Wrong size !!!");
        return;
    }

    // Get C++ pointer to the array data
    // The data is in BGRA !!!
    int *p = env->GetIntArrayElements(pix, nullptr);

    // Modify pixels in pure C++
    modifyPix((unsigned int *) p, imW, imH);

    // Release Array element, copies data if needed
    env->ReleaseIntArrayElements(pix, p, 0);
}



extern "C"
JNIEXPORT void JNICALL
Java_com_example_app3_MainActivity_modifyBitmap(JNIEnv *env, jobject thisObj, jobject bm) {
    // Get info: bitmap size etc
    AndroidBitmapInfo info;
    AndroidBitmap_getInfo(env, bm, &info);
    int imW = info.width, imH = info.height;

    // "Lock pixels", so that we can modify them
    // This can fail (e.g. with immutable bitmap)
    // THe data is in RGBA, different from teh previous routine
    unsigned int *p;
    if (AndroidBitmap_lockPixels(env, bm, (void **) &p)) {
        __android_log_print(ANDROID_LOG_ERROR, "BRIANNA", "AndroidBitmap_lockPixels failure !");
        return;
    }

    // Modify pixels
    modifyPix(p, imW, imH);

    // Unlock pixels
    AndroidBitmap_unlockPixels(env, bm);
}