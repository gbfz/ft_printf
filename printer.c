#include "types.h"

static int printChar(const struct Token* t)
{
	return 0;
}

static int printString(const struct Token* t)
{
	return 0;
}

static int printInt(const struct Token* t)
{
	return 0;
}

static int printUInt(const struct Token* t)
{
	return 0;
}

static int printLoHex(const struct Token* t)
{
	return 0;
}

static int printUpHex(const struct Token* t)
{
	return 0;
}

static int printPercent(const struct Token* t)
{
	return 0;
}

int printToken(const struct Token* token)
{
	switch (token->format.type)
	{
		case Char:	 return printChar	(token);
		case String: return printString	(token);
		case Int:	 return printInt	(token);
		case UInt:	 return printUInt	(token);
		case Ptr:
		case LoHex:	 return printLoHex	(token);
		case UpHex:	 return printUpHex	(token);
		case Percent:return printPercent(token);
		default:	 return -1;
	}
}
