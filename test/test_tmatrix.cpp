#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> a(5);
	TMatrix<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> a(5);
	TMatrix<int> b(a);
	EXPECT_NE(&a, &b);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> a(5);
	int b = a.GetSize();
	EXPECT_EQ(5, b);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> a(3);
	EXPECT_NO_THROW(a[2][2] = 2);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> a(3);
	EXPECT_ANY_THROW(a[-2][-2] = 2);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> a(3);
	EXPECT_ANY_THROW(a[MAX_MATRIX_SIZE + 10][MAX_MATRIX_SIZE + 10]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> a(3); 
	EXPECT_NO_THROW(a = a);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> a(3);
	TMatrix<int> b(3);
	b[2][2] = 5;
	EXPECT_NO_THROW(a = b);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> a(3);
	TMatrix<int> b(5);
	a = b;
	EXPECT_EQ(5, a.GetSize());

}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> a(3);
	TMatrix<int> b(5);
	b[2][2] = 5;
	EXPECT_NO_THROW(a = b);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> a(3);
	TMatrix<int> b(3);
	a[2][2] = 5;
	b[2][2] = 5;
	EXPECT_TRUE(a == b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> a(3);
	a[2][2] = 5;
	EXPECT_TRUE(a == a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> a(3);
	TMatrix<int> b(5);
	a[2][2] = 5;
	b[2][2] = 5;
	EXPECT_FALSE(a == b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> a(2);
	TMatrix<int> b(2);
	TMatrix<int> c(2);
	for (size_t i = 0; i < 2; i++) {
		a[i][i] = 3;
		b[i][i] = 2;
		c[i][i] = 5;
	}
	EXPECT_EQ(c, a + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> a(2);
	TMatrix<int> b(5);
	EXPECT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> a(2);
	TMatrix<int> b(2);
	TMatrix<int> c(2);
	for (size_t i = 0; i < 2; i++) {
		a[i][i] = 3;
		b[i][i] = 2;
		c[i][i] = 5;
	}
	EXPECT_EQ(a, c - b);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> a(2);
	TMatrix<int> b(5);
	EXPECT_ANY_THROW(a - b);
}

