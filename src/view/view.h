#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include "../lib/logger.h"

struct view {
	struct app * app;
	int (* paint) (struct view * view, SDL_Renderer * rend);
	int (* update) (struct view * view);
	int (* free) (struct view * view);
};

int view_paint(struct view * view, SDL_Renderer * rend);

int view_update(struct view * view);

int view_free(struct view * view);

#endif
