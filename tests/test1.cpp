#include "unitLib.h"
#include "gtest/gtest.h"

namespace{
  TEST(UNITLIB, create){
       EXPECT_EQ(100, match(100));
  }

} //namespace
