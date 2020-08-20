#ifndef XCALC_CORE_VARIABLEEXPRESSION_H
#define XCALC_CORE_VARIABLEEXPRESSION_H

#include <string>

#include "Expression.h"

namespace xcalc_internal {

class VariableExpression: public Expression {
public:
    explicit VariableExpression(std::string identifier);
    ~VariableExpression() override = default;

    double evaluate() override;

private:
    std::string _identifier;
};

} // namespace xcalc_internal

#endif //XCALC_CORE_VARIABLEEXPRESSION_H
