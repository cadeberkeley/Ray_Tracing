#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include "vector.h"

class Material {
	public:
		Material(float r, float g, float b, float a);
		Material(float r, float g, float b);
		Material(Vec3);

	private:
		float r, g, b, a;
}

#endif