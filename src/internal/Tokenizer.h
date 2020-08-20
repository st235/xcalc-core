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
    std::string extractSymbols();
    void ignoreWhiteSpaces();

    int getCurrentPosition();
    void restoreToPosition(int position);

    bool isEof();

  private:
    std::stringstream _stream;
};

} // namespace xcalc_internal

#endif //XCALC_CORE_TOKENIZER_H
