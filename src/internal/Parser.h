#ifndef XCALC_CORE_PARSER_H
#define XCALC_CORE_PARSER_H

#include <string>
#include <memory>

#include "Tokenizer.h"
#include "expressions/Expression.h"
#include "../../public/include/DegreeMode.h"

namespace xcalc_internal {

class Parser {
public:
    explicit Parser(const std::string& value, xcalc::DegreeMode degreeMode = xcalc::DegreeMode::RADS);
    ~Parser() = default;

    Expression* statement();

private:
    std::unique_ptr<Tokenizer> _tokenizer;
    xcalc::DegreeMode _degreeMode;

    Expression* calculation();
    Expression* sum();
    Expression* product();
    Expression* short_product();
    Expression* factor();
    Expression* power();
    Expression* term();
    Expression* group();
    Expression* suffix_unary();
    Expression* prefix_unary();
    Expression* terminals();
    Expression* function();
};

}

#endif //XCALC_CORE_PARSER_H
