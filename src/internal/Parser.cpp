#include "Parser.h"

#include <memory>

#include "./expressions/FunctionExpression.h"
#include "./expressions/ArithmeticExpression.h"
#include "./expressions/UnaryExpression.h"
#include "./terms/Terms.h"

namespace xcalc_internal {

Parser::Parser(const std::string& value, xcalc::DegreeMode degreeMode): _degreeMode(degreeMode) {
    _tokenizer = std::make_unique<Tokenizer>(value);
}

Expression*  Parser::statement() {
    return calculation();
}

Expression*  Parser::calculation() {
    int start = _tokenizer->getCurrentPosition();
    Expression*  expression = nullptr;

    if (!(expression = sum()) || !_tokenizer->isEof()) {
        delete expression;
        _tokenizer->restoreToPosition(start);
        return nullptr;
    }

    return expression;
}

Expression*  Parser::sum() {
    int start = _tokenizer->getCurrentPosition();
    Expression*  lhs = product();
    Expression*  rhs = nullptr;

    while (lhs) {
        if (_tokenizer->isExpectedCharacterNext(Terms::OPERATOR_PLUS)) {
            if (rhs = product()) {
                lhs = new ArithmeticExpression(Terms::OPERATOR_PLUS, lhs, rhs);
            } else {
                delete lhs;
                lhs = nullptr;
            }
            continue;
        }

        if (_tokenizer->isExpectedCharacterNext(Terms::OPERATOR_MINUS)) {
            if (rhs = product()) {
                lhs = new ArithmeticExpression(Terms::OPERATOR_MINUS, lhs, rhs);
            } else {
                delete lhs;
                lhs = nullptr;
            }
            continue;
        }

        break;
    }

    if (lhs == nullptr) {
        _tokenizer->restoreToPosition(start);
    }

    return lhs;
}

Expression*  Parser::product() {
    int start = _tokenizer->getCurrentPosition();
    Expression*  lhs = factor();
    Expression*  rhs = nullptr;

    while (lhs) {
        if (_tokenizer->isExpectedCharacterNext(Terms::OPERATOR_MULTIPLICATION)) {
            if (rhs = factor()) {
                lhs = new ArithmeticExpression(Terms::OPERATOR_MULTIPLICATION, lhs, rhs);
            } else {
                delete lhs;
                lhs = nullptr;
            }
            continue;
        }

        if (_tokenizer->isExpectedCharacterNext(Terms::OPERATOR_DIVISION)) {
            if (rhs = factor()) {
                lhs = new ArithmeticExpression(Terms::OPERATOR_DIVISION, lhs, rhs);
            } else {
                delete lhs;
                lhs = nullptr;
            }
            continue;
        }

        break;
    }

    if (lhs == nullptr) {
        _tokenizer->restoreToPosition(start);
    }

    return lhs;
}

Expression* Parser::short_product() {
    int start = _tokenizer->getCurrentPosition();

    Expression* decimal = _tokenizer->decimal();
    Expression* expression = nullptr;

    if (decimal && (expression = terminals())) {
        return new ArithmeticExpression(Terms::OPERATOR_MULTIPLICATION, decimal, expression);
    }

    delete decimal;
    delete expression;
    _tokenizer->restoreToPosition(start);
    return nullptr;
}

Expression*  Parser::factor() {
    int start = _tokenizer->getCurrentPosition();

    Expression*  expression = nullptr;

    if (!(expression = short_product()) && !(expression = power()) && !(expression = term())) {
        _tokenizer->restoreToPosition(start);
        delete expression;
        return nullptr;
    }

    return expression;
}

Expression* Parser::power() {
    int start = _tokenizer->getCurrentPosition();
    Expression*  t = nullptr;
    Expression*  f = nullptr;

    if (!(t = term()) ||
        !_tokenizer->isExpectedCharacterNext(Terms::OPERATOR_POWER) ||
        !(f = factor())) {
        _tokenizer->restoreToPosition(start);
        delete t;
        delete f;
        return nullptr;
    }

    return new ArithmeticExpression(Terms::OPERATOR_POWER, t, f);
}

Expression* Parser::term() {
    int start = _tokenizer->getCurrentPosition();
    Expression* expression = nullptr;

    if (!(expression = prefix_unary()) && !(expression = suffix_unary())) {
        _tokenizer->restoreToPosition(start);
        delete expression;
        return nullptr;
    }

    return expression;
}

Expression* Parser::group() {
    int start = _tokenizer->getCurrentPosition();
    Expression* expression = nullptr;

    if (!_tokenizer->isExpectedCharacterNext(Terms::LEFT_PARENTHESIS) ||
        !(expression = sum()) ||
        !_tokenizer->isExpectedCharacterNext(Terms::RIGHT_PARENTHESIS)) {
        _tokenizer->restoreToPosition(start);
        delete expression;
        return nullptr;
    }

    return expression;
}

Expression* Parser::suffix_unary() {
    int start = _tokenizer->getCurrentPosition();
    Expression* expression = terminals();

    if (expression) {
        if (_tokenizer->isExpectedCharacterNext(Terms::OPERATOR_PERCENT)) {
            return new UnaryExpression(Terms::OPERATOR_PERCENT, expression);
        }

        if (_tokenizer->isExpectedCharacterNext(Terms::OPERATOR_FACTORIAL)) {
            return new UnaryExpression(Terms::OPERATOR_FACTORIAL, expression);
        }
    }

    delete expression;
    _tokenizer->restoreToPosition(start);
    return nullptr;
}

Expression* Parser::prefix_unary() {
    int start = _tokenizer->getCurrentPosition();
    _tokenizer->ignoreWhiteSpaces();
    Expression* expression = nullptr;

    if (_tokenizer->isExpectedCharacterNext(Terms::OPERATOR_PLUS) && ((expression = suffix_unary()) || (expression = terminals()))) {
        return new UnaryExpression(Terms::OPERATOR_PLUS, expression);
    }

    if (_tokenizer->isExpectedCharacterNext(Terms::OPERATOR_MINUS) && ((expression = suffix_unary()) || (expression = terminals()))) {
        return new UnaryExpression(Terms::OPERATOR_MINUS, expression);
    }

    if (!(expression = suffix_unary()) && !(expression = terminals())) {
        _tokenizer->restoreToPosition(start);
        delete expression;
        return nullptr;
    }

    return new UnaryExpression(Terms::OPERATOR_EMPTY, expression);
}

Expression * Parser::terminals() {
    int start = _tokenizer->getCurrentPosition();
    Expression* expression = nullptr;

    if ((expression = group()) || (expression = function()) || (expression = _tokenizer->variable()) ||
            (expression = _tokenizer->decimal())) {
        return expression;
    }

    _tokenizer->restoreToPosition(start);
    delete expression;
    return nullptr;
}

Expression* Parser::function() {
    int start = _tokenizer->getCurrentPosition();

    if (!_tokenizer->startsWithIdentifier()) {
        _tokenizer->restoreToPosition(start);
        return nullptr;
    }

    std::string id = _tokenizer->extractIdentifier();

    if (id.empty()) {
        _tokenizer->restoreToPosition(start);
        return nullptr;
    }

    Expression* expression = nullptr;

    if (_tokenizer->isExpectedCharacterNext(Terms::LEFT_PARENTHESIS)) {
        _tokenizer->ignoreWhiteSpaces();
        if ((expression = sum())) {
            _tokenizer->ignoreWhiteSpaces();

            if (_tokenizer->isExpectedCharacterNext(Terms::RIGHT_PARENTHESIS)) {
                return new FunctionExpression(_degreeMode, id, expression);
            }
        }
    }

    _tokenizer->restoreToPosition(start);
    delete expression;
    return nullptr;
}


}
