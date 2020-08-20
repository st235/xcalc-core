#ifndef XCALC_CORE_TERMS_H
#define XCALC_CORE_TERMS_H

#include <string>

namespace xcalc_internal {

class Terms {
  public:
    static constexpr char* CONST_PI_DEFINITION = "pi";
    static constexpr double CONST_PI_VALUE = 3.141592653589793;

    static constexpr char OPERATOR_EMPTY = '\0';
    static constexpr char OPERATOR_PLUS = '+';
    static constexpr char OPERATOR_MINUS = '-';
    static constexpr char OPERATOR_DIVISION = '/';
    static constexpr char OPERATOR_MULTIPLICATION = '*';
    static constexpr char OPERATOR_POWER = '^';

    static constexpr char LEFT_PARENTHESIS = '(';
    static constexpr char RIGHT_PARENTHESIS = ')';

    static constexpr char* FUNCTION_COS = "cos";
};

}

#endif //XCALC_CORE_TERMS_H
