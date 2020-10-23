#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <OpenEXR/ImathVec.h>

void method_a(unsigned long count) {
    clock_t t = clock();
    Imath::V3d c;
    Imath::V3d d;

    for (size_t i = 0; i < count; i++)
    {
        Imath::V3d a(1.0, 2.0, 3.0);
        Imath::V3d b(1.0, 2.0, 3.0);
        c = a + b;
        d.x += c.x;
        d.y += c.y;
        d.z += c.z;
    }

    t = clock() - t;

    std::cout << t << std::endl;
    std::cout << d << std::endl;
}

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        return 1;
    }

    unsigned long count = strtoul(argv[1], nullptr, 0);
    method_a(count);

    return 0;
}
