#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#define _USE_MATH_DEFINES
#include <cmath>

namespace utils {
    float getDistance(float x1, float y1, float x2, float y2){
        return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
    }
}

#endif // UTILS_HPP_INCLUDED
