#include "parser.h"

static struct Flags parseFlags(const char* fmt)
{
	struct Flags flags = {
		.len = 1,
		.value = noFlags
	};
	char c = fmt[1];
	while (c && ft_strchr("# -0", c)) {
		if (c == '0')
			flags.value |= Zero;
		else if (c == '#')
			flags.value |= Hash;
		else if (c == ' ')
			flags.value |= Space;
		else if (c == '-') {
			flags.value ^= Zero;
			flags.value |= Minus;
		}
		else return (struct Flags) { .value = flagError };
		c = fmt[flags.len += 1];
	}
	return flags;
}

static struct Fields parseFields(const char* fmt)
{
	int len = 0;
	int width = ft_atoi_diminished(fmt, &len);
	int precision = 0;
	fmt += len;
	if (*fmt == '.') {
		len += 1;
		precision = ft_atoi_diminished(++fmt, &len);
	}
	return (struct Fields) {
		.len = len,
		.width = width,
		.precision = precision
	};
}

static tokenCreator getTokenCreator(char c)
{
	if (c == 'c')
		return getCharToken;
	if (c == 's')
		return getStringToken;
	if (c == 'p')
		return getPtrToken;
	if (c == 'd' || c == 'i')
		return getIntToken;
	if (c == 'u')
		return getUIntToken;
	if (c == 'x')
		return getLoHexToken;
	if (c == 'X')
		return getUpHexToken;
	if (c == '%')
		return getPercentToken;
	return NULL;
}

static struct Format parseFormat(const char* fmt)
{
	struct Flags flags = parseFlags(fmt);
	if (flags.value == flagError)
		return (struct Format) {};
	struct Fields fields = parseFields(fmt + flags.len);
	int len = fields.len + flags.len;
	tokenCreator creator = getTokenCreator(fmt[len]);
	return (struct Format) {
		.valid = creator != NULL,
		.createToken = creator,
		.fields = fields,
		.flags = flags,
		.len = len,
	};
}

struct Token getToken(const char* fmt, va_list args)
{
	struct Format format = parseFormat(fmt);
	if (!format.valid)
		return (struct Token) {};
	return format.createToken(format, args);
}
