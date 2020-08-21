#include "AngleUnitsProvider.h"

namespace {

constexpr double RAD_TO_DEGREE_SCALE = 0.01745329252;

double ConvertRadsToDegree(double value) {
    return value * RAD_TO_DEGREE_SCALE;
}

}

namespace xcalc_internal {

double ConvertToRads(xcalc::DegreeMode mode, double value) {
    switch (mode) {
        case xcalc::DegreeMode::RADS: return value;
        case xcalc::DegreeMode::DEG: return ConvertRadsToDegree(value);
    }
}

} // namespace xcalc_internal
