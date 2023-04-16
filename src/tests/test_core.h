#ifndef SRC_S21_MATRIXPLUS_TESTS_TEST_CORE_H_
#define SRC_S21_MATRIXPLUS_TESTS_TEST_CORE_H_

#include <gtest/gtest.h>
#include "../logic/s21_matrix_oop.h"

bool EqMatrix(S21Matrix& matrix, double **test_matrix, int rows, int cols);
void InitS21Matrix(S21Matrix& matrix, double *test, int rows, int cols);
double **InitTestMatrix(double *test, int rows, int cols);
void DeleteTestMatrix(double *test, double **test_matrix, int rows);

#endif  // SRC_S21_MATRIXPLUS_H_TESTS_TEST_CORE_H_