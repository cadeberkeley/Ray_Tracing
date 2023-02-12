#include "vector.h"


int main() {
	float v1_arr[3] = {1.0, 2.0, 3.0};
	Vector<float, 3> v1(v1_arr);

	float v2_arr[3] = {2.0, 4.0, 6.0};
    Vector<float, 3> v2(v2_arr);

    Vector<float, 3> d1 = v1.normalized();
    std::cout << d1 << std::endl;
}