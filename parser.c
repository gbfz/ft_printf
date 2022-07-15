#include "types.h"

static struct Flags parseFlags(const char* fmt)
{
	struct Flags flags = {
		.len = 1,
		.value = None
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

enum formatType getFormatType(char c)
{
	if (c == 'c')
		return Char;
	if (c == 's')
		return String;
	if (c == 'p')
		return Ptr;
	if (c == 'd' || c == 'i')
		return Int;
	if (c == 'u')
		return UInt;
	if (c == 'x')
		return LoHex;
	if (c == 'X')
		return UpHex;
	if (c == '%')
		return Percent;
	return formatError;
}

struct Format parseFormat(const char* fmt)
{
	struct Format format = {
		.type = formatError
	};
	struct Flags flags = parseFlags(fmt);
	if (flags.value == flagError)
		return format;
	struct Fields fields = parseFields(fmt + flags.len);
	int len = fields.len + flags.len;
	return (struct Format) {
		.flags = flags,
		.fields = fields,
		.len = len,
		.type = getFormatType(fmt[len])
	};
}
