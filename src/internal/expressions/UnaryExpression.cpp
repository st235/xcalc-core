#include "UnaryExpression.h"

#include "../operators/OperatorsProvider.h"

namespace xcalc_internal {

UnaryExpression::UnaryExpression(char identifier, Expression *expression):
    _identifier(identifier),
    _expression(expression) {
}

double UnaryExpression::evaluate() {
    if (_expression == nullptr) {
        return 0.0;
    }

    double value = _expression->evaluate();
    return OperatorsProvider::getInstance().evaluate(_identifier, value);
}

}
