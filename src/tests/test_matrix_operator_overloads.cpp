#include "test_core.h"

TEST(INDEXATION_OPERATOR_OVERLOAD, CORRECT_INPUT_GET_VALUE_OF_ELEMENT_BY_INDEXATION) {
	double *test1 = new double[4]
	{2, 2,
	 2, 2};
	
	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 2, 2);

	ASSERT_EQ(matrix1(0, 0), 2);

	DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(INDEXATION_OPERATOR_OVERLOAD, CORRECT_INPUT_ASSIGNMENT_OF_VALUE_BY_INDEXATION) {
	double *test1 = new double[4]
	{2, 2,
	 2, 2};
	
	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 2, 2);

	ASSERT_EQ(EqMatrix(matrix1, test_matrix1, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(INDEXATION_OPERATOR_OVERLOAD, INCORRECT_INPUT_INDEXED_ELEMENT_IS_OUT_OF_BOUNDS) {
	double *test1 = new double[4]
	{2, 2,
	 2, 2};
	
	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 2, 2);

	ASSERT_THROW(matrix1(3, 3), std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(ASSIGNMENT_BY_COPY_OPERATOR_OVERLOAD, CORRECT_INPUT) {
	double *test1 = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 2, 2);
	
	S21Matrix copy_matrix1 = matrix1;
	ASSERT_EQ(EqMatrix(matrix1, test_matrix1, 2, 2), true);
	ASSERT_EQ(EqMatrix(copy_matrix1, test_matrix1, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(ASSIGNMENT_BY_MOVE_OPERATOR_OVERLOAD, CORRECT_INPUT) {
	double *test1 = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	InitS21Matrix(matrix1, test_matrix1, 2, 2);

	S21Matrix copy_matrix1 = std::move(matrix1);
	ASSERT_EQ(EqMatrix(copy_matrix1, test_matrix1, 2, 2), true);
	ASSERT_THROW(matrix1(0, 0), std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(EQUALITY_OPERATOR_OVERLOAD, CORRECT_INPUT) {
	double *test1 = new double[4]
	{2, 2,
	 2, 2};

	double **test_matrix1 = InitTestMatrix(test1, 2, 2);
	S21Matrix matrix1 = S21Matrix(2, 2);
	S21Matrix matrix2 = S21Matrix(2, 2);
 	InitS21Matrix(matrix1, test_matrix1, 2, 2);
	InitS21Matrix(matrix2, test_matrix1, 2, 2);

	ASSERT_EQ(matrix1 == matrix2, true);

	DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(ADDICTION_OPERATOR_OVERLOAD, CORRECT_INPUT) {
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

	matrix1 = matrix1 + matrix2;
	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(test2, test_matrix2, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(ADDICTION_OPERATOR_OVERLOAD, INCORRECT_INPUT_DIFFERENT_MATRIX_DIMENSIONS) {
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

	ASSERT_THROW(matrix1 + matrix2, std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(test2, test_matrix2, 2);
}

TEST(ADDICTION_ASSIGNMENT_OPERATOR_OVERLOAD, CORRECT_INPUT) {
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

	matrix1 += matrix2;
	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(test2, test_matrix2, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(ADDICTION_ASSIGNMENT_OPERATOR_OVERLOAD, INCORRECT_INPUT_DIFFERENT_MATRIX_DIMENSIONS) {
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

	ASSERT_THROW(matrix1 += matrix2, std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(test2, test_matrix2, 2);
}

TEST(SUBTRACTION_OPERATOR_OVERLOAD, CORRECT_INPUT) {
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

	matrix1 = matrix1 - matrix2;
	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(test2, test_matrix2, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(SUBTRACTION_OPERATOR_OVERLOAD, INCORRECT_INPUT_DIFFERENT_MATRIX_DIMENSIONS) {
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

	ASSERT_THROW(matrix1 - matrix2, std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(test2, test_matrix2, 2);
}

TEST(SUBTRACTION_ASSIGNMENT_OPERATOR_OVERLOAD, CORRECT_INPUT) {
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

	matrix1 -= matrix2;
	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(test2, test_matrix2, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(SUBTRACTION_ASSIGNMENT_OPERATOR_OVERLOAD, INCORRECT_INPUT_DIFFERENT_MATRIX_DIMENSIONS) {
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

	ASSERT_THROW(matrix1 -= matrix2, std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(test2, test_matrix2, 2);
}

TEST(MULTIPLICATION_BY_NUMBER_ON_THE_RIGHT_OPERATOR_OVERLOAD, CORRECT_INPUT) {
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

	matrix1 = matrix1 * 4;

	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(MULTIPLICATION_BY_NUMBER_ON_THE_LEFT_OPERATOR_OVERLOAD, CORRECT_INPUT) {
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

	matrix1 = 4 * matrix1;

	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(ASSIGNMENT_BY_MULTIPLICATION_BY_NUMBER_OPERATOR_OVERLOAD, CORRECT_INPUT) {
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

	matrix1 *= 4;

	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(MULTIPLICATION_BY_MATRIX_OPERATOR_OVERLOAD, CORRECT_INPUT) {
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

	matrix1 = matrix1 * matrix2;
	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(test2, test_matrix2, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(MULTIPLICATION_BY_MATRIX_OPERATOR_OVERLOAD, INCORRECT_INPUT_NOT_VALID_MATRIX_DIMENSIONS_FOR_MULTIPLICATION) {
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

	ASSERT_THROW(matrix1 * matrix2, std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(test2, test_matrix2, 2);
}

TEST(ASSIGNMENT_BY_MULTIPLICATION_BY_MATRIX, CORRECT_INPUT) {
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

	matrix1 *= matrix2;
	ASSERT_EQ(EqMatrix(matrix1, test_result, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix1, 2);
	DeleteTestMatrix(test2, test_matrix2, 2);
	DeleteTestMatrix(result, test_result, 2);
}

TEST(ASSIGNMENT_BY_MULTIPLICATION_BY_MATRIX, INCORRECT_INPUT_NOT_VALID_MATRIX_DIMENSIONS_FOR_MULTIPLICATION) {
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

	ASSERT_THROW(matrix1 *= matrix2, std::out_of_range);

	DeleteTestMatrix(test1, test_matrix1, 1);
	DeleteTestMatrix(test2, test_matrix2, 2);
}
