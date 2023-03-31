/// JNI example 1 : Call a C++ method

package com.example;


public class Hello {

    /// Load the shared library libidiot.so (which contains built C++ code)
    static {
        System.loadLibrary("idiot");
    }

    /// Main method: Create a Hello java object and run the native method sayHi()
    public static void main(String[] args) {
        new Hello().sayHi();
    }
        
    /// Native method: implemented in C++ via JNI
    private native void sayHi();
    
}
