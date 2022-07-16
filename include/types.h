#pragma once
#include <unistd.h>

enum formatType
{
	Char,
	String,
	Ptr,
	Int,
	UInt,
	LoHex,
	UpHex,
	Percent,
	formatError,
	noFormat,
};

enum fmtFlags
{
	noFlags = 0,
	Zero = (1 << 0),
	Hash = (1 << 1),
	Space = (1 << 2),
	Minus = (1 << 3),
	flagError = (1 << 4)
};

union argType
{
	char			c;
	char*			s;
	int				i;
	unsigned long	u;
};

struct Flags
{
	int				len;
	enum fmtFlags	value;
};

struct Fields
{
	int	len;
	int	width;
	int	precision;
};

struct Format
{
	int				len;
	struct Flags	flags;
	struct Fields	fields;
	enum formatType	type;
};

struct Token
{
	struct Format	format;
	union argType	arg;
	int				(*print)(union argType);
};
