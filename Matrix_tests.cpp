#include "Matrix.hpp"
#include "Matrix_test_helpers.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix mat;
  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(&mat, 3, 5);
  Matrix_fill(&mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(&mat, r, c), value);
    }
  }
}

TEST(test_initialize) {
  Matrix mat;
  const int width = 1;
  const int height = 5;
  Matrix_init(&mat, 1, 5);
  for (int i = 0; i<width; i++){
    for (int j = 0; j<height ; ++j){
      ASSERT_EQUAL(*Matrix_at(&mat,i,j), 0);
    }
  }
}

TEST(test_initialize_2) {
  Matrix mat;
  const int width = 1;
  const int height = 5;
  Matrix_init(&mat, 1, 5);
  for (int i = 0; i<width; i++){
    for (int j = 0; j<height ; ++j){
      ASSERT_EQUAL(*Matrix_at(&mat,i,j), 0);
    }
  }
}

TEST(test_printing) {
  Matrix mat;
  const int width = 1;
  const int height = 5;
  Matrix_init(&mat, width, height);
  ostringstream os;
  Matrix_print(&mat, os);
  string expected = 
  "0\n"
  "0\n"
  "0\n"
  "0\n"
  "0\n";
  ASSERT_EQUAL(os.str(),expected);
}

TEST(test_width1) {
  Matrix mat;
  const int width = 10000;
  const int height = 5;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_width(&mat), 10000);
}

TEST(test_width2) {
  Matrix mat;
  const int width = 5;
  const int height = 5;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_width(&mat), 5);
}

TEST(test_height1) {
  Matrix mat;
  const int width = 5;
  const int height = 5;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_height(&mat), 5);
}

TEST(test_height2) {
  Matrix mat;
  const int width = 5;
  const int height = 1000;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_height(&mat), 1000);
}

TEST(test_at1) {
  Matrix mat;
  const int width = 1;
  const int height = 1;
  Matrix_init(&mat, width, height);
  Matrix_fill(&mat, 1);
  ASSERT_EQUAL(*Matrix_at(&mat,0,0), 1);
}

TEST(test_at2) {
  Matrix mat;
  const int width = 3;
  const int height = 3;
  Matrix_init(&mat, width, height);
  Matrix_fill_border(&mat, 1);
  ASSERT_EQUAL(*Matrix_at(&mat,1,1), 0);
}

TEST(test_fill2) {
  Matrix mat;
  const int width = 5;
  const int height = 3;
  Matrix_init(&mat, width, height);
  Matrix_fill(&mat, 9);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(&mat, r, c), 9);
    }
  }
}

TEST(test_fill_border_1) {
  Matrix mat;
  const int width = 4;
  const int height = 3;
  Matrix_init(&mat, width, height);
  Matrix_fill_border(&mat, 9);

  for(int r = 0; r < height; ++r){
    ASSERT_EQUAL(*Matrix_at(&mat, width, r), 9);
    ASSERT_EQUAL(*Matrix_at(&mat, 0, r), 9);
  }
  for(int c = 0; c < width; ++c){
    ASSERT_EQUAL(*Matrix_at(&mat, c, 0), 9);
    ASSERT_EQUAL(*Matrix_at(&mat, c, height), 9);
  }
}

TEST(test_fill_border_2) {
  Matrix mat;
  const int width = 1;
  const int height = 2;
  Matrix_init(&mat, width, height);
  Matrix_fill_border(&mat, 1);

  for(int r = 0; r < height; ++r){
    ASSERT_EQUAL(*Matrix_at(&mat, width, r), 1);
    ASSERT_EQUAL(*Matrix_at(&mat, 0, r), 1);
  }
  for(int c = 0; c < width; ++c){
    ASSERT_EQUAL(*Matrix_at(&mat, c, 0), 1);
    ASSERT_EQUAL(*Matrix_at(&mat, c, height), 1);
  }
}

TEST(test_fill_border_3) {
  Matrix mat;
  const int width = 2;
  const int height = 1;
  Matrix_init(&mat, width, height);
  Matrix_fill_border(&mat, 1);

  for(int r = 0; r < height; ++r){
    ASSERT_EQUAL(*Matrix_at(&mat, width, r), 1);
    ASSERT_EQUAL(*Matrix_at(&mat, 0, r), 1);
  }
  for(int c = 0; c < width; ++c){
    ASSERT_EQUAL(*Matrix_at(&mat, c, 0), 1);
    ASSERT_EQUAL(*Matrix_at(&mat, c, height), 1);
  }
}

TEST(test_max_1) {
  Matrix mat;
  const int width = 1;
  const int height = 2;
  Matrix_init(&mat, width, height);
  Matrix_fill_border(&mat, 1);
  *Matrix_at(&mat,1,1) = 11;
  ASSERT_EQUAL(Matrix_max(&mat), 11);
}

TEST(test_max_2) {
  Matrix mat;
  const int width = 2;
  const int height = 10;
  Matrix_init(&mat, width, height);
  Matrix_fill_border(&mat, 1);
  *Matrix_at(&mat,2,10) = 12;
  ASSERT_EQUAL(Matrix_max(&mat), 12);
}

TEST(test_Matrix_column_of_min_value_in_row_1) {
  Matrix mat;
  const int width = 3;
  const int height = 3;
  Matrix_init(&mat, width, height);
  Matrix_fill_border(&mat, 1);
  *Matrix_at(&mat,2,1) = 12;
  *Matrix_at(&mat,2,2) = 12;
  
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(&mat,2,0,2), 1);
}

TEST(test_Matrix_column_of_min_value_in_row_2) {
  Matrix mat;
  const int width = 5;
  const int height = 3;
  Matrix_init(&mat, width, height);
  Matrix_fill_border(&mat, 1);
  *Matrix_at(&mat,2,4) = 12;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(&mat,2,0,2), 1);
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.hpp as needed.

TEST_MAIN() // Do NOT put a semicolon here
