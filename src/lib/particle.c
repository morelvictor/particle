#include "particle.h"


void particle_gravity(struct particle * A, struct particle * B, double dt) {
	double d = vec3_dist(A->position, B->position);
	double mod_grav_force = - G * (B->mass) / (d * d);
	A->velocity = vec3_scal(vec3_add(A->velocity, vec3_scal(vec3_normalize(vec3_diff(B->position, A->position)), mod_grav_force)), dt);
}

void particle_all_gravity(struct particle * T, int size, double dt) {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(i != j) {
				particle_gravity(&T[i], &T[j], dt);
			}
		}
	}
}

