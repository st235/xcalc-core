#include "ArithmeticExpression.h"

#include "../operators/OperatorsProvider.h"

namespace xcalc_internal {

ArithmeticExpression::ArithmeticExpression(char operation, Expression* left,
                                           Expression* right):
        _operator(operation),
        _left(left),
        _right(right) {
}

ArithmeticExpression::~ArithmeticExpression() noexcept {
    delete _left;
    delete _right;
}

double ArithmeticExpression::evaluate() {
    if (_left == nullptr || _right == nullptr) {
        return 0.0;
    }

    double left = _left->evaluate();
    double right = _right->evaluate();

    return OperatorsProvider::getInstance().evaluate(_operator, left, right);
}

}
