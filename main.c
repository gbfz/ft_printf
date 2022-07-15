#include "types.h"
#include <stdio.h>

static int repl(const char* fmt, va_list args) {
	if (!*fmt)
		return 0;
	if (*fmt == '%') {
		struct Token token = getToken(fmt, args);
		if (token.format.type == formatError)
			return -1;
		fmt += token.format.len;
		return token.print(token.arg) + repl(fmt + 1, args);
	}
	write(1, fmt, 1);
	return 1 + repl(fmt + 1, args);
}

int ft_printf(const char* fmt, ...) {
	va_list argList;
	va_start(argList, fmt);
	int retNum = repl(fmt, argList);
	va_end(argList);
	return retNum;
}

int main() {
	// printf("% -10.8d|\n", 42);
	// printf("|%20.40s|\n", "abcdefghijklmnopqrstuvwxyz");
	// ft_printf("%#020.7x");
	ft_printf("%%\n");
	ft_printf(" wow\n");
	// ft_printf("%e");
	// ft_printf("%c %# -010.3s %c\n", 'a', "=)", 'b');
	// printf("%p\n", &ft_printf);
	// ft_printf("%p\n", &ft_printf);
	// ft_printf("%0-10.1d\n", -42);
	// ft_printf("%d\n", -2147483648);
	// ft_printf(" == %d\n", ft_printf("%d", -2147483649));
	// ft_printf("%d\n", 0);
	// ft_printf("%x\n", 64206);
	// ft_printf("%%\n");
	// ft_printf("%s\n", "aboba");
	// ft_printf(" == %d\n", ft_printf("%s", "aboba weird"));
	// ft_printf("that's all %sgood:) %d %s\n", "very ", 420, ":D");
}
