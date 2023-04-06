#include <string>

#include <jni.h>
#include <android/log.h>


extern "C"
JNIEXPORT jint JNICALL
Java_com_example_jniandroid_MainActivity_addInt(JNIEnv *env, jobject thiz, jint a, jint b) {
    // Android logger example in C++
    __android_log_print(ANDROID_LOG_INFO, "BRIANNA", "addInt(%d, %d) = %d", a, b, a + b);

    return a + b;
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jniandroid_MainActivity_addStr(JNIEnv *env, jobject thiz, jstring a, jstring b) {
    using namespace std;

    // Get raw pointers from Java strings
    // Data can be copied or not, it's up to the JNI
    const char *aP = env->GetStringUTFChars(a, nullptr);
    const char *bP = env->GetStringUTFChars(b, nullptr);

    // Create C++ strings and concatenate, the data is copied
    string s = string(aP) + string(bP);

    // Now that we don't need aP, bP anymore, we release them
    // Otherwise MEMORY LEAK !!!
    env->ReleaseStringUTFChars(a, aP);
    env->ReleaseStringUTFChars(b, bP);

//     cout << "s = " << s << endl;

    // Create a new Java string, the data is copied
    // Java string is memory-managed by the JVM, no memory leaks
    return env->NewStringUTF(s.c_str());

    // Stack object s is destroyed here, but we already copied the data
}