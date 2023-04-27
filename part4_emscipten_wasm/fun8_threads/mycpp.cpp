// Fun 8: multithread

#include <thread>
#include <vector>
#include <iostream>

#include <emscripten.h>


extern "C" {
    
    
    EMSCRIPTEN_KEEPALIVE void cpp_fun() {
        using namespace std;
        
        // This is wrong, outputs 12 instead of 6 !
        cout << "thread::hardware_concurrency() = " << thread::hardware_concurrency() << endl << endl;
        
        
        // Start n threads, more that 6 will NOT work, as we set 6 in CMakeLists.txt
        const int n = 6;
        cout << "Starting " << n << " threads ..." << endl;
        vector<thread> tt;
        for (int i=0; i< n; ++i) {
            char c = char('A' + i);
            tt.emplace_back([c]()->void{
                for (int i=0; i< 100; ++i) {
                    cout << c;
                }
            });
        }
        
        cout << "Waiting for the threads to finish ..." << endl;
        
        // Wait for the threads to finish
        for (thread &t: tt)
            t.join();
        
        cout << endl;
        cout << "Threads joined " << endl;
    }
}
