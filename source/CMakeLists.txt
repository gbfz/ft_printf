cmake_minimum_required(VERSION 3.2)
project(ft_printf)
add_executable(ft_printf
	charToken.c
	errorToken.c
	intToken.c
	loHexToken.c
	parser.c
	percentToken.c
	printer.c
	ptrToken.c
	stringToken.c
	tokenizer.c
	uintToken.c
	upHexToken.c
	utils.c
	main.c
)
