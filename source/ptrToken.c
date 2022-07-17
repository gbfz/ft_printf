#include "../include/parser.h"

static int printPtr(union argType arg) {
	write(1, "0x", 2);
	return printNumBase(arg.u, "0123456789abcdef", 16, 0);
}

struct Token getPtrToken(struct Format format, va_list argList) {
	struct Token token = {
		.format = format,
		.arg.u = va_arg(argList, unsigned long),
		.print = printPtr,
	};
	return token;
}

