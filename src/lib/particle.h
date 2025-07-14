#ifndef PARTICLE_H
#define PARTICLE_H

#include <SDL/SLD2.h>
#include <math.h>
#include "vec3.h"

struct particle {
	struct vec3 position;
	struct vec3 velocity;
	double radius;
	double mass;
	SDL_Color color;
};

void particle_gravity(struct particle * A, struct particle * B, double dt);
void particle_all_gravity(struct particle * T, int size, double dt);

#endif
