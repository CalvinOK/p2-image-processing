#include "Matrix.hpp"
#include "Image_test_helpers.hpp"
#include "unit_test_framework.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image img;
  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(&img, 2, 2);
  Image_set_pixel(&img, 0, 0, red);
  Image_set_pixel(&img, 0, 1, green);
  Image_set_pixel(&img, 1, 0, blue);
  Image_set_pixel(&img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(&img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.hpp as needed.

//image init 1
TEST(test_im_init_basic){
  Image img;
  Image_init(&img, 1, 3);
  Image_fill(&img, {0, 0, 0});
  
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).r, 0);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).g, 0);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).b, 0);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 1).r, 0);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 1).g, 0);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 1).b, 0);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 2).r, 0);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 2).g, 0);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 2).b, 0);

  ASSERT_EQUAL(img.width, 1);
  ASSERT_EQUAL(img.height, 3);
}
// image init 2
TEST(test_init_from_istream){
  stringstream stream;
  stream << "P3\n1 2\n255\n0 0 255 255 255 255\n";

  Image img;
  Image_init(&img, stream);

  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).r, 0);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).g, 0);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).b, 255);

  ASSERT_EQUAL(Image_get_pixel(&img, 0, 1).r, 255);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 1).g, 255);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 1).b, 255);
  
  ASSERT_EQUAL(img.width, 1);
  ASSERT_EQUAL(img.height, 2);
}

// image print
TEST(test_print_1) {
  Image img;
  const Pixel red = {255, 0, 0};
  Image_init(&img, 1, 1);
  Image_set_pixel(&img, 0, 0, red);

  // Capture our output
  ostringstream s;
  Image_print(&img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n1 1\n255\n";
  correct << "255 0 0 \n";
  ASSERT_EQUAL(s.str(), correct.str());
}

//image width
TEST(test_im_width_1) {
  Image img;
  Image_init(&img, 1, 2);
  ASSERT_EQUAL(Image_width(&img),1);
}

TEST(test_im_width_2) {
  Image img;
  Image_init(&img, 3, 10);

  ASSERT_EQUAL(Image_width(&img),3);
}

//image height
TEST(test_im_height_1) {
  Image img;
  Image_init(&img, 1, 2);
  ASSERT_EQUAL(Image_height(&img),2);
}

TEST(test_im_height_2) {
  Image img;
  Image_init(&img, 3, 10);

  ASSERT_EQUAL(Image_height(&img),10);
}

//image get pixel
TEST(test_im_get_pixel_1) {
  Image img;
  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(&img, 2, 2);
  Image_set_pixel(&img, 0, 0, red);
  Image_set_pixel(&img, 0, 1, green);
  Image_set_pixel(&img, 1, 0, blue);
  Image_set_pixel(&img, 1, 1, white);

  ASSERT_EQUAL(Image_get_pixel(&img, 1, 1).r, white.r);
  ASSERT_EQUAL(Image_get_pixel(&img, 1, 1).g, white.g);
  ASSERT_EQUAL(Image_get_pixel(&img, 1, 1).b, white.b);

}

//image get pixel
TEST(test_im_get_pixel_2) {
  Image img;
  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(&img, 5, 5);
  Image_set_pixel(&img, 0, 0, red);
  Image_set_pixel(&img, 0, 1, green);
  Image_set_pixel(&img, 1, 0, blue);
  Image_set_pixel(&img, 1, 1, white);

  ASSERT_EQUAL(Image_get_pixel(&img, 00, 0).r, red.r);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).g, red.g);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).b, red.b);

}

//image set pixel
TEST(test_im_set_pixel_1) {
  Image img;
  const Pixel red = {255, 0, 0};

  Image_init(&img, 2, 2);
  Image_set_pixel(&img, 0, 1, red);

  ASSERT_EQUAL(Image_get_pixel(&img, 0, 1).r, red.r);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 1).g, red.g);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 1).b, red.b);

}

TEST(test_im_set_pixel_2) {
  Image img;
  const Pixel white = {255, 255, 255};

  Image_init(&img, 1, 1);
  Image_set_pixel(&img, 0, 0, white);

  ASSERT_EQUAL(Image_get_pixel(&img, 0,0).r, white.r);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).g, white.g);
  ASSERT_EQUAL(Image_get_pixel(&img, 0, 0).b, white.b);
}

// TEST(test_im_set_pixel_3) {
//   Image img;
//   const Pixel blue = {0, 0, 255};

//   Image_init(&img,3, 4);
//   Image_set_pixel(&img, 2, 3, blue);

//   ASSERT_EQUAL(Image_get_pixel(&img, 2, 3).r, blue.r);
//   ASSERT_EQUAL(Image_get_pixel(&img, 2, 3).g, blue.g);
//   ASSERT_EQUAL(Image_get_pixel(&img, 2, 3).b, blue.b);
// }

//image fill
TEST(test_im_fill_1) {
  Image img;
  const Pixel blue = {0, 0, 255};

  Image_init(&img,3, 4);
  Image_fill(&img, blue);

  ASSERT_EQUAL(Image_get_pixel(&img, 2,3).r, blue.r);
  ASSERT_EQUAL(Image_get_pixel(&img, 2,3).g, blue.g);
  ASSERT_EQUAL(Image_get_pixel(&img, 2,3).b, blue.b);
}

//image fill
TEST(test_im_fill_2) {
  Image img;
  const Pixel white = {255, 255, 255};

  Image_init(&img,3, 4);
  Image_fill(&img, white);

  for (int j=0; j < Image_width(&img); ++j){
    for (int i = 0; i < Image_height(&img); ++i){
      ASSERT_EQUAL(Image_get_pixel(&img, i,j).r, white.r);
      ASSERT_EQUAL(Image_get_pixel(&img, i,j).g, white.g);
      ASSERT_EQUAL(Image_get_pixel(&img, i,j).b, white.b);
    }
  }
}

TEST_MAIN() // Do NOT put a semicolon here
