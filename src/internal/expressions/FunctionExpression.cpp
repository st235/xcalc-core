#include "FunctionExpression.h"

#include "../functions/FunctionsProvider.h"

namespace xcalc_internal {

FunctionExpression::FunctionExpression(std::string identifier, Expression* expression):
    _identifier(std::move(identifier)),
    _innerExpression(expression) {
}

double FunctionExpression::evaluate() {
    if (_innerExpression == nullptr) {
        return 0.0;
    }

    double innerValue = _innerExpression->evaluate();
    return FunctionsProvider::getInstance().evaluate(_identifier, innerValue);
}

}
