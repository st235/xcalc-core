#ifndef XCALC_CORE_EXPRESSION_H
#define XCALC_CORE_EXPRESSION_H

namespace xcalc_internal {

class Expression {
  public:
    virtual double evaluate() = 0;
    virtual ~Expression() = default;
};

} // namespace xcalc_internal

#endif //XCALC_CORE_EXPRESSION_H
