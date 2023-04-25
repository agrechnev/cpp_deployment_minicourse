// Fun 7: C++ exceptions

#include <stdexcept>
#include <iostream>

#include <emscripten.h>

extern "C" {

    EMSCRIPTEN_KEEPALIVE void excep_fun() {
        using namespace std;
        
//         throw runtime_error("I am no man !");
        
        
        try {
            throw runtime_error("If I could be where you are ...");
        } catch (std::exception &e) {
            cout << "Caught : " << e.what() << endl;
        }
        
        
    }
}
