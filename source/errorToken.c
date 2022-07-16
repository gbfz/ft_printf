#include "../include/tokenizer.h"

struct Token getErrorToken() {
	return (struct Token) { .format.type = formatError };
}
