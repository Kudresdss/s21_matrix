#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() { *this = S21Matrix(1, 1); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  MatrixMemoryAllocation();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  MatrixMemoryAllocation();
  for (int i = 0; i < rows_; ++i) {
    std::memcpy(matrix_[i], other.matrix_[i], cols_ * sizeof(double));
  }
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

void S21Matrix::MatrixMemoryAllocation() {
  ValidateMatrixDimensions();

  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  for (int i = 0; i < other.rows_ && i < rows_; ++i) {
    if (other.cols_ < cols_) {
      std::memcpy(matrix_[i], other.matrix_[i], other.cols_ * sizeof(double));
    } else
      std::memcpy(matrix_[i], other.matrix_[i], cols_ * sizeof(double));
  }
}

void S21Matrix::SetRows(int rows) {
  if (rows >= 1 && rows_ != rows) {
    S21Matrix res(rows, cols_);
    res.CopyMatrix(*this);
    *this = res;
  }
}

int S21Matrix::GetRows() { return (rows_); }

void S21Matrix::SetCols(int cols) {
  if (cols >= 1 && cols_ != cols) {
    S21Matrix res(rows_, cols);
    res.CopyMatrix(*this);
    *this = res;
  }
}

int S21Matrix::GetCols() { return (cols_); }

void S21Matrix::ValidateMatrixDimensions() {
  if (cols_ < 1 || rows_ < 1) throw std::out_of_range("Invalid matrix size");
}

void S21Matrix::ValidateSquareMatrix() {
  if (rows_ != cols_) throw std::out_of_range("Matrix is not square");
}

void S21Matrix::ValidateInvertibleMatrix(double det) {
  if (det == 0) throw std::invalid_argument("Matrix is not invertible");
}

void S21Matrix::ValidateIndexOutOfBounds(int row, int col) {
  if (row >= rows_ || col >= cols_)
    throw std::out_of_range("Incorrect input, index is out of range");
}
