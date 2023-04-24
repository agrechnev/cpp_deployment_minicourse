#include <iostream>
#include <emscripten.h>

extern "C" {
    // Multiply two double numbers: nothing interesting
    EMSCRIPTEN_KEEPALIVE double mymul(double a, double b) {
        using namespace std;
        double c = a * b;
//         cout << "mymul: " << a << " * " << b << " = " << c << endl;
        return c;
    }
}
