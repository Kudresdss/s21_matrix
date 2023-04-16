#include "s21_matrix_oop.h"

// написать приближение до 7го знака?
bool S21Matrix::EqMatrix(const S21Matrix& other) {
	if (rows_ != other.rows_ || cols_ != other.cols_)
		return (false);
	
	for (int i = 0; i < rows_; ++i) {
		if (std::memcmp(matrix_[i], other.matrix_[i], cols_ * sizeof(double)))
			return (false);
	}
	return (true);
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
	if (rows_ != other.rows_ || cols_ != other.cols_)
		throw std::out_of_range("Different matrix dimensions");
	
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j)
			matrix_[i][j] += other.matrix_[i][j];
	}
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
	if (rows_ != other.rows_ || cols_ != other.cols_)
		throw std::out_of_range("Different matrix dimensions");
	
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j)
			matrix_[i][j] -= other.matrix_[i][j];
	}
}

void S21Matrix::MulNumber(const double num) {
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j)
			matrix_[i][j] *= num;
	}
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
	if (cols_ != other.rows_)
		throw std::out_of_range("Matrix dimensions are not compatible for multiplication");
	
	S21Matrix res(rows_, other.cols_);
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < other.cols_; ++j)
			for (int k = 0; k < cols_; ++k)
				res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
	}
	*this = res;
}

S21Matrix S21Matrix::Transpose() {

	S21Matrix res(cols_, rows_);
	for (int i = 0; i < res.rows_; ++i)
		for (int j = 0; j < res.cols_; ++j)
			res.matrix_[i][j] = matrix_[j][i];
	return (res);
}

S21Matrix S21Matrix::CalcComplements() {
	ValidateSquareMatrix();

	S21Matrix res(rows_, cols_);
	if (rows_ == 1)
		res.matrix_[0][0] = matrix_[0][0];
	else {

		S21Matrix minor(rows_ - 1, cols_ - 1);
		for (int i = 0; i < rows_; ++i) {
			for (int j = 0; j < cols_; ++j) {
				minor.CalcSubMatrix(i, j, *this);
				res.matrix_[i][j] = minor.Determinant() * pow(-1, i + j); 
			}
		}
	}
	return (res);
}

void S21Matrix::CalcSubMatrix(int row, int col, const S21Matrix& minor) {
	for (int min_x = 0, i = 0; i < minor.rows_; ++i) {
		if (i == row) continue;
		for (int min_y = 0, j = 0; j < minor.cols_; ++j) {
			if (j == col) continue;
			matrix_[min_x][min_y] = minor.matrix_[i][j];
			++min_y;
		}
		++min_x;
	}
}

double S21Matrix::Determinant() {
	ValidateSquareMatrix();

	double det;
	det = CalcDet();
	return (det);
}

double S21Matrix::CalcDet() {
	double det = 0;

	if (rows_ == 1)
			return (matrix_[0][0]);
		else if (rows_ == 2)
			return (matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1]);
		else {

			S21Matrix minor(rows_ - 1, cols_ - 1);
			for (int i = 0, sign = 1; i < rows_; ++i, sign *= -1) {
				minor.CalcSubMatrix(i, 0, *this);
				det += sign * matrix_[i][0] * minor.CalcDet();
			}
		}
	return (det);
}

S21Matrix S21Matrix::InverseMatrix() {
	ValidateInvertibleMatrix();

	double det = this->Determinant();
	double inverse_det = pow(det, -1);
	S21Matrix compliment = this->CalcComplements();
	S21Matrix trans_compliment = compliment.Transpose();
	S21Matrix inverse = trans_compliment * inverse_det;

	return (inverse);
}
