#include "../include/tokenizer.h"

static int printInt(union argType arg) {
	int i = arg.i;
	if (i == -2147483648)
		return write(1, "-2147483648", 11);
	if (i < 0)
		i *= -1;
	return printNumBase(i, "0123456789", 10, 0);
}

struct Token getIntToken(struct Format format, va_list argList) {
	struct Token token = {
		.format = format,
		.arg.i = va_arg(argList, int),
		.print = printInt,
	};
	return token;
}
