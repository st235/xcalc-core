#include "ConstantsProvider.h"

#include <string>
#include <algorithm>
#include <cctype>

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

    return 0.0;
}

}
