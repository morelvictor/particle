#include "view.h"

int view_paint(struct view * view, SDL_Renderer * rend) {
	return view->paint(view, rend);
}

int view_update(struct view * view) {
	return view->update(view);
}

int view_free(struct view * view) {
	if (view->free != NULL) {
		int ret = view->free(view);
		free(view);
		logger_warn("View freed");
		return ret;
	}

	/*
	 * Here put generic code to free view
	*/
	return 0;
}
