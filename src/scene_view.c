#include "scene_view.h"


int scene_view_paint(struct view * view, SDL_Renderer * rend) {
	SDL_Rect rect = { 10, 10, 100, 50 };
	SDL_SetRenderDrawColor(rend, 255, 255, 0, SDL_ALPHA_OPAQUE);
	return SDL_RenderDrawRect(rend, &rect);
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

	return ret;
}

