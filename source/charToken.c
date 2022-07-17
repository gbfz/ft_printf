#include "../include/parser.h"

static int printChar(union argType arg)
{
	return write(1, &arg.c, 1);
}

struct Token getCharToken(struct Format format, va_list argList)
{
	struct Token token = {
		.format = format,
		.arg.c = va_arg(argList, int),
		.print = printChar,
	};
	return token;
}
