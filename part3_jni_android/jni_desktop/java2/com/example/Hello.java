/// JNI example 2: Arguments, return values, primitives, then strings

package com.example;

public class Hello {
    
    /// Load library
    static {
        System.loadLibrary("idiot");
    }

    public static void main(String[] args) {
        Hello h = new Hello();
        System.out.println(h.addInt(13, 8));
        System.out.println(h.addStr("One", "Two"));
    }
    
    
    /// Native method with primitives
    private native int addInt(int a, int b);
    
    /// Native method with Java strings
    private native String addStr(String a, String b);
    
}
