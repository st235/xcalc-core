#include "FunctionsProvider.h"

#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>

#include "../terms/Terms.h"

namespace xcalc_internal {

double FunctionsProvider::evaluate(const std::string& identifier, double innerExpression) {
    std::string lowercaseId = identifier;

    std::transform(lowercaseId.begin(), lowercaseId.end(), lowercaseId.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    if (lowercaseId == Terms::FUNCTION_COS) {
        return std::cos(innerExpression);
    }

    return 0.0;
}

}
