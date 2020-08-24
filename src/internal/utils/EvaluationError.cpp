#include "EvaluationError.h"

#include "Formatter.h"

namespace xcalc_internal {

EvaluationError::EvaluationError(Type type, const std::string& description) noexcept:
    std::runtime_error(Formatter() << "error(" << type << "): " << description >> Formatter::end) {
}

const char * EvaluationError::what() const noexcept {
    return std::runtime_error::what();
}

}
