#include "vector.h"

int main() {
	Vector<float> v1(3);
    v1.x = 1.0;
    v1.y = 2.0;
    v1.z = 3.0;

    Vector<float> v2(3);
    v2.x = 2.0;
    v2.y = 4.0;
    v2.z = 6.0;

    Vector<float> v3 = v1 + v2;

    std::cout << v1;
    std::cout << v2;
    std::cout << v3;
    std::cout << v1;
    std::cout << v2;

    v1 += v2;
    std::cout << v1;
    std::cout << v2;
}