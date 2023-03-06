// Example 2: Vectors, strings, maps are auto-converted to python types by pybind

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

int add(int i, int j) {
    return i + j;
}


/// std::string becomes python str
std::string fun_s(const std::string &s) {
    using namespace std;
    cout << "Hello " << s << "!" << endl;
    return s + s;
}

/// std::vector becomes python list
std::vector<int> fun_v(std::vector<int> v) {
    using namespace std;
    sort(v.begin(), v.end());
    return v;
}

/// std::map becomes python dict
std::map<std::string, int> fun_m(std::map<std::string, int> m) {
    using namespace std;
    for (auto &p: m) {
        p.second += 2;
    }
    return m;
}

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind example 2";
    m.def("add", &add, "add function", py::arg("i")=1, py::arg("j")=2);
    
    m.def("fun_s", &fun_s, "string test", py::arg("s"));
    
    m.def("fun_v", &fun_v, "vector test", py::arg("v"));
    
    m.def("fun_m", &fun_m, "map test", py::arg("m"));
}
