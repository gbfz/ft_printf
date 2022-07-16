#pragma once
#include <stddef.h>

int printNumBase(size_t n, const char* base, int len, int wr);
size_t ft_strlen(const char* s);
char* ft_strchr(const char* s, int c);
void ft_memset(void* p, unsigned char c, size_t n);
int ft_isdigit(int c);
int is_dot(int c);
int ft_atoi_diminished(const char* s, int* len);
