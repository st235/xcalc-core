#include "gtest/gtest.h"

#include "xcalc.h"

TEST(XCALC_EVALUATE, evaluate) {
    EXPECT_EQ(xcalc::evaluate("-1"),  "-1");
    EXPECT_EQ(xcalc::evaluate("-1+2"),  "1");
    EXPECT_EQ(xcalc::evaluate("(3+5)*7"),  "56");
}
