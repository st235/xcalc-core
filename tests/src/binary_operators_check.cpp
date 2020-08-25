#include "gtest/gtest.h"

#include "xcalc.h"

class BinaryOperatorsTests: public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

TEST_P(BinaryOperatorsTests, CheckOperatorCorrectness) {
    std::string input = std::get<0>(GetParam());
    std::string expected = std::get<1>(GetParam());
    ASSERT_EQ(expected, xcalc::evaluate(xcalc::DegreeMode::DEG, input));
}

INSTANTIATE_TEST_CASE_P(
    PlusOperatorTests,
    BinaryOperatorsTests,
    ::testing::Values(
        std::make_tuple("1+2", "3"),
        std::make_tuple("2+3", "5"),
        std::make_tuple("7+8+15", "30"),
        std::make_tuple("2.2+.2", "2.4"),
        std::make_tuple("0.0+0", "0"),
        std::make_tuple("3+3+3+1", "10"),
        std::make_tuple("9+1+3.2", "13.2"),
        std::make_tuple("0.333+0.334", "0.667"),
        std::make_tuple("9.21+.008", "9.218")
    )
);

INSTANTIATE_TEST_CASE_P(
        MinusOperatorTests,
        BinaryOperatorsTests,
        ::testing::Values(
                std::make_tuple("1-2", "-1"),
                std::make_tuple("2.2-3", "-0.8"),
                std::make_tuple("10-2-2", "6"),
                std::make_tuple("2.2-.2", "2"),
                std::make_tuple("1.0-0-0", "1"),
                std::make_tuple("99-100-71-4", "-76"),
                std::make_tuple("-2-2", "-4"),
                std::make_tuple("0.77-.777", "-0.007"),
                std::make_tuple("2.1-.1", "2")
        )
);

INSTANTIATE_TEST_CASE_P(
        MultiplyOperator,
        BinaryOperatorsTests,
        ::testing::Values(
                std::make_tuple("2*2*2", "8"),
                std::make_tuple("3*7", "21"),
                std::make_tuple("6*-3", "-18"),
                std::make_tuple("0.2*5", "1"),
                std::make_tuple("9*8.7", "78.3"),
                std::make_tuple("3*4*4", "48"),
                std::make_tuple("2*2*2*2*2*2*2*2*2*2", "1024"),
                std::make_tuple(".2*.6", "0.12"),
                std::make_tuple(".2*-.6", "-0.12")
        )
);

INSTANTIATE_TEST_CASE_P(
        DivideOperator,
        BinaryOperatorsTests,
        ::testing::Values(
                std::make_tuple("2/2", "1"),
                std::make_tuple("2/2/2", "0.5"),
                std::make_tuple("2/.5", "4"),
                std::make_tuple("-2/5", "-0.4"),
                std::make_tuple("2/-5", "-0.4"),
                std::make_tuple("9/9", "1"),
                std::make_tuple(".3/.3", "1"),
                std::make_tuple("2./4", "0.5"),
                std::make_tuple("1/100", "0.01")
        )
);

