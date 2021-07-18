//
// Created by Mehdi on 7/18/2021.
//
#pragma once
#include "utils.h"


class material {
    struct hit_record;
    class material {
    public:
        virtual bool scatter(
                const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
                )
    };



