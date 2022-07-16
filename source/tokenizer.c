#include "../include/tokenizer.h"

typedef struct Token (* tokenCreator )(struct Format, va_list);

static tokenCreator getTokenCreator(enum formatType format)
{
	static tokenCreator tc[8];
	if (tc[format] != NULL)
		return tc[format];
	tc[Char   ] = getCharToken;
	tc[String ] = getStringToken;
	tc[Ptr    ] = getPtrToken;
	tc[Int    ] = getIntToken;
	tc[UInt   ] = getUIntToken;
	tc[LoHex  ] = getLoHexToken;
	tc[UpHex  ] = getUIntToken;
	tc[Percent] = getPercentToken;
	return tc[format];
}

struct Token getToken(const char* fmt, va_list argList)
{
	struct Format format = parseFormat(fmt);
	if (format.type == formatError)
		return getErrorToken();
	tokenCreator createToken = getTokenCreator(format.type);
	if (createToken == NULL)
		return getErrorToken();
	return createToken(format, argList);
}
