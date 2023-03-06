// Example 4: Same as example 3, but build with cmake

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


/// A simple custom C++ class
class Hero{
public:
    Hero(int age) : age(age) {}
    
    int getAge() {return age;}
    
    ~Hero(){
        std::cout << "Hero Dtor " << age << std::endl; 
    }
    
private:
    int age;
};


namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind example 4";
    
    py::class_<Hero>(m, "Hero").def(py::init<int>()).def("getAge", &Hero::getAge);
}
