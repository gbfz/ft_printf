#include "parser.h"

static int printString(union argType arg) {
	return write(1, arg.s, ft_strlen(arg.s));
}

struct Token getStringToken(struct Format format, va_list args) {
	struct Token token = {
		.format = format,
		.arg.s = va_arg(args, char*),
		.print = printString
	};
	return token;
}
