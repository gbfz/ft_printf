#include "../include/tokenizer.h"

static int printUInt(union argType arg) {
	return printNumBase(arg.u, "0123456789", 10, 0);
}

struct Token getUIntToken(struct Format format, va_list argList) {
	struct Token token = {
		.format = format,
		.arg.u = va_arg(argList, unsigned int),
		.print = printUInt,
	};
	return token;
}
