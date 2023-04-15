#ifndef CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_

#include <iostream>
#include <cmath>

class S21Matrix {

public:
    S21Matrix();										// default constructor
    S21Matrix(int rows, int cols);						// parameterized constructor
    S21Matrix(const S21Matrix& other);					// copy cnstructor
    S21Matrix(S21Matrix&& other);						// move cnstructor
    ~S21Matrix();										// destructor

	void SetRows(int rows);
	int	GetRows();
	void SetCols(int cols);
	int GetCols();
	void MatrixMemoryAllocation();
	void CopyMatrix(const S21Matrix& other);
	void ValidateMatrixDimensions();
	void ValidateSquareMatrix();
	void ValidateInvertibleMatrix();

	bool EqMatrix(const S21Matrix& other);
	void SumMatrix(const S21Matrix& other);
	void SubMatrix(const S21Matrix& other);
	void MulNumber(const double num);
	void MulMatrix(const S21Matrix& other);
	double Determinant();
	S21Matrix Transpose();
	S21Matrix InverseMatrix();
	
	S21Matrix CalcComplements();
	void CalcSubMatrix(size_t i, size_t j, const S21Matrix& minor);
	double CalcDet();

    S21Matrix operator+(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other);
	S21Matrix operator*(const S21Matrix& other);
	friend S21Matrix operator*(const S21Matrix& matrix, const double num);
	friend S21Matrix operator*(const double num, const S21Matrix& matrix);
	bool operator==(const S21Matrix& other);
    S21Matrix& operator=(const S21Matrix& other);		// assignment operator overload
	S21Matrix& operator=(S21Matrix&& other);
    S21Matrix& operator+=(const S21Matrix& other);                           
    S21Matrix& operator-=(const S21Matrix& other);
	S21Matrix& operator*=(const S21Matrix& other);
    double operator()(int row, int col);				// index operator overload
	
private:
	int rows_, cols_;
	double **matrix_;

};


#endif  // CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_
