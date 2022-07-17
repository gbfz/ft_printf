#pragma once
#include <stdarg.h>
#include <unistd.h>

enum formatType {
	noFormat,
	Char,
	String,
	Ptr,
	Int,
	UInt,
	LoHex,
	UpHex,
	Percent,
	formatError,
};

enum fmtFlags {
	noFlags,
	Zero = (1 << 0),
	Hash = (1 << 1),
	Space = (1 << 2),
	Minus = (1 << 3),
	flagError = (1 << 4)
};

enum Valid {
	No,
	Yes
};

union argType {
	char c;
	char* s;
	int i;
	unsigned long u;
};

struct Flags {
	int len;
	enum fmtFlags value;
};

struct Fields {
	int len;
	int width;
	int precision;
};

struct Format {
	int len;
	enum Valid valid;
	struct Flags flags;
	struct Fields fields;
	struct Token (*createToken)(struct Format, va_list);
};

struct Token {
	struct Format format;
	union argType arg;
	int (*print)(union argType);
};
