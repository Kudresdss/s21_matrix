#include "test_core.h"

TEST(CONSTRUCTORS, DEFAULT_CONSTRUCTOR) {
	S21Matrix matrix = S21Matrix();
	
	ASSERT_EQ(matrix.GetRows(), 1);
	ASSERT_EQ(matrix.GetCols(), 1);
	ASSERT_EQ(matrix(0, 0), 0);
}

TEST(CONSTRUCTORS, PARAMETERIZED_CONSTRUCTOR) {
	double *test = new double[4]
	{0, 0,
	 0, 0};
	
	double **test_matrix = InitTestMatrix(test, 2, 2);
	S21Matrix matrix = S21Matrix(2, 2);

	ASSERT_EQ(matrix.GetRows(), 2);
	ASSERT_EQ(matrix.GetCols(), 2);
	ASSERT_EQ(EqMatrix(matrix, test_matrix, 2, 2), true);
	
	DeleteTestMatrix(test, test_matrix, 2);
}

TEST(CONSTRUCTORS, COPY_CONSTRUCTOR) {
	double *test = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix = InitTestMatrix(test, 2, 2);
	S21Matrix matrix = S21Matrix(2, 2);
	InitS21Matrix(matrix, test, 2, 2);
	S21Matrix copy_matrix = S21Matrix(matrix);

	ASSERT_EQ(EqMatrix(matrix, test_matrix, 2, 2), true);
	ASSERT_EQ(EqMatrix(copy_matrix, test_matrix, 2, 2), true);

	DeleteTestMatrix(test, test_matrix, 2);
}

TEST(CONSTRUCTORS, MOVE_CONSTRUCTOR) {
	double *test = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix = InitTestMatrix(test, 2, 2);
	S21Matrix matrix = S21Matrix(2, 2);
	InitS21Matrix(matrix, test, 2, 2);
	S21Matrix copy_matrix = S21Matrix(std::move(matrix));

	ASSERT_EQ(EqMatrix(copy_matrix, test_matrix, 2, 2), true);
	ASSERT_THROW(matrix(0, 0), std::out_of_range);

	DeleteTestMatrix(test, test_matrix, 2);
}

TEST(DESTRUCTOR, STANDART_DESTRUCTOR) {
	double *test = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix = InitTestMatrix(test, 2, 2);
	S21Matrix matrix = S21Matrix(2, 2);
	InitS21Matrix(matrix, test, 2, 2);
	matrix.~S21Matrix();

	ASSERT_THROW(matrix(0, 0), std::out_of_range);
	ASSERT_EQ(matrix.GetRows(), 0);
	ASSERT_EQ(matrix.GetCols(), 0);

	DeleteTestMatrix(test, test_matrix, 2);
}

TEST(ACCESSORS_AND_MUTATORS, ACCESSORS) {
	S21Matrix matrix = S21Matrix(2, 2);

	ASSERT_EQ(matrix.GetRows(), 2);
	ASSERT_EQ(matrix.GetCols(), 2);
}

TEST(ACCESSORS_AND_MUTATORS, MUTATORS) {
	S21Matrix matrix = S21Matrix(2, 2);

	ASSERT_NO_THROW(matrix.SetRows(3));
	ASSERT_NO_THROW(matrix.SetCols(3));
	ASSERT_EQ(matrix(1, 2), 0);
	ASSERT_EQ(matrix(2, 1), 0);
}
