//
// Created by Mehdi on 7/4/2021.
//
#pragma once
#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H
#include "vec3.h"
#include <iostream>

void write_color(std::ostream &out, color pixel_color) {
//write RGB value of each color

out << static_cast<int>(255.999 * pixel_color.x()) << ' '
    << static_cast<int>(255.999 * pixel_color.y()) << ' '
    << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif //RAYTRACER_COLOR_H
