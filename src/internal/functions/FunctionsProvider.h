#ifndef XCALC_CORE_FUNCTIONSPROVIDER_H
#define XCALC_CORE_FUNCTIONSPROVIDER_H

#include <memory>

namespace xcalc_internal {

class FunctionsProvider {
public:
    static FunctionsProvider& getInstance()
    {
        static FunctionsProvider instance;
        return instance;
    }

    FunctionsProvider(FunctionsProvider const&) = delete;
    FunctionsProvider operator=(FunctionsProvider const&) = delete;

    double evaluate(const std::string& identifier, double innerExpression);

private:
    FunctionsProvider() = default;
};

}


#endif //XCALC_CORE_FUNCTIONSPROVIDER_H
