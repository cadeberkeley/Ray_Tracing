#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        point3 origin;
        vec3 dir;

        ray() {}
        ray(const point3& o, const vec3& d) {
            origin = o;
            dir = d;
        }

        point3 at(float t) {
            return origin + t * dir;
        }
};

#endif