#include "../include/parser.h"

static int printPercent( __attribute__ (( unused )) union argType arg) {
	return write(1, "%", 1);
}

struct Token getPercentToken(struct Format format, va_list args) {
	(void)args;
	return (struct Token) {
		.arg.s = NULL,
		.print = printPercent,
		.format = format
	};
}
