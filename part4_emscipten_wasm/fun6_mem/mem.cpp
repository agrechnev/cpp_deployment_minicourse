// Fun 6: Check how much memory we can allocate

#include <cstdlib>
#include <iostream>

#include <emscripten.h>

extern "C" {

    EMSCRIPTEN_KEEPALIVE void mem_fun() {
        using namespace std;
        
        
        // Emscripten is 32-bit, size_t and pointers are 32-bit
        // 4 Gb is the limit !
        cout << "void* : " << sizeof(void*) << endl;
        cout << "size_t : " << sizeof(size_t) << endl;
        cout << "int : " << sizeof(int) << endl;
        cout << "long : " << sizeof(long) << endl;
        cout << "long long : " << sizeof(long long) << endl;
        
        // Try allocation up to 4GB with malloc
        for (size_t i=1; i<= 10; ++i) {
            size_t m = i * 400;  // In Mib
            cout << "malloc  " << m << " MiB  : " << (m * 1024 * 1024) << " bytes ";
            void * p = malloc(m * 1024 * 1024);
            if (p == nullptr) {
                cout << "failed !" << endl;
                break;
            } else {
                cout << "success" << endl;
                free(p);
            }
        }
        
        // Same with new
        for (size_t i=1; i<= 10; ++i) {
            size_t m = i * 400;  // In Mib
            cout << "new  " << m << " MiB  : " << (m * 1024 * 1024) << " bytes ";
            
            char * p = new char[m * 1024 * 1024];
            if (p == nullptr) {
                cout << "failed !" << endl;
                break;
            } else {
                cout << "success" << endl;
                delete [] p;
            }
        }
        
        {
            // Check that 1GB memory actually works
            size_t n = 256 * 1024 * 1024;
            cout << "n = " << n << endl;
            
            
            size_t *p = new size_t [n];
            for (size_t i=1; i < n; ++i) {
                p[i] = i;
            }
            for (size_t i=1; i < n; ++i) {
                if (p[i] != i) {
                    cout << "FAILURE i=" << i << endl;
                    break;
                }
            }
            delete [] p;
        }
        
        
        // Alocate 2GB and leave it allocated
//         malloc(2u * 1024 * 1024 * 1024);
    }

}
