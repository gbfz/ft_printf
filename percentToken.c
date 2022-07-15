#include "types.h"

static int printPercent( __attribute__ (( unused )) union argType arg) {
	return write(1, "%", 1);
}

struct Token getPercentToken(struct Format format) {
	struct Token token = {
		.arg.s = NULL,
		.print = printPercent,
		.format = format
	};
	return token;
}
