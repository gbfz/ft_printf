cmake_minimum_required(VERSION 3.2)

project(ft_printf)

include_directories(../include)

add_executable(ft_printf
	charToken.c
	intToken.c
	#errorToken.c
	loHexToken.c
	parser.c
	percentToken.c
	#printer.c
	ptrToken.c
	stringToken.c
	uintToken.c
	upHexToken.c
	utils.c
	main.c
)
