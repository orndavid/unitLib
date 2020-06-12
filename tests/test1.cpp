
#include "unitLib.h"
#include "gtest/gtest.h"

namespace{
  TEST(UNITLIB, Kg_initialize){
    Kg<int> kg1;
    double kg2_val{3.3};
    Kg<double> kg2(kg2_val);
    Kg<float> kg3(102);
    EXPECT_EQ(kg1.value(), 0);
    EXPECT_EQ(kg2.unit(), "kg");
    EXPECT_EQ(kg2.value(), kg2_val);
    EXPECT_EQ(kg2.unit(), "kg");
    EXPECT_EQ(kg3.value(), 102);
    EXPECT_EQ(kg3.unit(), "kg");


  }

  TEST(UNITLIB, lbs_initialize){
    lbs<int> lbs1;
    double lbs2_val{3.3};
    lbs<double> lbs2(lbs2_val);
    lbs<double> lbs3(303);
    EXPECT_EQ(lbs1.value(), 0);
    EXPECT_EQ(lbs2.unit(), "lbs");
    EXPECT_EQ(lbs2.value(), lbs2_val);
    EXPECT_EQ(lbs2.unit(), "lbs");
    EXPECT_EQ(lbs3.value(), 303.0);
    EXPECT_EQ(lbs3.unit(), "lbs");

    }


  TEST(UNITLIB, force_initialize){
    Force<int> force1;
    double force2_val{3.3};
    Force<double> force2(force2_val);
    Force<double> force3(303);
    EXPECT_EQ(force1.value(), 0);
    EXPECT_EQ(force2.unit(), "F");
    EXPECT_EQ(force2.value(), force2_val);
    EXPECT_EQ(force2.unit(), "F");
    EXPECT_EQ(force3.value(), 303.0);
    EXPECT_EQ(force3.unit(), "F");

  }


} //namespace
