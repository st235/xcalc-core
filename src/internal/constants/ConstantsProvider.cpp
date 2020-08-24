#include "ConstantsProvider.h"

#include <string>
#include <algorithm>
#include <cctype>

#include "../utils/EvaluationError.h"
#include "../utils/Formatter.h"
#include "../terms/Terms.h"

namespace xcalc_internal {

double ConstantsProvider::resolve(const std::string& identifier) {
    std::string lowercaseId = identifier;

    std::transform(lowercaseId.begin(), lowercaseId.end(), lowercaseId.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    if (lowercaseId == Terms::CONST_PI_DEFINITION) {
        return Terms::CONST_PI_VALUE;
    }

    if (lowercaseId == Terms::CONST_E_DEFINITION) {
        return Terms::CONST_E_VALUE;
    }

    throw EvaluationError(EvaluationError::CONST_NOT_FOUND, Formatter() << "cannot find const with such name: "  << identifier >> Formatter::end);
}

}
