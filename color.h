//
// Created by Mehdi on 7/4/2021.
//
#pragma once
#include "vec3.h"
#include <iostream>

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {

    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    //Divide the color by the number of samples.
    auto scale = 1.0 / samples_per_pixel;
    r*=scale;
    g*=scale;
    b*=scale;

//write RGB value of each color
out << static_cast<int>(255.999 * r) << ' '
    << static_cast<int>(255.999 * g) << ' '
    << static_cast<int>(255.999 * b) << '\n';
}


