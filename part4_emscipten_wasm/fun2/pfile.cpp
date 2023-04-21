#include <iostream>
#include <string>

#include <emscripten.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE void print_file(uint8_t *buffer, size_t size) {
        using namespace std;
        cout << "print_file: size=" << size << endl;
        cout << string((char *)buffer, size);
    }
}
