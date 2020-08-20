#ifndef XCALC_CORE_DECIMALEXPRESSION_H
#define XCALC_CORE_DECIMALEXPRESSION_H

#include "Expression.h"

namespace xcalc_internal {

class DecimalExpression: public Expression {
  public:
    explicit DecimalExpression(double value);
    ~DecimalExpression() override = default;

    double evaluate() override;

  private:
    double _value;
};

}

#endif //XCALC_CORE_DECIMALEXPRESSION_H
