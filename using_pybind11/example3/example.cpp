#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Eigen/Core>
#include <Eigen/SVD>

using RowMatrixXd = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

Eigen::MatrixXd svd1(Eigen::Ref<Eigen::MatrixXd> mat) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(mat, Eigen::ComputeThinU | Eigen::ComputeThinV);
    return svd.matrixU();
}

Eigen::MatrixXd svd2(pybind11::EigenDRef<Eigen::MatrixXd> mat) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(mat, Eigen::ComputeThinU | Eigen::ComputeThinV);
    return svd.matrixU();
}

Eigen::MatrixXd svd3(Eigen::Ref<RowMatrixXd> mat) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(mat, Eigen::ComputeThinU | Eigen::ComputeThinV);
    return svd.matrixU();
}

namespace py = pybind11;
PYBIND11_PLUGIN(example) {
    py::module m("example", "pybind11 example plugin");

    m.def("svd1", &svd1,
        py::return_value_policy::reference_internal, 
        "A function do svd1");

    m.def("svd2", &svd2,
        py::return_value_policy::reference_internal, 
        "A function do svd1");

    m.def("svd3", &svd3,
        py::return_value_policy::reference_internal, 
        "A function do svd3");
    return m.ptr();
}
