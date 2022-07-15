#include "types.h"

struct Token getErrorToken() {
	return (struct Token) { .format.type = formatError };
}
