#ifndef RAY_H
#define RAY_H

#include "vector.h"

class Ray {
    public:
        Vec3 origin, dir;
        Vec3 color;

        ray(const Vec3& o, const Vec3& d) {
            origin = o;
            dir = d;
            color = Vec3<float, 3>::new(0.0, 0.0, 0.0);
        }

        point3 at(float t) {
            return origin + t * dir;
        }

};

#endif