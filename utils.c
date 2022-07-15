#include "types.h"

size_t ft_strlen(const char* s) {
	if (!s || !*s)
		return (0);
	return 1 + ft_strlen(s + 1);
}

void ft_memset(void* p, unsigned char c, size_t n) {
	if (n == 0)
		return;
	((unsigned char*)p)[n - 1] = c;
	ft_memset(p, c, n - 1);
}

char* ft_strchr(const char* s, int c) {
	if (!s || (!*s && c != '\0'))
		return NULL;
	if (*s == c)
		return (char*)s;
	return ft_strchr(s + 1, c);
}

int ft_isdigit(int c) {
	return '0' <= c && c <= '9';
}

int is_dot(int c) {
	return c == '.';
}

int printNumBase(unsigned long n, const char* base, int len, int wr) {
	if (n >= 10)
		wr += printNumBase(n / len, base, len, wr);
	return wr + write(1, &base[n % len], 1);
}

int ft_atoi_diminished(const char* s, int* len) {
	if (!s)
		return 0;
	int i = 0;
	while (*s && ft_isdigit(*s)) {
		i = i * 10 + (*s++ - '0');
		++(*len);
	}
	return i;
}
