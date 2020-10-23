#include <OpenEXR/ImathVec.h>

#include "wrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

V3d v3d_create(double x, double y, double z) {
    return V3d {x, y, z};
}

V3d v3d_add_a(V3d a, V3d b) {
    return v3d_create(a.x + b.x, a.y + b.y, a.z + b.z);
}

V3d v3d_add_b(V3d a, V3d b) {
    Imath::V3d* cpp_a = reinterpret_cast<Imath::V3d*>(&a);
    Imath::V3d* cpp_b = reinterpret_cast<Imath::V3d*>(&b);
    Imath::V3d cpp_c = *cpp_a + *cpp_b;
    return v3d_create(cpp_c.x, cpp_c.y, cpp_c.z);
}

#ifdef __cplusplus
}
#endif
