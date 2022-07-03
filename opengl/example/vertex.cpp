#include <iostream>
#include "maths/vertex.h"

using namespace agbr;

int main() {
    std::cout << "text example" << std::endl;

    vtx2u p2 = {1, 2};
    std::cout << p2.x << p2.y << std::endl;
    std::cout << p2.u << p2.v << std::endl;
    std::cout << p2.width << p2.height << std::endl;
    std::cout << p2.of[0] << p2.of[1] << std::endl;

    vtx3i p3 = {1, 2, 3};
    std::cout << p3.x << p3.y << p3.z << std::endl;
    std::cout << p3.u << p3.v << p3.w << std::endl;
    std::cout << p3.of[0] << p3.of[1] << p3.of[2] << std::endl;

    vtx4f p4 = {1.1, -2.2, -3.3, -4.4};
    std::cout << p4.x << p4.y << p4.z << p4.w << std::endl;
    std::cout << p4.r << p4.g << p4.b << p4.a << std::endl;
    return 0;
}
