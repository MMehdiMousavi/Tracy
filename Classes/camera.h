//
// Created by Mehdi on 7/17/2021.
//

#pragma once
#include "utils.h"


class camera {
public:
    camera(
            point3 position,
            point3 lookat,
            vec3 up_vector,
            double vfov, // vertical field-of-view in degrees
            double aspect_ratio
    ) {
        auto theta = degrees_to_radians(vfov);
        auto h = tan(theta/2);
        auto viewport_height = 2.0 * h;
        auto viewport_width = aspect_ratio * viewport_height;

        auto w = unit_vector(position - lookat);
        auto u = unit_vector(cross(up_vector, w));
        auto v = cross(w, u);
        auto focal_length = 1.0;

        origin = position;
        horizontal = viewport_width * u;
        vertical =  viewport_height * v;
        lower_left_corner = origin - horizontal / 2 - vertical / 2 - w;
    }
    ray get_ray(double s, double t) const {
        return ray(origin, lower_left_corner + + s*horizontal + t*vertical - origin);
    }

private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
};


