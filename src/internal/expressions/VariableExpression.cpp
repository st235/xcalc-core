#include "VariableExpression.h"

#include "../constants/ConstantsProvider.h"

namespace xcalc_internal {

VariableExpression::VariableExpression(std::string identifier): _identifier(std::move(identifier)) {}

double VariableExpression::evaluate() {
    return ConstantsProvider::getInstance().resolve(_identifier);
}

}
