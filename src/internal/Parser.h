#ifndef XCALC_CORE_PARSER_H
#define XCALC_CORE_PARSER_H

#include <string>
#include <memory>

#include "Tokenizer.h"
#include "expressions/Expression.h"

namespace xcalc_internal {

class Parser {
public:
    explicit Parser(const std::string& value);
    ~Parser() = default;

    Expression* statement();

private:
    std::unique_ptr<Tokenizer> _tokenizer;

    Expression* calculation();
    Expression* sum();
    Expression* product();
    Expression* factor();
    Expression* power();
    Expression* term();
    Expression* group();
    Expression* unary_operators();
    Expression* terminals();
    Expression* function();
};

}

#endif //XCALC_CORE_PARSER_H
