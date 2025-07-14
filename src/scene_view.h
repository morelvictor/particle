#ifndef SCENE_VIEW_H
#define SCENE_VIEW_H

#include <stdlib.h>
#include <SDL2/SDL.h>

#include "view.h"

struct scene_view {
	struct view * view;
};

struct scene_view * scene_view_init(struct app * app);

#endif
