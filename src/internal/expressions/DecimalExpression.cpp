#include "DecimalExpression.h"

namespace xcalc_internal {

DecimalExpression::DecimalExpression(double value): _value(value) {
}

double DecimalExpression::evaluate() {
    return _value;
}

} // namespace xcalc_internal
