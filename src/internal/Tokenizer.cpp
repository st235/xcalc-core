#include "Tokenizer.h"

#include "expressions/DecimalExpression.h"
#include "expressions/VariableExpression.h"

namespace xcalc_internal {

Tokenizer::Tokenizer(const std::string& input): _stream(input) {}

bool Tokenizer::isExpectedCharacterNext(char expected) {
    this->ignoreWhiteSpaces();

    if (_stream.peek() == expected) {
        _stream.get();
        return true;
    }

    return false;
}

Expression* Tokenizer::decimal() {
    this->ignoreWhiteSpaces();
    char current = _stream.peek();

    if (!std::isdigit(current)) {
        return nullptr;
    }

    double value;
    _stream >> value;
    return new DecimalExpression(value);
}

Expression* Tokenizer::variable() {
    this->ignoreWhiteSpaces();

    if (!startsWithIdentifier()) {
        return nullptr;
    }

    std::string variable = extractIdentifier();

    if (variable.length() <= 0) {
        return nullptr;
    }

    return new VariableExpression(variable);
}

bool Tokenizer::startsWithIdentifier() {
    this->ignoreWhiteSpaces();
    char current = _stream.peek();
    return std::isalpha(current);
}

std::string Tokenizer::extractIdentifier() {
    this->ignoreWhiteSpaces();
    std::string result;
    char current = _stream.peek();

    while (std::isalpha(current) || std::isdigit(current)) {
        char c = _stream.get();
        result += c;
        current = _stream.peek();
    }

    return result;
}

int Tokenizer::getCurrentPosition() {
    return _stream.tellg();
}

void Tokenizer::restoreToPosition(int position) {
    _stream.clear();
    _stream.seekg(position);
}

bool Tokenizer::isEof() {
    return _stream.eof();
}

void Tokenizer::ignoreWhiteSpaces() {
    char current = _stream.peek();

    while (std::isspace(current)) {
        _stream.get();
        current = _stream.peek();
    }
}

} // namespace xcalc_internal
