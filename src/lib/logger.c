#include "logger.h"

/*
 * DEBUG levels
 * 1 errors
 * 2 errors + warnings
 * 3 errors + warnings + infos
 */

extern struct logger logger;


int logger_log(char * fmt, ...) {
#if DEBUG >= 3
	int fd = logger.out_fd;

	va_list args;
	va_start(args, fmt);

	dprintf(fd, "LOG: ");
	int ret = vdprintf(fd, fmt, args);
	dprintf(fd, "\n");

	va_end(args);
	return ret;
#endif
	return 0;
}

int logger_warn(char * fmt, ...) {
#if DEBUG >= 2
	int fd = logger.err_fd;

	va_list args;
	va_start(args, fmt);

	dprintf(fd, "WARNING: ");
	int ret = vdprintf(fd, fmt, args);
	dprintf(fd, "\n");

	va_end(args);
	return ret;

#endif
	return 0;
}

int logger_error(char * fmt, ...) {
#if DEBUG >= 1
	int fd = logger.err_fd;

	va_list args;
	va_start(args, fmt);

	dprintf(fd, "ERROR: ");
	int ret = vdprintf(fd, fmt, args);
	dprintf(fd, "\n");

	va_end(args);
	return ret;

#endif
	return 0;
}
int logger_init() {
	logger.out_fd = 1;
	logger.err_fd = 2;

	logger_log("Logger lib, started !");
	return 0;
}

int logger_stop() {
	logger_log("Logger lib, stopped !");

	if(logger.out_fd != 0 && logger.out_fd != 1 && logger.out_fd != 2) {
		close(logger.out_fd);
	}

	if(logger.err_fd != 0 && logger.err_fd != 1 && logger.err_fd != 2) {
		close(logger.err_fd);
	}
	return 0;
}

