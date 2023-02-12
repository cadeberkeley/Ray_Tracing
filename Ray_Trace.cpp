#include "color.h"
#include "vec3.h"

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const auto ASPECT_RATIO = 16.0/9.0;
    const int IMG_WIDTH  = 400;
    const int IMG_HEIGHT = static_cast<int>(IMG_WIDTH / ASPECT_RATIO);

    // Camera

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    ofstream img_file;
    img_file.open("Ray_Trace.ppm");
    img_file << "P3\n" << IMG_WIDTH << ' ' << IMG_HEIGHT << "\n255\n";

    for (int x = 0; x < IMG_WIDTH; x++) {
        cout << "\rScanlines remaining: " << x << ' ' << std::flush;
        for (int y = 0; y < IMG_HEIGHT; y++) {
            ray r(origin, lower)
            color px_color(float(x)/(IMG_WIDTH - 1), float(y)/(IMG_HEIGHT - 1), 0.25);
            write_color(img_file, px_color);
        }
    }

    Vector<float> v1 = new Vector<float>(3);
    v1.x = 1.0;
    v1.y = 2.0;
    v1.z = 3.0;

    Vector<float> v2 = new Vector<float>(3);
    v1.x = 2.0;
    v1.y = 4.0;
    v1.z = 6.0;

    img_file.close();

    return 0;
}