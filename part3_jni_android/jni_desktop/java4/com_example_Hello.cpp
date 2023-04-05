#include <iostream>

#include <jni.h>

#include "com_example_Hello.h"


/// Modify Java int[] in place
JNIEXPORT void JNICALL Java_com_example_Hello_modifyArray  (JNIEnv *env, jobject thisObj, jintArray arr) {
    using namespace std;
    
    // Get array length (N of elements)
    jsize n = env->GetArrayLength(arr);
    cout << "array length : n = " << n << endl;
    
    // Get C++ pointer to the array data
    int *p =  env->GetIntArrayElements(arr, nullptr);
    
    // Modify this in place: square each element
    for (int i=0; i<n; ++i) {
        p[i] = p[i] * p[i]; 
    }
    
    // Note: C++ data might be a copy of the original data
    // In this case, modifying it in place will not work
    // We need to release the data and copy it back to Java (third argument : 0==copy)
    env->ReleaseIntArrayElements(arr, p, 0);
    
    // A new array can be created by env->NewIntArray() and returned, we don't do that here 
}
