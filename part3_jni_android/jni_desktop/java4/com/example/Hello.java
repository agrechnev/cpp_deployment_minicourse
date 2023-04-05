/// JNI example 4: Modifying Java int[] array in place

package com.example;


import java.util.Arrays;

public class Hello {
    
    /// Load library
    static {
        System.loadLibrary("idiot");
    }

    public static void main(String[] args) {
        // We create an int array (primitive int type)
        int[] intArray = new int[] {3, 4, 11, 7};
        
        // Print the array
        System.out.println("BEFORE : " + Arrays.toString(intArray));
        
        // Modify it in C++
        new Hello().modifyArray(intArray);
        
        System.out.println("AFTER : " + Arrays.toString(intArray));
    }
    
    native void modifyArray(int[] arr);
    
    
}
