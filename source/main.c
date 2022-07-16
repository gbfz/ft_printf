#include "../include/ft_printf.h"
#include <stdio.h>

static int writeWrapper(union argType arg) {
	return write(1, &arg.c, 1);
}

static struct Token fmtCharToken(const char* fmt) {
	return (struct Token) {
		.print = writeWrapper,
		.arg.c = *fmt,
		.format.type = noFormat,
		.format.len = 0,
	};
}

static int repl(const char*, va_list);
static int replTail(const struct Token token,
					const char* fmt,
					va_list args)
{
	const int written = token.print(token.arg);
	const int tail_written = repl(fmt + token.format.len + 1, args);

	if (tail_written == -1)
		return -1;
	return written + tail_written;
}

static int repl(const char* fmt, va_list args)
{
	if (!fmt || !*fmt)
		return 0;
	if (*fmt == '%')
	{
		struct Token token = getToken(fmt, args);
		if (token.format.type == formatError)
			return -1;
		return replTail(token, fmt, args);
	}
	return replTail(fmtCharToken(fmt), fmt, args);
}

int ft_printf(const char* fmt, ...) {
	va_list argList;
	va_start(argList, fmt);
	int retNum = repl(fmt, argList);
	va_end(argList);
	return retNum;
}

void test1() {
	printf("% -10.8d|\n", 42);
	printf("|%20.40s|\n", "abcdefghijklmnopqrstuvwxyz");
	ft_printf("%#020.7x");
	ft_printf("%e");
	ft_printf("%c %# -010.3s %c\n", 'a', "=)", 'b');
	printf("%p\n", &ft_printf);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%0-10.1d\n", -42);
	ft_printf("%d\n", -2147483648);
	ft_printf(" == %d\n", ft_printf("%d", -2147483649));
	ft_printf("%d\n", 0);
	ft_printf("%x\n", 64206);
	ft_printf("%%\n");
	ft_printf("%s\n", "aboba");
	ft_printf(" == %d\n", ft_printf("%s", "aboba weird"));
}

void test2() {
	int i = printf("darling\n");
	printf("i = %d\n", i);
	// int i = ft_printf("%%%%%\n");
	// printf("i = %d\n", i);
	// i = ft_printf("%s\n", "aboba");
	// ft_printf(" wow%c", '\n');
	i = ft_printf("that's all %sgood:) %d %s\n", "very ", 420, ":D");
	printf("i = %d\n", i);
}

int main() {
	test2();
}
