#include "../include/types.h"
#include "../include/utils.h"

int getStringLen(union argType arg) {
	return ft_strlen(arg.s);
}

int getNumLen(union argType arg) {
	int len = !arg.i;
	while (arg.i) {
		++len;
		arg.i /= 10;
	}
	return len;
}
