// TestProject.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

extern "C" {
#include "mymath.h"
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

