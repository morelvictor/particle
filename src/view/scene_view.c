#include "scene_view.h"


int particle_draw(SDL_Renderer * rend, struct particle particle, struct vec3 offset, double scale) {
	
	filledCircleRGBA(rend, particle.position.x * (scale/100) + offset.x, particle.position.y  * (scale/100) + offset.y, particle.radius * (scale/100), particle.color.r, particle.color.g, particle.color.b, particle.color.a);

	return 0;
}


int scene_view_update(struct view * view, double dt) {
	struct scene_view * sv = (struct scene_view *) view;

	sv->center = (struct vec3) { 0, 0, 0 };
	particle_all_gravity(sv->particles, sv->particles_size, dt);
	for(int i = 0; i < sv->particles_size; i++) {
		sv->particles[i].position = vec3_add(sv->particles[i].position, sv->particles[i].velocity);
		sv->center = vec3_add(sv->center, vec3_scal(sv->particles[i].position, -1));
	}

	sv->center = vec3_scal(sv->center, sv->scale/((double) sv->particles_size * 100));

	sv->center.x += view->width / 2;
	sv->center.y += view->height / 2;
	
	return 0;
}


int scene_view_paint(struct view * view, SDL_Renderer * rend) {
	struct scene_view * sv = (struct scene_view *) view;

	int acc = 0;
	for(int i = 0; i < sv->particles_size; i++) {
		acc += particle_draw(rend, sv->particles[i], sv->center, sv->scale);
	}
	
	filledCircleRGBA(rend, sv->center.x, sv->center.y, 1, 0xff, 0, 0, 0xff);

	return acc;
}


int scene_view_handle_event(struct view * view, SDL_Event event) {
	struct scene_view * sv = (struct scene_view *) view;
	switch(event.type) {
		case SDL_MOUSEWHEEL:
			{
				SDL_MouseWheelEvent mouse_wheel_event = event.wheel;
				sv->scale += SCROLL_SPEED * mouse_wheel_event.y;
				if(sv->scale < 0) {
					sv->scale -= SCROLL_SPEED * mouse_wheel_event.y;
				}
				break;
			}
		default:
			break;
	}
	return 0;
}

int scene_view_free(struct view * view) {
	return 0;
}

int random_int_between(int min, int max) {

    if (min > max) {
        int tmp = min;
        min = max;
        max = tmp;
    }

    double scale = rand() / (RAND_MAX + 1.0);
    return min + (int)(scale * (max - min + 1));
}

struct vec3 vec3_random(int x_min, int x_max, int y_min, int y_max, int z_min, int z_max) {
	struct vec3 ret = { (double) random_int_between(x_min, x_max), (double) random_int_between(y_min, y_max), (double) random_int_between(z_min, z_max) };

	return ret;
}

struct particle particle_random(int x_min, int x_max, int y_min, int y_max, int z_min, int z_max) {
	struct particle ret = {
			.position = vec3_random(x_min, x_max, y_min, y_max, z_min, z_max),
			.velocity = (struct vec3) { 0, 0, 0 },
			.radius = 10,
			.mass = pow(10.0, random_int_between(5, 8)),
			.color = (SDL_Color) { 0xff, 0xff, 0xff, 0xff }
		};

	return ret;
}

struct scene_view * scene_view_init(struct app * app, int width, int height) {
	srand(1);
	struct scene_view * ret = malloc(sizeof(struct scene_view));
	struct view * view = (struct view *) ret;
	view->app = app;
	view->paint = scene_view_paint;
	view->update = scene_view_update;
	view->free = scene_view_free;
	view->handle_event = scene_view_handle_event;
	
	ret->particles = malloc(PARTICLES_SIZE * sizeof(struct particle));
	ret->particles_size = PARTICLES_SIZE;
	ret->center = (struct vec3) { 0, 0, 0 };
	ret->scale = 100;

	struct particle * p = ret->particles;

	for(int i = 0; i < ret->particles_size; i++) {
		p[i] = particle_random(- width / 2, width / 2, - height / 2, height / 2, 0, 0);
	}

	return ret;
}

