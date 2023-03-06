#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind minimal example";
    m.def("add", &add, "add function", py::arg("i")=1, py::arg("j")=2);
}
