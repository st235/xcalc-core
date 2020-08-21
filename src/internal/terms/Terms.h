#ifndef XCALC_CORE_TERMS_H
#define XCALC_CORE_TERMS_H

#include <string>

namespace xcalc_internal {

class Terms {
  public:
    static constexpr char* CONST_PI_DEFINITION = "pi";
    static constexpr double CONST_PI_VALUE = 3.141592653589793;
    static constexpr char* CONST_E_DEFINITION = "e";
    static constexpr double CONST_E_VALUE = 2.718281828459045;

    static constexpr char OPERATOR_EMPTY = '\0';
    static constexpr char OPERATOR_PLUS = '+';
    static constexpr char OPERATOR_MINUS = '-';
    static constexpr char OPERATOR_DIVISION = '/';
    static constexpr char OPERATOR_MULTIPLICATION = '*';
    static constexpr char OPERATOR_POWER = '^';
    static constexpr char OPERATOR_FACTORIAL = '!';
    static constexpr char OPERATOR_PERCENT = '%';

    static constexpr char LEFT_PARENTHESIS = '(';
    static constexpr char RIGHT_PARENTHESIS = ')';

    static constexpr char* FUNCTION_COS = "cos";
    static constexpr char* FUNCTION_SIN = "sin";
    static constexpr char* FUNCTION_TAN = "tan";
    static constexpr char* FUNCTION_LOG = "ln";
    static constexpr char* FUNCTION_LOG2 = "log2";
    static constexpr char* FUNCTION_LOG10 = "log10";
    static constexpr char* FUNCTION_SQRT = "sqrt";
    static constexpr char* FUNCTION_EXP = "exp";
};

}

#endif //XCALC_CORE_TERMS_H
