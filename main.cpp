#include "Classes/utils.h"
#include "Classes/color.h"
#include "Classes/hittable_list.h"
#include "Classes/sphere.h"
#include "Classes/camera.h"
#include "Classes/material.h"


#include <iostream>


color ray_color(const ray& r, const hittable& world, int bounce_limit) {
    hit_record rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (bounce_limit<=0)
        return color(0,0,0);

    if (world.hit(r,0.001,infinity,rec)) {

        ray scattered;
        color attenuation;
        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, bounce_limit-1);
        return color(0,0,0);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 640;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 500;
    const int bounce_lim = 50;

    //World
    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(0.235, 0.647, 0.843));
    auto material_center = make_shared<dielectric>(2.5);

    auto material_left = make_shared<metal>(color(0.8,0.8,0.8),0.3);
    auto material_right = make_shared<metal>(color(0.882, 0.439, 0.117),1.0);

    world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0),100.0, material_ground));
    world.add(make_shared<sphere>(point3(0.0,0.0,-1), 0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,0.0,-1), 0.5, material_left));
    world.add(make_shared<sphere>(point3(1.0,0.0,-1), 0.5, material_right));

    // Camera

    camera cam(point3(-2,2,1), point3(0,0,-1), vec3(0,1,0), 25, aspect_ratio);

    // Render

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0,0,0);
            for (int s =0; s<samples_per_pixel; ++s){
                auto u = (i + random_double()) / (image_width-1);
                auto v = (j + random_double()) /(image_height-1);

                ray r = cam.get_ray(u,v);
                pixel_color += ray_color(r, world, bounce_lim);
            }
            write_color(std::cout,pixel_color,samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
}