#include <cstring>
#include <string>

#include <emscripten.h>

extern "C" {
    
    // EMSCRIPTEN_KEEPALIVE ensures that the function is exported and not removed by the linker 
    EMSCRIPTEN_KEEPALIVE
    int int_add(int x, int y) {
        return x + y;
    }
    
    // Emscripten cannot work with C++ strings at the JS/C++ interface, only char *
    EMSCRIPTEN_KEEPALIVE
    char * dup_str(char *s1) {
        using namespace std;
        // But of course we can use C++ classes inside the code
        string s = string(s1) + string(s1);
        // C-strings are 0-terminated, thus +1
        int n = s.size() + 1;
        
        // We cannot return s (a local stack object which dies when this function finishes)
        // We must return a persistent object we allocate on the heap with malloc()
        // Somebody somewhere has to free() it, otherwise memory leak !!!
        // Hopefully ccall/cwrap handles the free() part
        char * buf = (char *)malloc(n);
        memcpy(buf, s.c_str(), n);
        return buf;
    }
}
