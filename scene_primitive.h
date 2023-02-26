#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include "vector.h"
#include "material.h"
#include <math.h>

#include <iostream>

class SceneObject {
	public:
		virtual float intersect(Ray r);

}

class ScenePrimitive: public SceneObject {

	private:
		//Material material;

}

class Sphere: public ScenePrimitive {
	public:
		Vec3 center;
		float radius;

		Sphere(float r, Vec3 c) {
			radius = r;
			center = c;
		}

		float intersect(&Ray r) {
			Vec3 beta = r.origin + center;
			float beta_len_squared = beta.length_squared();
			float delta_len = r.dir.dot(beta);
			float delta_len_squared = delta_len * delta_len;
			float center_to_delta_squared = beta_len_squared - delta_len_squared
			float delta_to_intersection = sqrt(radius * radius - center_to_delta_squared);

			float t1 = delta_len - delta_to_intersection;
			float t2 = delta_len + delta_to_intersection;

			(*r)->color = Vec3<float, 3>::new(1.0, 0.0, 0.0);

			return t1;
		}
}

#endif