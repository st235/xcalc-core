#ifndef XCALC_CORE_ARITHMETICEXPRESSION_H
#define XCALC_CORE_ARITHMETICEXPRESSION_H

#include <string>

#include "Expression.h"

namespace xcalc_internal {

class ArithmeticExpression: public Expression {
  public:
    ArithmeticExpression(char operation,
                         Expression* left,
                         Expression* right);
    ~ArithmeticExpression() override;

    double evaluate() override;

  private:
    char _operator;
    Expression* _left;
    Expression* _right;
};

}

#endif //XCALC_CORE_ARITHMETICEXPRESSION_H
