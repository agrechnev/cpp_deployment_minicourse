package com.example;

/// A correct JNI wrapper of a C++ class BoxImpl
/// This class stores a string which can be retrieved with get()

public class Box {
    static {
        System.loadLibrary("idiot");
    }

    /// Java Constructor cannot be native !
    Box(String s) {
        ctorCPP(s);
    }
 
    /// The-facto native constructor
    native void ctorCPP(String s);
    
    /// Get the string from the box
    native String get();
    
    /// Destroy the C++ object, must call this to avoid memoty leaks !!!
    native void close();
    
    /// Note: Java destructor finalize() still works in practive
    /// But produce a deprecated warning
    /// You can enable it as a safeguard against memory leaks
    /// Note: works on garbage collecting only, NOT at the end of the program
//     void finalize() {
//         close();
//     }
    
    /// Pointer to the C++ object, stored as Java long (8 bytes)
    private long handle = 0L;
}
