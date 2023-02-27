#include "color.h"
#include "vector.h"
//#include "vec3.h"
#include "scene_object.h"
#include "ray.h"

#include <iostream>
#include <fstream>

#include <iterator>
#include <list>
using namespace std;

// Store list of objects
// Sort from z least to greatest (closest to camera to furthest from camera)
// iterate thru each pixel and trace ray from origin = camera_pos, dir = unit vector of pixel vector - camera vector


int main() {
    const float ASPECT_RATIO = 16.0/9.0;
    const int IMG_WIDTH  = 400;
    const int IMG_HEIGHT = static_cast<int>(IMG_WIDTH / ASPECT_RATIO);

    // Camera

    float viewport_height = 2.0;
    float viewport_width = ASPECT_RATIO * viewport_height;
    float focal_length = 5.0;

    Vec3 origin = newVec3(0, 0, 0);
    Vec3 horizontal = newVec3(viewport_width, 0, 0);
    Vec3 vertical = newVec3(0, viewport_height, 0);
    Vec3 lower_left_corner = origin - horizontal/2 - vertical/2 + newVec3(0, 0, focal_length);
    cout << lower_left_corner;

    // Output file setup
    ofstream img_file;
    img_file.open("sphere_tests.ppm");
    img_file << "P3\n" << IMG_WIDTH << ' ' << IMG_HEIGHT << "\n255\n";

    // Scene Setup
    list<SceneObject*> scene_objs;
    scene_objs.push_front(new Sphere(1.0, newVec3(0.0, 0.0, 10.0)));

    // Render
    for (int y = 0; y < IMG_HEIGHT; y++) {
        cout << "\rScanlines remaining: " << y << ' ' << std::flush;
        for (int x = 0; x < IMG_WIDTH; x++) {
            Ray r(origin, lower_left_corner + newVec3({(float) x/IMG_WIDTH * viewport_width, (float) y/IMG_HEIGHT * viewport_height, 0.0}));
            //cout << lower_left_corner + newVec3({(float) x, (float) y, 0.0}) << ", ";
            //cout << r.dir << endl;
            list<SceneObject*>::iterator obj_iter;

            bool intersect = false;

            for (obj_iter = scene_objs.begin(); obj_iter != scene_objs.end(); ++obj_iter) {
                if ((*obj_iter)->intersect(r) > 0) {
                    write_color(img_file, r.color);
                    intersect = true;
                    continue;
                }
            }

            if (intersect) continue;
            Vec3 px_color = newVec3(float(x)/float(IMG_WIDTH - 1), float(y)/float(IMG_HEIGHT - 1), 0.25);

            write_color(img_file, px_color);
        }
    }

    img_file.close();

    return 0;
}