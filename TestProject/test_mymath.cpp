#include "gtest/gtest.h"

extern "C" {
#include "mymath.h"
}

class MyMathTest : public ::testing::Test {
 protected:
  virtual void SetUp() {

  }

  // virtual void TearDown() {}
};

class MathClass {
  virtual ~MathClass() {}
  virtual void doSqaure() = 0;
};

/*
TEST_F(MyMathTest, testBasic) 
{
	EXPECT_EQ(25, square(5));
	EXPECT_EQ(36, square(6));

}

TEST_F(MyMathTest, testOverFlow) 
{
	EXPECT_EQ(10000000000, square(100000));
}
*/