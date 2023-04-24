#include <string>
#include <iostream>

#include <emscripten/bind.h>

/// A class in pure C++ which holds a string
class Hero{
public:
    /// Ctor
    explicit Hero(const std::string &s) : s(s) {
        std::cout << "Hero Ctor : s = " << s << std::endl;
    }
    
    /// Dtor
    ~Hero() {
        std::cout << "Hero Dtor : s = " << s << std::endl;
    }
    
    /// method
    const std::string & getS() const {
        return s;
    }
    
    
private:
    std::string s;
};


// Now generate bindings for it
using namespace emscripten;

EMSCRIPTEN_BINDINGS(hero) {
    class_<Hero>("Hero")
    .constructor<std::string>()
    .function("getS", &Hero::getS);
}
