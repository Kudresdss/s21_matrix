#ifndef CPP1_S21_MATRIXPLUS_LOGIC_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_LOGIC_S21_MATRIX_OOP_H_

#include <cmath>
#include <cstring>
#include <new>
#include <stdexcept>

class S21Matrix {
 public:
  S21Matrix();                        // default constructor
  S21Matrix(int rows, int cols);      // parameterized constructor
  S21Matrix(const S21Matrix& other);  // copy costructor
  S21Matrix(S21Matrix&& other);       // move costructor
  ~S21Matrix();                       // destructor

  void SetRows(int rows);  // rows_ mutator
  int GetRows();           // rows_ accessor
  void SetCols(int cols);  // cols_ mutator
  int GetCols();           // cols_ accessor

  bool EqMatrix(const S21Matrix& other);   // check equality of matrices
  void SumMatrix(const S21Matrix& other);  // addiction of matrices
  void SubMatrix(const S21Matrix& other);  // subtraction of matrices
  void MulNumber(const double num);        // multiplication of
                                           // matrix by a number
  void MulMatrix(const S21Matrix& other);  // multiplication of
                                           // matrix by a matrix
  double Determinant();                    // find determinant of a matrix
  S21Matrix Transpose();                   // transpose the current matrix
  S21Matrix InverseMatrix();               // invert the current matrix
  S21Matrix CalcComplements();             // calculate matrix of algebraic
                                           // complement from current matrix

  S21Matrix operator+(const S21Matrix& other);  // operator overload for
                                                // expression: matrix + matrix
  S21Matrix operator-(const S21Matrix& other);  // operator overload for
                                                // expression: matrix - matrix
  S21Matrix operator*(const S21Matrix& other);  // operator overload for
                                                // expression: matrix * matrix
  friend S21Matrix operator*(
      const S21Matrix& matrix,
      const double num);  // operator overload for expression: matrix * num
  friend S21Matrix operator*(
      const double num,
      const S21Matrix&
          matrix);  // operator overload for expression: num * matrix
  bool operator==(const S21Matrix& other);  // operator overload for expression:
                                            // matrix == matrix
  S21Matrix& operator=(
      const S21Matrix&
          other);  // operator overload for expression: matrix = matrix (copy)
  S21Matrix& operator=(S21Matrix&& other);  // operator overload for expression:
                                            // matrix = matrix (move)
  S21Matrix& operator+=(
      const S21Matrix&
          other);  // operator overload for expression: matrix += matrix
  S21Matrix& operator-=(
      const S21Matrix&
          other);  // operator overload for expression: matrix -= matrix
  S21Matrix& operator*=(
      const S21Matrix&
          other);  // operator overload for expression: matrix *= matrix
  S21Matrix& operator*=(
      const double num);  // operator overload for expression: matrix *= num
  double& operator()(
      int row, int col);  // operator overload for expression: matrix(i, j)

 private:
  int rows_{}, cols_{};       // rows and columns of a matrix
  double** matrix_{nullptr};  // pointer to the current matrix

  void MatrixMemoryAllocation();  // method for matrix memory allocation
  void CopyMatrix(
      const S21Matrix& other);  // method for copying the contents from a given
                                // matrix to the current one

  void CalcSubMatrix(
      int i, int j,
      const S21Matrix& minor);  // method for calculating matrix of minors for a
                                // given element from current matrix
  double CalcDet();             // recursive method of calculating a determinant

  void ValidateMatrixDimensions();  // validation of same matrix dimensions
  void ValidateSquareMatrix();      // validation of square matrix
  void ValidateInvertibleMatrix(double det);  // validation of invertible matrix
  void ValidateIndexOutOfBounds(int row, int col);  // validation of indexes
};

#endif  // CPP1_S21_MATRIXPLUS_LOGIC_S21_MATRIX_OOP_H_
