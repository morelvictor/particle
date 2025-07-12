#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "constants.h"

struct app {
	SDL_Window * win;
	SDL_Renderer * rend;
	char running;
	int width, height;
};

struct app * app_init();

int app_run(struct app * app);

int app_free(struct app * app);

#endif
