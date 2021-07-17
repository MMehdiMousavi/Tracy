//
// Created by Mehdi on 7/17/2021.
//
#pragma once
#ifndef RAYTRACER_HITTABLE_H
#define RAYTRACER_HITTABLE_H
#include "ray.h"

struct hit_record {
    point3 p;
    vec3 normal;
    double t;
};
/*
 * Hittable objects are polymorphistic, so we define a hit() function that we can override later in our other objects.
 */
class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;

};


#endif //RAYTRACER_HITTABLE_H
