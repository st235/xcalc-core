#include "./include/xcalc.h"

#include <memory>

#include "../internal/Parser.h"

namespace xcalc {

    std::string evaluate(DegreeMode degreeMode, const std::string& input) {
        std::unique_ptr<xcalc_internal::Parser> parser = std::make_unique<xcalc_internal::Parser>(input, degreeMode);

        xcalc_internal::Expression* expression = expression = parser->statement();
        if (!expression) {
            return "error";
        }

        try {
            std::ostringstream result;
            result << expression->evaluate();
            delete expression;
            return result.str();
        } catch (const std::runtime_error& exception) {
            delete expression;
            return std::string(exception.what());
        }
    }

} // namespace xcalc
