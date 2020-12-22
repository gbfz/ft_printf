# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meldora <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 15:20:57 by meldora           #+#    #+#              #
#    Updated: 2020/12/20 13:16:37 by meldora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c memory_management.c put_functions.c ft_strcmp.c 	   \
			  process_fmt.c ft_utoa.c s_c_conversions.c conversion_interface.c \
			  display_interface.c display_offset.c display_d.c display_x.c	   \
			  display_p.c len_interface.c

OBJS		= $(SRCS:.c=.o)

.c.o:
			@gcc -Wall -Werror -Wextra -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo " === compiled ft_printf files ==="
			@make -C libft
			@echo " === compiled libft files     ==="
			@cp libft/libft.a $(NAME)
			@ar rcs $@ $^
			@echo " === created a library        ==="

clean:
			@rm -rf $(OBJS)
			@echo " === removed ft_printf object files ==="
			@make clean -C libft
			@echo " === removed libft object files     ==="

fclean:		clean
			@rm -rf $(NAME)
			@make fclean -C libft
			@echo " === removed library                ==="

re:			fclean all

.PHONY:		all clean fclean re
