#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Eigen/Core>
#include <Eigen/SVD>
#include <iostream>

using RowMatrixXd = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

Eigen::MatrixXd svd(Eigen::Ref<RowMatrixXd> mat) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(mat, Eigen::ComputeThinU | Eigen::ComputeThinV);
    // std::cout << svd.singularValues() << std::endl;
    return svd.matrixU();
}

Eigen::VectorXd lsq(Eigen::Ref<RowMatrixXd> mat, Eigen::VectorXd b) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(mat, Eigen::ComputeThinU | Eigen::ComputeThinV);
    // std::cout << svd.singularValues() << std::endl;
    return svd.solve(b);
}

namespace py = pybind11;
PYBIND11_PLUGIN(example) {
    py::module m("example", "pybind11 example plugin");

    m.def("svd", &svd,
        py::return_value_policy::reference_internal, 
        "A function do svd");

    m.def("lsq", &lsq,
        py::return_value_policy::reference_internal,
        "solve least square");

    return m.ptr();

}
