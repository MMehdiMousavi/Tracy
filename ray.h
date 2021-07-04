//
// Created by Mehdi on 7/4/2021.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H
#include "vec3.h"

class ray {

public:
    ray() {}
    ray(const point3& origin, const vec3& direction)
        : orig(origin), dir(direction)
    {}

    point3 origin() const {return orig;}
    point3 direction() const{return dir;}

    point3 at(double t) const {
        return orig+t*dir;
    }

public:
    point3 orig;
    vec3 dir;
};


#endif //RAYTRACER_RAY_H
