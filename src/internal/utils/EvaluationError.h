#ifndef XCALC_CORE_EVALUATIONERROR_H
#define XCALC_CORE_EVALUATIONERROR_H

#include <string>
#include <stdexcept>

namespace xcalc_internal {

class EvaluationError: public std::runtime_error {
  public:
    enum Type: int {
        DIVIDE_BY_ZERO = 0,
        CONST_NOT_FOUND = 1,
        FUNCTION_NOT_FOUND = 2,
        ARITHMETIC_ERROR = 3,
        NO_SUCH_OPERATOR = 4,
        SYNTAX_ERROR = 5
    };

    EvaluationError(Type type, const std::string& description) noexcept;
    char const* what() const noexcept override;

};

}

#endif //XCALC_CORE_EVALUATIONERROR_H
