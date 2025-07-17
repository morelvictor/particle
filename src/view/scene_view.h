#ifndef SCENE_VIEW_H
#define SCENE_VIEW_H

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "view.h"
#include "../lib/particle.h"
#include "../lib/vec3.h"
#include "../constants.h"

struct scene_view {
	struct view view;
	struct particle * particles;
	int particles_size;
};

struct scene_view * scene_view_init(struct app * app);

#endif
