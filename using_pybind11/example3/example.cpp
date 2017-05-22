#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Eigen/Core>
#include <Eigen/SVD>

Eigen::MatrixXf svd(Eigen::Ref<Eigen::MatrixXf> mat) {
    //Eigen::MatrixXf m = Eigen::MatrixXf::Random(3,2);
    Eigen::JacobiSVD<Eigen::MatrixXf> svd(mat, Eigen::ComputeThinU | Eigen::ComputeThinV);
    return svd.matrixU();
}

namespace py = pybind11;
PYBIND11_PLUGIN(example) {
    py::module m("example", "pybind11 example plugin");

    m.def("svd", &svd, py::return_value_policy::reference_internal, 
        "A function do svd");
    return m.ptr();
}

// m.def("scale", [](py::EigenDRef<Eigen::MatrixXd> m, double c) { m *= c; });
