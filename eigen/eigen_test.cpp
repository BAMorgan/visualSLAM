//
// Created by Brandon on 6/24/2025.
//
#include "eigen_test.h"
#include <Eigen/Core>
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace Eigen;

#define MATRIX_SIZE 50;

void eigen_test(){
//All matrix/vectors are Eigen::Matrix(data type, row, column,...)
   Matrix<float, 2 , 3> matrix_23;
   //Eigen has types in 'typedef', but all are still Eigen::Matrix under the hood
   // EXAMPLE: Vector3d is the same thing as Matrix<double,3, 1>, which is a 3D vector

   //Matrix3d is a 3x3 vector
   Matrix3d matrix_33 = Matrix3d::Zero();

   //Can have dynamic matrix size if you don't have static dimensions
   Matrix<double, Dynamic, Dynamic> matrix_dynamic;
   //MatrixXd is the same thing has the above

   //Initializing the matrix
   matrix_23 << 1, 2, 3, 4, 5, 6;
   //outputting
   std::cout << matrix_23 << "\n";

   //Accessing elements through parameters
   std::cout << "print matrix_23: " << "\n";
   for (int i = 0; i < matrix_23.rows(); i++)
   {
      for (int j = 0; j < matrix_23.cols(); j++)
      {
         std::cout << matrix_23(i, j) << "\t";
      }
   }
   std::cout << "\n";

   Vector3d v_3d;
   v_3d << 3, 2, 1;
   Matrix<float, 3, 1> vd_3d;
   vd_3d << 4, 5, 6;
   //In Eigen we must explicitly convert matrix types before operations
   Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
   std::cout << "[1,2,3;4,5,6] *[3,2,1]: " << result.transpose() << "\n";
   //Matrix<float, 2, 1> result2 = matrix_23.cast<double>() * vd_3d;
   // std::cout << "[1,2,3;4,5,6] *[4,5,6]: " << result2.transpose() << "\n";

   //EXAMPLE: mixing matrices of differing size
   //Eigen::Matrix<double, 2, 3> result_wrong_dimension = matrix_23.cast<double>() * v_3d;

   //Matrix Operations (without +-*/)
   matrix_33 = Matrix3d::Random();
   std::cout << "random matrix:  \n" << matrix_33 << "\n";
   std::cout << "transpose: \n" << matrix_33.transpose() << "\n";
   std::cout << "sum: \n" << matrix_33.sum() << "\n";
   std::cout << "trace: \n" << matrix_33.trace() << "\n";
   std::cout << "times 10 \n" << matrix_33 * 10 << "\n";
   std::cout << "inverse \n" << matrix_33.inverse() << "\n";
   std::cout << "det \n" << matrix_33.determinant() << "\n";

   //Eigenvalues
   //Real symmetric matrix = successful diagonalization
   SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
   std::cout << "Eigen values: = \n" << eigen_solver.eigenvalues() << "\n";
   std::cout << "Eigen vectors: = \n" << eigen_solver.eigenvectors() << "\n";


}