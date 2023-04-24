#include <string>

#include <emscripten/bind.h>

// Add two numbers
int int_add(int x, int y) {
    return x + y;
}

// Now we can concatenate two std::strings !
std::string str_add(const std::string &s1, const std::string &s2) {
    return s1 + s2;
}


using namespace emscripten;

// Generate bindings for our two functions
EMSCRIPTEN_BINDINGS(my_module) {
    function("int_add", &int_add);
    function("str_add", &str_add);
}
