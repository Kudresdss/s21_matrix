#include "test_core.h"

bool EqMatrix(S21Matrix& matrix, double **test_matrix, int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (test_matrix[i][j] != matrix(i, j))
				return (false);
		}
	}
	return (true);
}

void InitS21Matrix(S21Matrix& matrix, double *test, int rows, int cols) {
	for (int i = 0, k = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j, ++k)
			matrix(i, j) = test[k];
	}
}

double **InitTestMatrix(double *test, int rows, int cols) {
	double **test_matrix = new double*[rows]();
	for (int i = 0, k = 0; i < cols; ++i) {
		test_matrix[i] = new double[cols]();
		for (int j = 0; j < cols; ++j, ++k)
			test_matrix[i][j] = test[k];
	}
	return (test_matrix);
}

void DeleteTestMatrix(double *test, double **test_matrix, int rows) {
	for (int i = 0; i < rows; ++i)
		delete[] test_matrix[i];
	delete[] test_matrix;
	delete[] test;
}
