#include "FunctionsProvider.h"

#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <stdexcept>

#include "../utils/Formatter.h"
#include "../utils/EvaluationError.h"
#include "../terms/Terms.h"
#include "../utils/AngleUnitsProvider.h"

namespace xcalc_internal {

double FunctionsProvider::evaluate(xcalc::DegreeMode degreeMode, const std::string& identifier, double innerExpression) {
    std::string lowercaseId = identifier;

    std::transform(lowercaseId.begin(), lowercaseId.end(), lowercaseId.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    if (lowercaseId == Terms::FUNCTION_COS) {
        return std::cos(ConvertToRads(degreeMode, innerExpression));
    }

    if (lowercaseId == Terms::FUNCTION_SIN) {
        return std::sin(ConvertToRads(degreeMode, innerExpression));
    }

    if (lowercaseId == Terms::FUNCTION_TAN) {
        return std::tan(ConvertToRads(degreeMode, innerExpression));
    }

    if (lowercaseId == Terms::FUNCTION_LOG) {
        return std::log(innerExpression);
    }

    if (lowercaseId == Terms::FUNCTION_LOG2) {
        return std::log2(innerExpression);
    }

    if (lowercaseId == Terms::FUNCTION_LOG10) {
        return std::log10(innerExpression);
    }

    if (lowercaseId == Terms::FUNCTION_SQRT) {
        return std::sqrt(innerExpression);
    }

    if (lowercaseId == Terms::FUNCTION_EXP) {
        return std::exp(innerExpression);
    }

    throw EvaluationError(EvaluationError::FUNCTION_NOT_FOUND, Formatter() << "cannot find function: " << identifier >> Formatter::end);
}

}
