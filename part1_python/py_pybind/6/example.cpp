// Exampel 6: Accessing a numpy array using Eigen


#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

namespace py = pybind11;

// Use eigen types with copy and conversion
Eigen::MatrixXd fun1(Eigen::MatrixXd a){
    using namespace std;
    cout << "================================" << endl;
    cout << "rows =" << a.rows() << endl;
    cout << "cols =" << a.cols() << endl;
    cout << "a =" << a << endl;
    cout << "================================" << endl;
    // Copy then modify
    Eigen::MatrixXd b = a;
    b.array() += 1.5;
    return b;
}

// Use eigen types without copying
void fun2(Eigen::Ref<Eigen::MatrixXd> a) {
    using namespace std;
    cout << "================================" << endl;
    cout << "rows =" << a.rows() << endl;
    cout << "cols =" << a.cols() << endl;
    cout << "a =" << a << endl;
    cout << "================================" << endl;
    // Modify in place
    a.array() += 2.5;
}


PYBIND11_MODULE(example, m) {
    m.doc() = "pybind example 6";
    m.def("fun1", &fun1, "Use Eigen types with copying");
    m.def("fun2", &fun2, "Use Eigen types with no copying");
    
}
