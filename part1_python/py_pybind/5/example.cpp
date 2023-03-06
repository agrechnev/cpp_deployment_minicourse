// Exampel 5: Accessing a numpy array using py::array
// The data is not copied and can be modified in-place


#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void fun(py::array a){
    using namespace std;
    cout << "================================" << endl;
    cout << "dtype =" << a.dtype().num() << endl;
    cout << "size =" << a.size() << endl;
    cout << "nbytes =" << a.nbytes() << endl;
    cout << "ndim =" << a.ndim() << endl;
    cout << "itemsize =" << a.itemsize() << endl;
    cout << "writeable =" << a.writeable() << endl;
    
    
    cout << "shape = ";
    for (int i=0; i<a.ndim(); ++i) {
        cout << a.shape()[i] << " ";
    }
    cout << endl;
    
    // Print data
    // Warning: works only for double data, supporting arbitrary dtype is much harder !
    // Also non-contiguous arrays would be a major trouble !
    double * data = (double *)a.data();
    cout << "data = ";
    for (int i=0; i < a.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    
    // Modify data in-place
    if (a.writeable()) {
        for (int i=0; i < a.size(); ++i) {
            ++data[i];
        }
    }
    
    cout << "================================" << endl;
}


PYBIND11_MODULE(example, m) {
    m.doc() = "pybind example 5";
    m.def("fun", &fun, "fun function");
    
}
