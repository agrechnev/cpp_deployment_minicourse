package com.example;
/// Test the Java-wrapped C++ class Box in action

public class Hello { 
    public static void main(String [] args) {
        Box b = new Box("Rabbit");
        System.out.println("get() returns s=" + b.get());
        // Very important, to avoid memory leaks, we must close every object before it can get garbage-collected !
        b.close();
        // Test: Closing for the second time will not crash the code
        b.close();
    }
}
