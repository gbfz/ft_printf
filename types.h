#pragma once
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h> // :)

#define false 0
#define true  1

union argType {
	char c;
	char* s;
	int i;
	unsigned long u;
};

enum fmtFlags {
	None = 0,
	Zero = (1 << 0),
	Hash = (1 << 1),
	Space = (1 << 2),
	Minus = (1 << 3),
	flagError = (1 << 4)
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

enum formatType {
	Char,
	String,
	Ptr,
	Int,
	UInt,
	LoHex,
	UpHex,
	Percent,
	formatError
};

struct Format {
	int len;
	struct Flags flags;
	struct Fields fields;
	enum formatType type;
};

struct Token {
	struct Format format;
	union argType arg;
	int (*print)(union argType);
};

struct Token getToken(const char* curSymbol, va_list argList);

struct Token getCharToken(struct Format spec, va_list argList);
struct Token getStringToken(struct Format spec, va_list argList);
struct Token getPtrToken(struct Format spec, va_list argList);
struct Token getIntToken(struct Format spec, va_list argList);
struct Token getUIntToken(struct Format spec, va_list argList);
struct Token getLoHexToken(struct Format spec, va_list argList);
struct Token getUpHexToken(struct Format spec, va_list argList);
struct Token getPercentToken();
struct Token getErrorToken();

struct Format parseFormat(const char* fmt);

int getStringLen(union argType arg);
int getNumLen(union argType arg);

int printNumBase(size_t n, const char* base, int len, int wr);
size_t ft_strlen(const char* s);
char* ft_strchr(const char* s, int c);
void ft_memset(void* p, unsigned char c, size_t n);
int ft_isdigit(int c);
int is_dot(int c);
int ft_atoi_diminished(const char* s, int* len);
