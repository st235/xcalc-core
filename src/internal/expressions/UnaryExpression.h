#ifndef XCALC_CORE_UNARYEXPRESSION_H
#define XCALC_CORE_UNARYEXPRESSION_H

#include "Expression.h"

namespace xcalc_internal {

class UnaryExpression: public Expression {
public:
    UnaryExpression(char identifier, Expression* expression);
    ~UnaryExpression() override = default;

    double evaluate() override;

private:
    char _identifier;
    Expression* _expression;
};

}

#endif //XCALC_CORE_UNARYEXPRESSION_H
