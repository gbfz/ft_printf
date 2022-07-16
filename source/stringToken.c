#include "../include/tokenizer.h"

static int printString(union argType arg) {
	return write(1, arg.s, ft_strlen(arg.s));
}

struct Token getStringToken(struct Format format, va_list argList) {
	struct Token token = {
		.format = format,
		.arg.s = va_arg(argList, char*),
		.print = printString,
	};
	return token;
}
