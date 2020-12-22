/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:27:42 by meldora           #+#    #+#             */
/*   Updated: 2020/12/20 13:21:41 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_fsi
{
	unsigned char	type;
	char			*int_types;
	char			*oth_types;
	int				field;
	int				prec;
	short			null_prec;
	short			zero;
	short			hash;
	short			space;
	short			plus;
	unsigned int	fslen;
}					t_fsi;

int					ft_printf(const char *fmt, ...);
t_fsi				*ft_create_interface(void);
void				ft_destroy_interface(t_fsi *interface);
int					ft_cleanup(char **res, t_fsi **interface, \
					va_list ap, int c);
int					ft_process_fmt(const char *fmt, \
					t_fsi *interface, va_list ap);
void				ft_putstr(const char *s);
char				ft_putcstr(const char **fmt, int *len);
void				ft_putchar(int c);
char				*ft_convert_arg(t_fsi *interface, va_list ap);
char				*ft_string(va_list ap);
char				*ft_ctoa(int arg);
char				*ft_ptoa(size_t arg);
char				*ft_utoa(unsigned int n);
char				*ft_hextoa(size_t n);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_display_arg(const char *res, t_fsi *interface);
void				ft_display_s(const char *res, t_fsi interface);
void				ft_display_c(const char *res, t_fsi interface);
void				ft_display_d(const char *res, t_fsi interface);
void				ft_display_x(const char *res, t_fsi *interface);
void				ft_display_p(const char *res, t_fsi interface);
void				ft_display_zero(t_fsi interface, int len, int sign);
void				ft_display_nonzero(t_fsi interface, int len, int sign);
void				ft_display_right_offset(int len, int offset, \
					t_fsi interface);
int					ft_lencheck(const char *res, t_fsi *interface);

#endif
