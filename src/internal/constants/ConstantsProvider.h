#ifndef XCALC_CORE_CONSTANTSPROVIDER_H
#define XCALC_CORE_CONSTANTSPROVIDER_H

#include <memory>

namespace xcalc_internal {

class ConstantsProvider {
public:
    static ConstantsProvider& getInstance()
    {
        static ConstantsProvider instance;
        return instance;
    }

    ConstantsProvider(ConstantsProvider const&) = delete;
    ConstantsProvider operator=(ConstantsProvider const&) = delete;

    double resolve(const std::string& identifier);

private:
    ConstantsProvider() = default;
};

}


#endif //XCALC_CORE_CONSTANTSPROVIDER_H
