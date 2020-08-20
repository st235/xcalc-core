#ifndef XCALC_CORE_OPERATORSPROVIDER_H
#define XCALC_CORE_OPERATORSPROVIDER_H

#include <memory>

namespace xcalc_internal {

class OperatorsProvider {
public:
    static OperatorsProvider& getInstance()
    {
        static OperatorsProvider instance;
        return instance;
    }

    OperatorsProvider(OperatorsProvider const&) = delete;
    OperatorsProvider operator=(OperatorsProvider const&) = delete;


    double evaluate(char identifier, double left, double right);
    double evaluate(char identifier, double value);

private:
    OperatorsProvider() = default;
};

};


#endif //XCALC_CORE_OPERATORSPROVIDER_H
