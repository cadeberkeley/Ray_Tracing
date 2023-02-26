#include "color.h"
#include "Vec3.h"

#include <iostream>
#include <fstream>

#include <iterator>
#include <list>
using namespace std;

// Store list of objects
// Sort from z least to greatest (closest to camera to furthest from camera)
// iterate thru each pixel and trace ray from origin = camera_pos, dir = unit vector of pixel vector - camera vector


int main() {
    const auto ASPECT_RATIO = 16.0/9.0;
    const int IMG_WIDTH  = 400;
    const int IMG_HEIGHT = static_cast<int>(IMG_WIDTH / ASPECT_RATIO);

    // Camera

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = Vec3(viewport_width, 0, 0);
    auto vertical = Vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3(0, 0, focal_length);

    // Output file setup
    ofstream img_file;
    img_file.open("Ray_Trace.ppm");
    img_file << "P3\n" << IMG_WIDTH << ' ' << IMG_HEIGHT << "\n255\n";

    // Scene Setup
    list<SceneObject> scene_objs;
    scene_objs.push_front(Sphere);
    list<SceneObject>::iterator obj_iter;

    // Render
    for (int x = 0; x < IMG_WIDTH; x++) {
        cout << "\rScanlines remaining: " << x << ' ' << std::flush;
        for (int y = 0; y < IMG_HEIGHT; y++) {
            ray r(origin, lower_left_corner + Vec3((float) x, (float) y, 0.0))
            for (obj_iter = scene_objs.begin(); obj_iter != scene_objs.end(); ++obj_iter) {

            }
            color px_color(float(x)/(IMG_WIDTH - 1), float(y)/(IMG_HEIGHT - 1), 0.25);
            write_color(img_file, px_color);
        }
    }

    img_file.close();

    return 0;
}