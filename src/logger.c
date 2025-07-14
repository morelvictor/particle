#include "logger.h"

extern struct logger logger;

int logger_init() {
	logger.out_fd = 1;
	logger.err_fd = 2;
	return 0;
}

int logger_log(char * msg) {
	dprintf(logger.out_fd, "LOG: 		%s\n", msg);
	return 0;
}

int logger_warn(char * msg) {
	dprintf(logger.err_fd, "WARNING: 		%s\n", msg);
	return 0;
}

int logger_error(char * msg) {
	dprintf(logger.err_fd, "ERROR: 		%s\n", msg);
	return 0;
}

int logger_stop() {
	if(logger.out_fd != 0 && logger.out_fd != 1 && logger.out_fd != 2) {
		close(logger.out_fd);
	}

	if(logger.err_fd != 0 && logger.err_fd != 1 && logger.err_fd != 2) {
		close(logger.err_fd);
	}
	return 0;
}

