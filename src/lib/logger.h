#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <unistd.h>

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
int logger_log(char * msg);
int logger_warn(char * msg);
int logger_error(char * msg);
int logger_stop();

#endif
