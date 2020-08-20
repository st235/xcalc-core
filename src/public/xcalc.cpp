#include "./include/xcalc.h"

#include <memory>
#include <sstream>

#include "../internal/Parser.h"
#include "../internal/expressions/Expression.h"

namespace xcalc {

    std::string evaluate(const std::string& input) {
        std::unique_ptr<xcalc_internal::Parser> parser = std::make_unique<xcalc_internal::Parser>(input);
        xcalc_internal::Expression* expression = parser->statement();

        if (expression == nullptr) {
            return "error";
        }

        std::ostringstream result;
        result << expression->evaluate();
        delete expression;

        return result.str();
    }

} // namespace xcalc
