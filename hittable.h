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
    bOOl front_face;

    //We set things up so that normals always point “outward” from the surface, or always point against the incident ray.
    inline void set_face_normal(const ray& r, const vec3& outward_normal){
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal
    }
};
/*
 * Hittable objects are polymorphistic, so we define a hit() function that we can override later in our other objects.
 */
class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;

};


#endif //RAYTRACER_HITTABLE_H
