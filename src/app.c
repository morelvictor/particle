#include "app.h"

#include <time.h>
#include <stdint.h>

static double now_s(void) {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (double)ts.tv_sec + (double)ts.tv_nsec * 1E-9;
}

struct app * app_init() {
	struct app * app = malloc(sizeof(struct app));

	app->running = 1;
	if(SDL_Init(SDL_INIT_VIDEO)) {
		perror("Problem at SDL initialisation");
		goto error_handling;
	}

	app->win = SDL_CreateWindow(APP_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DFL_WIN_WIDTH, DFL_WIN_HEIGHT, SDL_WINDOW_RESIZABLE);
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

	struct scene_view * scene_view = scene_view_init(app, app->width, app->height);
	app->view = (struct view *) scene_view;

	return app;

error_handling:
	free(app);
	exit(1);
}

int app_run(struct app * app) {
	int fps = 1;
	double dt = 0;
	double last_fps = now_s();
	while(app->running) {
		fps++;
		double start_time = now_s();
		double fps_dt = start_time - last_fps;
		if(fps_dt > 1) {
			last_fps = start_time;
			printf("Fps: %d\n", fps);
			fps = 0;
		}

		SDL_GetWindowSize(app->win, &app->view->width, &app->view->height);

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					app->running = 0;
					break;
				default: break;
			}
			app->view->handle_event(app->view, event);
		}

		SDL_SetRenderDrawColor(app->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(app->rend);
		app->view->update(app->view, dt);
		app->view->paint(app->view, app->rend);
		SDL_RenderPresent(app->rend);

		double end_time = now_s();
		dt = end_time - start_time;
	}
	return 0;
}

int app_free(struct app * app) {
	
	free(app);
	return 0;
}

