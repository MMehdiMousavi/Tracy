# Raytracer
A textbook C++ Raytracer software 
I will remove the wip when the repo is complete.

How to use: 

    set parameters: sanoles per pixel, image width, bounce limit.
    create world: add objects, materials. (some are there already)
    set up camera: position, look at, up vector, FOV, aspect ratio.
    build: main.cpp
    run: cmake-build/raytracer.exe >image.ppm
    open: image.ppm for final render.
    

This repo is based off of Peter Shirley's amazing book (RT in one Weekend).

latest render: 
<p align="center">
  <img src="Assets/rt_test.png" alt="drawing" width="600"/>
</p>

## Next milestones:

 -   Adding lights, triangles, etc.
 - Add multi-threading or use DirectX/CUDA
 - Add GUI

