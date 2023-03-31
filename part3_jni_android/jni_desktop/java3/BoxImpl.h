#include <iostream>
#include <string>

/// A Pure C++ class, which stores a std::string value, NO JNI here !
/// We also log constructor and destructor to stdout
class BoxImpl {
public:
    /// Ctor
    BoxImpl(const std::string &s) : s(s) {
        std::cout << "C++ ctor s=" << s << std::endl;
    }
    
    /// Dtor
    ~BoxImpl() {
        std::cout << "C++ dtor s=" << s << std::endl;
    }
        
    const std::string &get() const {
        return s;
    }
    
private:
    /// STring contained in a box
    std::string s;
};
