#include "OperatorsProvider.h"

#include <cmath>

#include "../terms/Terms.h"

namespace xcalc_internal {

double OperatorsProvider::evaluate(char identifier, double left, double right) {
    switch (identifier) {
        case Terms::OPERATOR_PLUS: return left + right;
        case Terms::OPERATOR_MINUS: return left - right;
        case Terms::OPERATOR_DIVISION: return left / right;
        case Terms::OPERATOR_MULTIPLICATION: return left * right;
        case Terms::OPERATOR_POWER: return std::pow(left, right);
        default: return 0.0;
    }
}

double OperatorsProvider::evaluate(char identifier, double value) {
    switch (identifier) {
        case Terms::OPERATOR_PLUS: return +value;
        case Terms::OPERATOR_MINUS: return -value;
        case Terms::OPERATOR_EMPTY: return value;
        default: return 0.0;
    }
}

}
