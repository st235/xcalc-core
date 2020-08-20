#ifndef XCALC_CORE_FUNCTIONEXPRESSION_H
#define XCALC_CORE_FUNCTIONEXPRESSION_H

#include <string>

#include "Expression.h"

namespace xcalc_internal {

/**
 * Single argument functions only,
 * as there is no need in multi var functions
 * inside of arithmetical expressions
 */
class FunctionExpression: public Expression {
  public:
    FunctionExpression(std::string identifier, Expression* innerExpression);
    ~FunctionExpression() override = default;

    double evaluate() override;

  private:
    std::string _identifier;
    Expression* _innerExpression;
};

}

#endif //XCALC_CORE_FUNCTIONEXPRESSION_H
