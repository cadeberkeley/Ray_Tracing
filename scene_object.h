#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include "vector.h"
#include "material.h"
#include "ray.h"

#include <math.h>

#include <iostream>

class SceneObject {
	public:
		SceneObject() {}
		virtual float intersect(Ray& r) = 0;

};

class ScenePrimitive: public SceneObject {

	private:
		//Material material;

};

class Sphere: public ScenePrimitive {
	public:
		Vec3 center;
		float radius;

		Sphere() {
			radius = 1.0;
			center = newVec3(0.0, 0.0, 0.0);
		}

		Sphere(float r, Vec3 c) {
			radius = r;
			center = c;
		}

		virtual float intersect(Ray& r) override {
			Vec3 beta = r.origin + center;
			//std::cout << r.dir << std::endl;
			//std::cout << beta << std::endl;

			float beta_len_squared = beta.length_squared();
			float delta_len = beta.dot(r.dir);
			//std::cout << delta_len << std::endl;


			if (delta_len < 0) {
				return -1;
			}

			float delta_len_squared = delta_len * delta_len;
			float center_to_delta_squared = beta_len_squared - delta_len_squared;
			if (center_to_delta_squared > radius * radius) return -1;
			float delta_to_intersection = sqrt(radius * radius - center_to_delta_squared);

			float t1 = delta_len - delta_to_intersection;
			float t2 = delta_len + delta_to_intersection;

			r.color = newVec3(1.0, 0.0, 0.0);


			return t1;
		}
};

#endif