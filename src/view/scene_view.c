#include "scene_view.h"

int particle_draw(SDL_Renderer * rend, struct particle particle) {
	
	filledCircleRGBA(rend, particle.position.x, particle.position.y, particle.radius, particle.color.r, particle.color.g, particle.color.b, particle.color.a);

	return 0;
}


int scene_view_update(struct view * view, double dt) {
	struct scene_view * sv = (struct scene_view *) view;

	particle_all_gravity(sv->particles, sv->particles_size, dt);

	return 0;
}


int scene_view_paint(struct view * view, SDL_Renderer * rend) {
	struct scene_view * sv = (struct scene_view *) view;

	int a = particle_draw(rend, sv->particles[0]);
	int b = particle_draw(rend, sv->particles[1]);

	return a + b;
}

int scene_view_free(struct view * view) {
	return 0;
}

struct scene_view * scene_view_init(struct app * app) {
	struct scene_view * ret = malloc(sizeof(struct scene_view));
	struct view * view = (struct view *) ret;
	view->app = app;
	view->paint = scene_view_paint;
	view->update = NULL;
	view->free = scene_view_free;
	
	ret->particles = malloc(PARTICLES_SIZE * sizeof(struct particle));
	ret->particles_size = PARTICLES_SIZE;

	struct particle * p = ret->particles;

	p[0] = (struct particle)
		{
			(struct vec3) { DFL_WIN_WIDTH / 2 - 50, DFL_WIN_HEIGHT / 2, 0 },
			(struct vec3) { 0, 0, 0 },
			20,
			10,
			(SDL_Color) { 0xff, 0x00, 0x00, 0xff }
		};

	p[1] = (struct particle)
		{
			(struct vec3) { DFL_WIN_WIDTH / 2 + 50, DFL_WIN_HEIGHT / 2, 0 },
			(struct vec3) { 0, 0, 0 },
			20,
			10,
			(SDL_Color) { 0x00, 0xff, 0x00, 0xff }
		};

	return ret;
}

