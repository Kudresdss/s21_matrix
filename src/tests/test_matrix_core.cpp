#include "test_core.h"

TEST(CONSTRUCTORS, DEFAULT_CONSTRUCTOR) {
  S21Matrix matrix1 = S21Matrix();

  ASSERT_EQ(matrix1.GetRows(), 1);
  ASSERT_EQ(matrix1.GetCols(), 1);
  ASSERT_EQ(matrix1(0, 0), 0);
}

TEST(CONSTRUCTORS, PARAMETERIZED_CONSTRUCTOR) {
  double *test1 = new double[4]{0, 0, 0, 0};

  double **test_matrix1 = InitTestMatrix(test1, 2, 2);
  S21Matrix matrix1 = S21Matrix(2, 2);

  ASSERT_EQ(matrix1.GetRows(), 2);
  ASSERT_EQ(matrix1.GetCols(), 2);
  ASSERT_EQ(EqMatrix(matrix1, test_matrix1, 2, 2), true);

  DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(CONSTRUCTORS, COPY_CONSTRUCTOR) {
  double *test1 = new double[4]{2, 2, 2, 2};

  double **test_matrix1 = InitTestMatrix(test1, 2, 2);
  S21Matrix matrix1 = S21Matrix(2, 2);
  InitS21Matrix(matrix1, test_matrix1, 2, 2);

  S21Matrix copy_matrix1 = S21Matrix(matrix1);
  ASSERT_EQ(EqMatrix(matrix1, test_matrix1, 2, 2), true);
  ASSERT_EQ(EqMatrix(copy_matrix1, test_matrix1, 2, 2), true);

  DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(CONSTRUCTORS, MOVE_CONSTRUCTOR) {
  double *test1 = new double[4]{2, 2, 2, 2};

  double **test_matrix1 = InitTestMatrix(test1, 2, 2);
  S21Matrix matrix1 = S21Matrix(2, 2);
  InitS21Matrix(matrix1, test_matrix1, 2, 2);

  S21Matrix copy_matrix1 = S21Matrix(std::move(matrix1));
  ASSERT_EQ(EqMatrix(copy_matrix1, test_matrix1, 2, 2), true);
  ASSERT_THROW(matrix1(0, 0), std::out_of_range);

  DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(CONSTRUCTORS, INVALID_MATRIX_SIZE) {
  ASSERT_THROW(S21Matrix(0, 0), std::out_of_range);
}

TEST(DESTRUCTOR, STANDART_DESTRUCTOR) {
  double *test1 = new double[4]{2, 2, 2, 2};

  double **test_matrix1 = InitTestMatrix(test1, 2, 2);
  S21Matrix matrix1 = S21Matrix(2, 2);
  InitS21Matrix(matrix1, test_matrix1, 2, 2);

  matrix1.~S21Matrix();
  ASSERT_THROW(matrix1(0, 0), std::out_of_range);
  ASSERT_EQ(matrix1.GetRows(), 0);
  ASSERT_EQ(matrix1.GetCols(), 0);

  DeleteTestMatrix(test1, test_matrix1, 2);
}

TEST(ACCESSORS_AND_MUTATORS, ACCESSORS) {
  S21Matrix matrix1 = S21Matrix(2, 2);

  ASSERT_EQ(matrix1.GetRows(), 2);
  ASSERT_EQ(matrix1.GetCols(), 2);
}

TEST(ACCESSORS_AND_MUTATORS, MUTATORS_TO_BIGGER_SIZE) {
  S21Matrix matrix1 = S21Matrix(2, 2);

  ASSERT_NO_THROW(matrix1.SetRows(3));
  ASSERT_NO_THROW(matrix1.SetCols(3));
  ASSERT_EQ(matrix1(1, 2), 0);
  ASSERT_EQ(matrix1(2, 1), 0);
}

TEST(ACCESSORS_AND_MUTATORS, MUTATORS_TO_SMALLER_SIZE) {
  S21Matrix matrix1 = S21Matrix(2, 2);

  ASSERT_NO_THROW(matrix1.SetRows(1));
  ASSERT_NO_THROW(matrix1.SetCols(1));
}
