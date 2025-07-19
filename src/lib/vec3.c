#include "vec3.h"

struct vec3 vec3_add(struct vec3 a, struct vec3 b) {
	return (struct vec3) { a.x + b.x, a.y + b.y, a.z + b.z };
}

struct vec3 vec3_scal(struct vec3 a, double k) {
	return (struct vec3) { a.x * k, a.y * k, a.z * k };
}

struct vec3 vec3_diff(struct vec3 a, struct vec3 b) {
	return vec3_add(a, vec3_scal(b, -1));
}

double vec3_norm2(struct vec3 a) {
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

double vec3_dist(struct vec3 a, struct vec3 b) {
	return vec3_norm2(vec3_diff(a, b));
}

struct vec3 vec3_normalize(struct vec3 a) {
	return vec3_scal(a, vec3_norm2(a));
}

void vec3_pp(struct vec3 a) {
	printf("(%e, %e, %e)\n", a.x, a.y, a.z);
}
