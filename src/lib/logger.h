#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

enum log_type {
	LOG,
	WARNING,
	ERROR,
};

struct logger {
	int out_fd;
	int err_fd;
};

struct logger logger;

int logger_init();
int logger_log(char *, ...);
int logger_warn(char *, ...);
int logger_error(char *, ...);
int logger_stop();

#endif
