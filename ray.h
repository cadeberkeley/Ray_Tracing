#ifndef RAY_H
#define RAY_H

#include "vector.h"
#include "vec3.h"

class Ray {
    public:
        Vec3 origin, dir;
        Vec3 color;

        Ray(const Vec3& o, const Vec3& d) {
            origin = o;
            dir = (d-o).normalized();
            color = newVec3(0.0, 0.0, 0.0);
        }

        Vec3 at(float t) {
            return origin + t * dir;
        }

};

#endif