#include "test_core.h"

TEST(EQ_MATRIX, TRUE_ARE_EQUAL) {
	double *test1 = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	S21Matrix matrix2 = S21Matrix(2, 2);
 	InitS21Matrix(matrix1, test_matrix1, 2, 2);
	InitS21Matrix(matrix2, test_matrix1, 2, 2);

	ASSERT_EQ(matrix1.EqMatrix(matrix2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(EQ_MATRIX, FALSE_DIFFERENT_MATRIX_DIMENSIONS) {
	double *test1 = new double[1]
	{1};
	
	double *test2 = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix1 = InitTestMatrix(test1, 1, 1);
	double **test_matrix2 = InitTestMatrix(test2, 2, 2);
	S21Matrix matrix1 = S21Matrix(1, 1);
	S21Matrix matrix2 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 1, 1);
	InitS21Matrix(matrix2, test_matrix2, 2, 2);

	ASSERT_EQ(matrix1.EqMatrix(matrix2), false);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(test2, test_matrix2, 2);
}

TEST(EQ_MATRIX, FALSE_NOT_EQUAL_VALUES) {
	double *test1 = new double[4]
	{1, 2,
	 2, 2};

	double *test2 = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	double **test_matrix2 = InitTestMatrix(test2, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	S21Matrix matrix2 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 2, 2);
	InitS21Matrix(matrix2, test_matrix2, 2, 2);

	ASSERT_EQ(matrix1.EqMatrix(matrix2), false);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(test2, test_matrix2, 2);
}

TEST(SUM_MATRIX, CORRECT_INPUT) {
	double *test1 = new double[4]
	{1, 2,
	 2, 2};
	
	double *test2 = new double[4]
	{2, 2,
	 2, 2};

	double *result = new double[4]
	{3, 4,
	 4, 4};

	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	double **test_matrix2 = InitTestMatrix(test2, 2, 2);
	double **test_result = InitTestMatrix(result, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	S21Matrix matrix2 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 2, 2);
	InitS21Matrix(matrix2, test_matrix2, 2, 2);

	matrix1.SumMatrix(matrix2);
	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(test2, test_matrix2, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(SUM_MATRIX, INCORRECT_INPUT_DIFFERENT_MATRIX_DIMENSIONS) {
	double *test1 = new double[1]
	{1};
	
	double *test2 = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix1 = InitTestMatrix(test1, 1, 1);
	double **test_matrix2 = InitTestMatrix(test2, 2, 2);
	S21Matrix matrix1 = S21Matrix(1, 1);
	S21Matrix matrix2 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 1, 1);
	InitS21Matrix(matrix2, test_matrix2, 2, 2);

	ASSERT_THROW(matrix1.SumMatrix(matrix2), std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(test2, test_matrix2, 2);
}

TEST(SUB_MATRIX, CORRECT_INPUT) {
	double *test1 = new double[4]
	{3, 4,
	 4, 4};
	
	double *test2 = new double[4]
	{2, 2,
	 2, 2};

	double *result = new double[4]
	{1, 2,
	 2, 2};

	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	double **test_matrix2 = InitTestMatrix(test2, 2, 2);
	double **test_result = InitTestMatrix(result, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	S21Matrix matrix2 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 2, 2);
	InitS21Matrix(matrix2, test_matrix2, 2, 2);

	matrix1.SubMatrix(matrix2);
	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(test2, test_matrix2, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(SUB_MATRIX, INCORRECT_INPUT_DIFFERENT_MATRIX_DIMENSIONS) {
	double *test1 = new double[1]
	{1};
	
	double *test2 = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix1 = InitTestMatrix(test1, 1, 1);
	double **test_matrix2 = InitTestMatrix(test2, 2, 2);
	S21Matrix matrix1 = S21Matrix(1, 1);
	S21Matrix matrix2 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 1, 1);
	InitS21Matrix(matrix2, test_matrix2, 2, 2);

	ASSERT_THROW(matrix1.SubMatrix(matrix2), std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(test2, test_matrix2, 2);
}

TEST(MUL_NUMBER, CORRECT_MULTIPLICATION_BY_NUMBER) {
	double *test1 = new double[4]
	{2, 2,
	 2, 2};

	double *result = new double[4]
	{8, 8,
	 8, 8};

	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	double **test_result = InitTestMatrix(result, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 2, 2);

	matrix1.MulNumber(4);

	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(MUL_MATRIX, CORRECT_INPUT_SAME_DIMENSIONS) {
	double *test1 = new double[4]
	{2, 2,
	 2, 2};
	
	double *test2 = new double[4]
	{1, 4,
	 4, 4};

	double *result = new double[4]
	{10, 16,
	 10, 16};

	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	double **test_matrix2 = InitTestMatrix(test2, 2, 2);
	double **test_result = InitTestMatrix(result, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	S21Matrix matrix2 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 2, 2);
	InitS21Matrix(matrix2, test_matrix2, 2, 2);

	matrix1.MulMatrix(matrix2);
	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(test2, test_matrix2, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(MUL_MATRIX, CORRECT_INPUT_DIFFERENT_DIMENSIONS) {
	double *test1 = new double[9]
	{1, 2, 3,
	 1, 2, 3,
	 1, 2, 3};

	double *test2 = new double[15]
	{1, 2, 3, 4, 5, 
	 1, 2, 3, 4, 5,
	 1, 2, 3, 4, 5};

	double *result = new double[15]
	{6, 12, 18, 24, 30, 
	 6, 12, 18, 24, 30,
	 6, 12, 18, 24, 30};

	double **test_matrix1 = InitTestMatrix(test1, 3, 3);
	double **test_matrix2 = InitTestMatrix(test2, 3, 5);
	double **test_result = InitTestMatrix(result, 3, 5);
	S21Matrix matrix1 = S21Matrix(3, 3);
	S21Matrix matrix2 = S21Matrix(3, 5);
	InitS21Matrix(matrix1, test_matrix1, 3, 3);
	InitS21Matrix(matrix2, test_matrix2, 3, 5);

	ASSERT_NO_THROW(matrix1.MulMatrix(matrix2));
	ASSERT_EQ(EqMatrix(matrix1, test_result, 3, 5), true);

	DeleteTestMatrix(test1, test_matrix1, 3);
	DeleteTestMatrix(test2, test_matrix2, 3);
	DeleteTestMatrix(result, test_result, 3);
}

TEST(MUL_MATRIX, INCORRECT_INPUT_NOT_VALID_MATRIX_DIMENSIONS_FOR_MULTIPLICATION) {
	double *test1 = new double[1]
	{1};
	
	double *test2 = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix1 = InitTestMatrix(test1, 1, 1);
	double **test_matrix2 = InitTestMatrix(test2, 2, 2);
	S21Matrix matrix1 = S21Matrix(1, 1);
	S21Matrix matrix2 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 1, 1);
	InitS21Matrix(matrix2, test_matrix2, 2, 2);

	ASSERT_THROW(matrix1.MulMatrix(matrix2), std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(test2, test_matrix2, 2);
}

TEST(TRANSPOSE, CORRECT_TRANSPOSE_SQUARE) {
	double *test1 = new double[9]
	{1, 2, 3,
	 3, 2, 1,
	 1, 2, 3};

	double *result = new double[9]
	{1, 3, 1,
	 2, 2, 2,
	 3, 1, 3};

	double **test_matrix1 = InitTestMatrix(test1, 3, 3);
	double **test_result = InitTestMatrix(result, 3, 3);
	S21Matrix matrix1 = S21Matrix(3, 3);
	InitS21Matrix(matrix1, test_matrix1, 3, 3);

	matrix1 = matrix1.Transpose();
	ASSERT_EQ(EqMatrix(matrix1, test_result, 3, 3), true);

	DeleteTestMatrix(test1, test_matrix1, 3);
	DeleteTestMatrix(result, test_result, 3);
}

TEST(TRANSPOSE, CORRECT_TRANSPOSE_NOT_SQUARE) {
	double *test1 = new double[21]
	{1, 2, 3, 4, 5, 6, 7,
	 1, 2, 3, 4, 5, 6, 7,
	 1, 2, 3, 4, 5, 6, 7};

	double *result = new double[21]
	{1, 1, 1,
	 2, 2, 2,
	 3, 3, 3,
	 4, 4, 4,
	 5, 5, 5,
	 6, 6, 6,
	 7, 7, 7};

	double **test_matrix1 = InitTestMatrix(test1, 3, 7);
	double **test_result = InitTestMatrix(result, 7, 3);
	S21Matrix matrix1 = S21Matrix(3, 7);
	InitS21Matrix(matrix1, test_matrix1, 3, 7);

	matrix1 = matrix1.Transpose();
	ASSERT_EQ(EqMatrix(matrix1, test_result, 7, 3), true);

	DeleteTestMatrix(test1, test_matrix1, 3);
	DeleteTestMatrix(result, test_result, 7);
}

TEST(DETERMINANT, CORRECT_INPUT) {
	double *test1 = new double[9]
	{1, 1, -1,
	 1, -1, 1,
	 -1, 1, 1};

	double **test_matrix1 = InitTestMatrix(test1, 3, 3);
	S21Matrix matrix1 = S21Matrix(3, 3);
	InitS21Matrix(matrix1, test_matrix1, 3, 3);
	
	ASSERT_EQ(matrix1.Determinant(), -4);
	
	DeleteTestMatrix(test1, test_matrix1, 3);
}

TEST(DETERMINANT, CORRECT_INPUT_ONE_ELEMENT_MATRIX) {
	double *test1 = new double[1]
	{9};

	double **test_matrix1 = InitTestMatrix(test1, 1, 1);
	S21Matrix matrix1 = S21Matrix(1, 1);
	InitS21Matrix(matrix1, test_matrix1, 1, 1);
	
	ASSERT_EQ(matrix1.Determinant(), 9);
	
	DeleteTestMatrix(test1, test_matrix1, 1);
}

TEST(DETERMINANT, INCORRECT_INPUT_MATRIX_IS_NOT_SQUARE) {
	double *test1 = new double[6]
	{1, 1, -1,
	 1, -1, 1};
	
	double **test_matrix1 = InitTestMatrix(test1, 2, 3);
	S21Matrix matrix1 = S21Matrix(2, 3);
	InitS21Matrix(matrix1, test_matrix1, 2, 3);

	ASSERT_THROW(matrix1.Determinant(), std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(CALC_COMPLEMENTS, CORRECT_INPUT) {
	double *test1 = new double[9]
	{1, 1, -1,
	 1, -1, 1,
	 -1, 1, 1};

	double *result = new double[9]
	{-2, -2, 0,
	 -2, 0, -2,
	 0, -2, -2};

	double **test_matrix1 = InitTestMatrix(test1, 3, 3);
	double **test_result = InitTestMatrix(result, 3, 3);
	S21Matrix matrix1 = S21Matrix(3, 3);
	InitS21Matrix(matrix1, test_matrix1, 3, 3);

	matrix1 = matrix1.CalcComplements();
	ASSERT_EQ(EqMatrix(matrix1, test_result, 3, 3), true);

	DeleteTestMatrix(test1, test_matrix1, 3);
	DeleteTestMatrix(result, test_result, 3);
}

TEST(CALC_COMPLEMENTS, CORRECT_INPUT_ONE_ELEMENT_MATRIX) {
	double *test1 = new double[1]
	{9};

	double *result = new double[1]
	{9};

	double **test_matrix1 = InitTestMatrix(test1, 1, 1);
	double **test_result = InitTestMatrix(result, 1, 1);
	S21Matrix matrix1 = S21Matrix(1, 1);
	InitS21Matrix(matrix1, test_matrix1, 1, 1);

	matrix1 = matrix1.CalcComplements();
	ASSERT_EQ(EqMatrix(matrix1, test_result, 1, 1), true);
	ASSERT_EQ(matrix1(0, 0), 9);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(result, test_result, 1);
}

TEST(CALC_COMPLEMENTS, INCORRECT_INPUT_MATRIX_IS_NOT_SQUARE) {
	double *test1 = new double[6]
	{1, 1, -1,
	 1, -1, 1};
	
	double **test_matrix1 = InitTestMatrix(test1, 2, 3);
	S21Matrix matrix1 = S21Matrix(2, 3);
	InitS21Matrix(matrix1, test_matrix1, 2, 3);

	ASSERT_THROW(matrix1.CalcComplements(), std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(INVERSE_MATRIX, CORRECT_INPUT) {
	double *test1 = new double[9]
	{1, 1, -1,
	 1, -1, 1,
	 -1, 1, 1};

	double *result = new double[9]
	{0.5, 0.5, 0,
	 0.5, 0, 0.5,
	 0, 0.5, 0.5};

	double **test_matrix1 = InitTestMatrix(test1, 3, 3);
	double **test_result = InitTestMatrix(result, 3, 3);
	S21Matrix matrix1 = S21Matrix(3, 3);
	InitS21Matrix(matrix1, test_matrix1, 3, 3);

	matrix1 = matrix1.InverseMatrix();
	ASSERT_EQ(EqMatrix(matrix1, test_result, 3, 3), true);

	DeleteTestMatrix(test1, test_matrix1, 3);
	DeleteTestMatrix(result, test_result, 3);
}

TEST(INVERSE_MATRIX, INCORRECT_INPUT_DETERMINANT_IS_EQUAL_TO_ZERO) {
	double *test1 = new double[9]
	{1, 2, 3,
	 3, 2, 1,
	 1, 2, 3};

	double **test_matrix1 = InitTestMatrix(test1, 3, 3);
	S21Matrix matrix1 = S21Matrix(3, 3);
	InitS21Matrix(matrix1, test_matrix1, 3, 3);

	ASSERT_THROW(matrix1.InverseMatrix(), std::invalid_argument);

	DeleteTestMatrix(test1, test_matrix1, 3);
}
