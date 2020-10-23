#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "wrapper.h"

void method_a(unsigned long count) {
    clock_t t = clock();
    V3d c;
    V3d d = v3d_create(0.0, 0.0, 0.0);

    for (size_t i = 0; i < count; i++)
    {
        V3d a = v3d_create(1.0, 2.0, 3.0);
        V3d b = v3d_create(1.0, 2.0, 3.0);
        c = v3d_add_a(a, b);
        d.x += c.x;
        d.y += c.y;
        d.z += c.z;
    }

    t = clock() - t;

    printf("%i\n", t);
    printf("%f %f %f\n", d.x, d.y, d.z);
}

void method_b(unsigned long count) {
    clock_t t = clock();
    V3d c;
    V3d d = v3d_create(0.0, 0.0, 0.0);

    for (size_t i = 0; i < count; i++)
    {
        V3d a = v3d_create(1.0, 2.0, 3.0);
        V3d b = v3d_create(1.0, 2.0, 3.0);
        c = v3d_add_b(a, b);
        d.x += c.x;
        d.y += c.y;
        d.z += c.z;
    }

    t = clock() - t;

    printf("%i\n", t);
    printf("%f %f %f\n", d.x, d.y, d.z);
}

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        return 1;
    }

    unsigned long count = strtoul(argv[1], NULL, 0);
    method_a(count);
    method_b(count);

    return 0;
}
