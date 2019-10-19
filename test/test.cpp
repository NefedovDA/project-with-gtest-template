#include <gtest/gtest.h>

int sum(int a, int b);

TEST(Sum, Simple) {
  ASSERT_EQ(sum(1, 2), 3);
}