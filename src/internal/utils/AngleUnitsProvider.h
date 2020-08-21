#ifndef XCALC_CORE_ANGLEUNITSPROVIDER_H
#define XCALC_CORE_ANGLEUNITSPROVIDER_H

#include "../../public/include/DegreeMode.h"

namespace xcalc_internal {

double ConvertToRads(xcalc::DegreeMode mode, double value);

}

#endif //XCALC_CORE_ANGLEUNITSPROVIDER_H
