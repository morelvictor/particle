#include <stdio.h>
#include "app.h"
#include "logger.h"

int main() {
	logger_init();
	logger_log("Logger lib, started !");
	struct app * app = app_init();
	app_run(app);
	app_free(app);

	logger_log("Logger lib, stopped !");
	logger_stop();
	return 0;
}
