#include <stdio.h>
#include "app.h"
#include "lib/logger.h"

int main() {
	logger_init();
	struct app * app = app_init();
	app_run(app);
	app_free(app);

	logger_stop();
	return 0;
}
