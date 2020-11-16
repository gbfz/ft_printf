/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:27:42 by meldora           #+#    #+#             */
/*   Updated: 2020/11/14 17:15:43 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct			s_proc
{
		unsigned int	type;
		unsigned int	typeflag;
		int				field;
		int				prec;
		unsigned int	zero;
		unsigned int	ast;
		unsigned int	hash;
		unsigned int	space;
		unsigned int	plus;
		unsigned int	fmtlen;
}						interface;

typedef struct			s_print
{
		char			*str;
		struct s_print	*next;
}						printlst;

int				ft_printf(const char *fmt, ...);
char			*ft_conversion_interface(interface *fsi, const void *arg);
char			*ft_ctostr(int arg);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_utoa(unsigned int n);
int				ft_nlen(unsigned int n);
char			*ft_dtohex(int n);
char			*ft_strtoupper(char *s);
char			*ft_ptostr(int arg);
char			*ft_x_specs(size_t arg);
void			ft_putstr(const char *s);
void			ft_putchar(int c);
//p_struct		*ft_create_struct(void);
//void			ft_destroy_struct(p_struct *csi);
//int				ft_check_fmt(const char *fmt, p_struct *csi);
//int				ft_check_flags(const char *fmt, p_struct *csi);
//void			ft_process_flags(char *res, p_struct *csi);
//void			ft_putres(const char *res, p_struct *csi);
void			ft_putres(const char *res, interface *fsi);
size_t			ft_strclen(const char *s, char c);
//int				ft_fmt_fwd(int fwd);
size_t			ft_strlen(const char *s);
int				ft_strintlen(const char *s);

#endif
