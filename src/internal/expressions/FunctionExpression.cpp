#include "FunctionExpression.h"

#include "../functions/FunctionsProvider.h"

namespace xcalc_internal {

FunctionExpression::FunctionExpression(xcalc::DegreeMode degreeMode, std::string identifier, Expression* expression):
    _degreeMode(degreeMode),
    _identifier(std::move(identifier)),
    _innerExpression(expression) {
}

double FunctionExpression::evaluate() {
    if (_innerExpression == nullptr) {
        return 0.0;
    }

    double innerValue = _innerExpression->evaluate();
    return FunctionsProvider::getInstance().evaluate(_degreeMode, _identifier, innerValue);
}

}
