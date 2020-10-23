#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    double x;
    double y;
    double z;
} V3d;

V3d v3d_create(double x, double y, double z);
V3d v3d_add_a(V3d a, V3d b);
V3d v3d_add_b(V3d a, V3d b);

#ifdef __cplusplus
}
#endif
