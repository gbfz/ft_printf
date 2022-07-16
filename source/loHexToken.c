#include "../include/tokenizer.h"

static int printLoHex(union argType arg) {
	write(1, "0x", 2);
	return printNumBase(arg.u, "0123456789abcdef", 16, 0);
}

struct Token getLoHexToken(struct Format format, va_list argList) {
	struct Token token = {
		.format = format,
		.arg.u = va_arg(argList, unsigned long),
		.print = printLoHex,
	};
	return token;
}
