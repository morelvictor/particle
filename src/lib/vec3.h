#ifndef VEC3_H
#define VEC3_H

#include <math.h>

struct vec3 {
	double x;
	double y;
	double z;
};

struct vec3 vec3_add(struct vec3 a, struct vec3 b);
struct vec3 vec3_scal(struct vec3 a, double k);
struct vec3 vec3_diff(struct vec3 a, struct vec3 b);
double vec3_norm2(struct vec3 a);
double vec3_dist(struct vec3 a, struct vec3 b);
struct vec3 vec3_normalize(struct vec3 a);

#endif
