#ifndef XCALC_CORE_TOKENIZER_H
#define XCALC_CORE_TOKENIZER_H

#include <string>
#include <sstream>

#include "./expressions/Expression.h"

namespace xcalc_internal {

class Tokenizer {
  public:
    explicit Tokenizer(const std::string& input);
    
    Expression* decimal();
    Expression* variable();

    bool isExpectedCharacterNext(char expected);
    void ignoreWhiteSpaces();

    bool startsWithIdentifier();
    std::string extractIdentifier();

    int getCurrentPosition();
    void restoreToPosition(int position);

    bool isEof();

  private:
    std::stringstream _stream;
};

} // namespace xcalc_internal

#endif //XCALC_CORE_TOKENIZER_H
