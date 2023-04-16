#include "test_core.h"

TEST(OPERATOR_OVERLOADS, ASSIGNMENT_BY_INDEXATION) {
	S21Matrix matrix = S21Matrix(2, 2);
	double *test1 = new double[4]
	{2, 2,
	 2, 2};
	
	double **test_matrix = InitTestMatrix(test1, 2, 2);
	InitS21Matrix(matrix, test1, 2, 2);

	ASSERT_EQ(EqMatrix(matrix, test_matrix, 2, 2), true);

	DeleteTestMatrix(test1, test_matrix, 2);
}
