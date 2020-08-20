#include "gtest/gtest.h"

#include "xcalc.h"

TEST(XCALC_EVALUATE, evaluate) {
    EXPECT_EQ (xcalc::evaluate(""),  "");
}
