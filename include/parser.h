#pragma once
#include "types.h"
#include "utils.h"
#include <stdarg.h>

struct Token getToken(const char* curSymbol, va_list args);

struct Token getCharToken(struct Format format, va_list args);
struct Token getStringToken(struct Format format, va_list args);
struct Token getPtrToken(struct Format format, va_list args);
struct Token getIntToken(struct Format format, va_list args);
struct Token getUIntToken(struct Format format, va_list args);
struct Token getLoHexToken(struct Format format, va_list args);
struct Token getUpHexToken(struct Format format, va_list args);
struct Token getPercentToken(struct Format format, va_list args);
struct Token getErrorToken( struct Format f, va_list a);

typedef struct Token (*tokenCreator)(struct Format, va_list);
