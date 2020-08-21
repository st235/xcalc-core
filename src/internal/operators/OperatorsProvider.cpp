#include "OperatorsProvider.h"

#include <cmath>

#include "../utils/Formatter.h"
#include "../terms/Terms.h"

namespace xcalc_internal {

double OperatorsProvider::evaluate(char identifier, double left, double right) {
    switch (identifier) {
        case Terms::OPERATOR_PLUS: return left + right;
        case Terms::OPERATOR_MINUS: return left - right;
        case Terms::OPERATOR_DIVISION: return left / right;
        case Terms::OPERATOR_MULTIPLICATION: return left * right;
        case Terms::OPERATOR_POWER: return std::pow(left, right);
        default: throw std::runtime_error(Formatter() << "error: cannot find operator with name: " << identifier >> Formatter::end);
    }
}

double OperatorsProvider::evaluate(char identifier, double value) {
    switch (identifier) {
        case Terms::OPERATOR_PLUS: return +value;
        case Terms::OPERATOR_MINUS: return -value;
        case Terms::OPERATOR_FACTORIAL: return std::tgamma(value + 1);
        case Terms::OPERATOR_PERCENT: return value / 100;
        case Terms::OPERATOR_EMPTY: return value;
        default: throw std::runtime_error(Formatter() << "error: cannot find operator with name: " << identifier >> Formatter::end);
    }
}

}
