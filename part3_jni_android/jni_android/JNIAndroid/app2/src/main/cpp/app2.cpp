#include <iostream>
#include <fstream>
#include <string>

#include <jni.h>
#include <android/log.h>

// Write C++ code here.

extern "C"
JNIEXPORT void JNICALL
Java_com_example_app2_MainActivity_writeText(JNIEnv *env, jobject thiz, jstring fileName) {
    using namespace std;

    // Java String to std::string as usual
    const char * p = env->GetStringUTFChars(fileName, nullptr);
    string fileNameS(p);
    env->ReleaseStringUTFChars(fileName, p);

    // Write data to file
    ofstream out(fileNameS);
    __android_log_print(ANDROID_LOG_INFO, "BRIANNA", "good=%d", int(out.good()));
    out << "The old pond," << endl;
    out << "A frog jumps in:" << endl;
    out << "Plop!" << endl;
}