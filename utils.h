//
// Created by Mehdi on 7/17/2021.
//
#pragma once


#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

//Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//Utils
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double(){
    //returns a random double in range[0,1)
    return rand()/(RAND_MAX+1.0);
}

inline double random_double(double min, double max){
    //returns a random double in range[min,max)
    return min + (max-min)*random_double();
}

inline double clamp(double x, double min, double max) {
    // clamps the value x to the range [min,max]
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

// Common Headers
#include "ray.h"
#include "vec3.h"
