#include "OperatorsProvider.h"

#include <cmath>

#include "../utils/EvaluationError.h"
#include "../terms/Terms.h"

namespace xcalc_internal {

double OperatorsProvider::evaluate(char identifier, double left, double right) {
    switch (identifier) {
        case Terms::OPERATOR_PLUS: return left + right;
        case Terms::OPERATOR_MINUS: return left - right;
        case Terms::OPERATOR_DIVISION: {
            if (right == 0) {
                throw EvaluationError(EvaluationError::DIVIDE_BY_ZERO, "divide by zero");
            }
            return left / right;
        }
        case Terms::OPERATOR_MULTIPLICATION: return left * right;
        case Terms::OPERATOR_POWER: return std::pow(left, right);
        default: throw EvaluationError(EvaluationError::NO_SUCH_OPERATOR, "no such operator");
    }
}

double OperatorsProvider::evaluate(char identifier, double value) {
    switch (identifier) {
        case Terms::OPERATOR_PLUS: return +value;
        case Terms::OPERATOR_MINUS: return -value;
        case Terms::OPERATOR_FACTORIAL: return std::tgamma(value + 1);
        case Terms::OPERATOR_PERCENT: return value / 100;
        case Terms::OPERATOR_EMPTY: return value;
        default: throw EvaluationError(EvaluationError::NO_SUCH_OPERATOR, "no such operator");
    }
}

}
