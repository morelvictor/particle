#include <stdio.h>
#include "app.h"

int main() {
	struct app * app = app_init();
	app_run(app);
	app_free(app);
	return 0;
}
