#include "app.h"

struct app * app_init() {
	struct app * app = malloc(sizeof(struct app));

	app->running = 1;
	if(SDL_Init(SDL_INIT_VIDEO)) {
		perror("Problem at SDL initialisation");
		goto error_handling;
	}

	app->win = SDL_CreateWindow(APP_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DFL_WIN_WIDTH, DFL_WIN_HEIGHT, 0);
	if (!app->win) {
		perror("Problem at window creation");
		goto error_handling;
	}

	app->rend = SDL_CreateRenderer(app->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!app->rend) {
		perror("Problem at renderer creation");
		goto error_handling;
	}

	SDL_GetWindowSize(app->win, &app->width, &app->height);

	return app;

error_handling:
	free(app);
	exit(1);
}

int app_run(struct app * app) {
	while(app->running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					app->running = 0;
					break;
				default: break;
			}
		}
	}
	return 0;
}

int app_free(struct app * app) {
	
	free(app);
	return 0;
}

