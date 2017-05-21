#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Eigen/Core>

class MyClass {
    Eigen::MatrixXd big_mat = Eigen::MatrixXd::Zero(10000, 10000);
public:
    Eigen::MatrixXd &getMatrix() { return big_mat; }
    const Eigen::MatrixXd &viewMatrix() { return big_mat; }
};

namespace py = pybind11;
PYBIND11_PLUGIN(example) {
    py::module m("example", "pybind11 example plugin");

// Later, in binding code:
    py::class_<MyClass>(m, "MyClass")
    .def(py::init<>())
    .def("copy_matrix", &MyClass::getMatrix) // Makes a copy!
    .def("get_matrix", &MyClass::getMatrix, py::return_value_policy::reference_internal)
    .def("view_matrix", &MyClass::viewMatrix, py::return_value_policy::reference_internal);

    return m.ptr();
}