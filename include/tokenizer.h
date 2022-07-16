#pragma once
#include "types.h"
#include "utils.h"
#include <stdarg.h>

struct Token getToken(const char* curSymbol, va_list argList);
struct Format parseFormat(const char* fmt);

struct Token getCharToken(struct Format spec, va_list argList);
struct Token getStringToken(struct Format spec, va_list argList);
struct Token getPtrToken(struct Format spec, va_list argList);
struct Token getIntToken(struct Format spec, va_list argList);
struct Token getUIntToken(struct Format spec, va_list argList);
struct Token getLoHexToken(struct Format spec, va_list argList);
struct Token getUpHexToken(struct Format spec, va_list argList);
struct Token getPercentToken();
struct Token getErrorToken();
