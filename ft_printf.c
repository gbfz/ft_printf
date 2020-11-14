/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:58:07 by meldora           #+#    #+#             */
/*   Updated: 2020/11/14 18:08:45 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

int				main(void)
{
	//ft_printf("\n---------------------------------------------------------------------------------\n\n");
	/*
	char	a[] = "this is a string";
	char	b[] = "this is another string";
	int		itogo;

	itogo = ft_printf("Privet\n%s\nalso %s\n%d\n\n%d", a, b, 42, -100);
	ft_printf("Symbols printed: %d\n\n", itogo);
	ft_printf("lmao\n\n");
	//printf("%kol\n"); // не должен работать
	ft_printf("%kol\n");// не должен ничего печатать
	printf("Correct: %%%%%%%%%%s\n");
	ft_printf("   Mine: %%%%%%%%%%s\n");
	printf("Correct: %%%%%%%%%s\n", "watch this");
	ft_printf("   Mine: %%%%%%%%%s\n", "watch this");
	char	*c = a;
	printf("Correct: %p\n", c);
	ft_printf("   Mine: %p\n", c);
	int		d = 64206;
	printf("Correct: %X\n", d);
	ft_printf("   Mine: %X\n", d);
	printf("Correct: %i\n", -2147483647);
	ft_printf("   Mine: %i\n", -2147483647); // не ломается при выходе
											 // за границы инта
	printf("Correct: I'm not 100%% sure I did everthing correctly\n");
	ft_printf("   Mine: I'm not 100%% sure I did everthing correctly\n");
	printf("Correct: %p\n", "0");
	ft_printf("   Mine: %p\n", "0");
	printf("Correct: %d\n", 420 + 69);
	ft_printf("   Mine: %d\n", 420 + 69);
	printf("Correct: %x\n", ft_strcmp(a, b));
	ft_printf("   Mine: %x\n", ft_strcmp(a, b));
	ft_printf("%e", "zhest'"); // не должен ничего печатать
	ft_printf(" Should print '10': %d\n\n", ft_printf("0123456789"));
	char	e[] = "moving forward";
	ft_printf("Correct:\n");
	itogo = printf("The string is '%s', its address is %p, its length is %d\n", e, e, ft_strintlen(e)); // тут %lu, там %d
	printf("The function above printed %d characters\n \
			and that number is %x in hex\n", itogo, itogo);
	ft_printf("Mine:\n");
	itogo = ft_printf("The string is '%s', its address is %p, its length is %d\n", e, e, ft_strintlen(e));
	ft_printf("The function above printed %d characters\n \
			and that number is %x in hex\n", itogo, itogo);
	printf("Correct: %s\n", d > itogo ? "yes" : "no");
	ft_printf("   Mine: %s\n", d > itogo ? "yes" : "no");
	printf("Correct: %.4s\n", "stupid dog");
	ft_printf("   Mine: %.4s\n", "stupid dog");
	printf("Correct: %50s\n", "this is a strobbery");
	ft_printf("   Mine: %50s\n", "this is a strobbery");
	printf("Correct: %50d\n", 400);
	ft_printf("   Mine: %50d\n", 400);
	printf("Correct: %030d\n", 400);
	ft_printf("   Mine: %030d\n", 400);
	char aa[] = "monty python is weird and lovely";
	int  ab	  = 54;
	char ac[] = "but I don't watch it anymore";
	printf("Correct: %40s, now's the time for %-4d, %.13s\n", aa, ab, ac);
	ft_printf("   Mine: %40s, now's the time for %-4d, %.13s\n", aa, ab, ac);
	//printf("Correct: %0-10d\n", 352); // не работает
	ft_printf("   Mine: %0-10dheh\n", 352);
	ft_printf(NULL);
	ft_printf("(null)", (char)0);
	ft_printf("\n");
	//ft_printf("%%");
	void *p;
	char lll[] = "hmmm";
	p = &lll;
	printf(">------------<%2p>-----------<", p);
	printf("\n");
	ft_printf(">------------<%2p>-----------<", p);
	ft_printf("\n");
	char adfda[] = "what the fuck";
	p = &adfda;
	printf("%2p", p);
	printf("\n");
	ft_printf("%2p", p);
	ft_printf("\n");
	char test[] = "haha";
	printf("Correct: %d\n", printf("Address: %39p\n", test));
	ft_printf("   Mine: %d\n", ft_printf("Address: %39p\n", test));
	printf("\nCorrect: %d\n", printf("%30p", (void *)0));
	ft_printf("\n   Mine: %d\n", ft_printf("%30p", (void *)0));
	printf("Correct: %d\n", printf("!%59p!", NULL));
	ft_printf("   Mine: %d\n", ft_printf("!%59p!", NULL));
	char lmao[] = "aaaaa";
	printf("Correct: %-57p|\n", lmao);
	ft_printf("   Mine: %-57p|\n", lmao);
	char boo[] = "bbbb";
	printf("Correct: %46s\n", boo);
	ft_printf("   Mine: %46s\n", boo);
	char h = 'h';
	printf("Correct: %46c\n", h);
	ft_printf("   Mine: %46c\n", h);
	printf("Correct: %40c\n", (char)-116);
	ft_printf("   Mine: %40c\n", (char)-116);
	printf("Correct: %56c\n", (char)0);
	ft_printf("   Mine: %56c\n", (char)0);
	char *t1 = "No fix, no sleep";
	printf(">------------<%20.28s>------------<", t1);
	printf("\n");
	ft_printf(">------------<%20.28s>------------<", t1);
	printf("\n");
	*/
	printf("-%d-", printf("%s", "(null)"));
	printf("\n");
	printf("-%d-", ft_printf("%s", "(null)"));
	printf("\n");
	printf(">----------<%.2s>----------<", NULL);
	printf("\n");
	ft_printf(">----------<%.2s>----------<", NULL);
	printf("\n");
	return (0);
}

p_struct	*ft_create_struct(void)
{
	p_struct	*csi;

	csi = (p_struct *)malloc(sizeof(p_struct));
	if (!csi)
		return (NULL);
	csi->cstype = (char *)malloc(sizeof(char) * 2);
	if (!csi->cstype)
		return (NULL);
	csi->cstype = NULL;
	csi->offset = 0;
	csi->zero = 0;
	csi->prec = 0;
	csi->cslen = 0;
	return (csi);
}

void		ft_destroy_struct(p_struct *csi)
{
	csi->cstype = NULL;
	free(csi->cstype);
	csi->offset = 0;
	csi->zero = 0;
	csi->prec = 0;
	csi->cslen = 0;
	free(csi);
}

int		ft_strintlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		//write(1, &s[i], 1);
		i++;
	}
}

int		ft_check_fmt(const char *fmt, p_struct *csi)
{
	if (*(fmt + csi->cslen) == 'c')
		csi->cstype = "c";
	else if (*(fmt + csi->cslen) == 's')
		csi->cstype = "s";
	else if (*(fmt + csi->cslen) == 'p')
		csi->cstype = "p";
	else if (*(fmt + csi->cslen) == 'd')
		csi->cstype = "d";
	else if (*(fmt + csi->cslen) == 'i')
		csi->cstype = "i";
	else if (*(fmt + csi->cslen) == 'u')
		csi->cstype = "u";
	else if (*(fmt + csi->cslen) == 'x')
		csi->cstype = "x";
	else if (*(fmt + csi->cslen) == 'X')
		csi->cstype = "X";
	if (csi->cstype != NULL)
		return (1);
	return (0);
}

int		ft_fmt_fwd(int fwd)
{
	int i;

	if (fwd < 0)
		fwd *= -1;
	i = 0;
	while (fwd)
	{
		i++;
		fwd /= 10;
	}
	return (i);
}

int		ft_check_flags(const char *fmt, p_struct *csi)
{
	char	*ptr;
	int		dir;

	ptr = (char *)fmt + 1;
	dir = 1;
	while (*ptr == '-' || *ptr == '0')
	{
		if (*ptr == '0')
		{
			csi->zero = 1;
			ptr++;
		}
		if (*ptr == '-')
		{
			csi->zero = 0;
			dir = -1;
			ptr++;
		}
	}
	csi->offset = ft_atoi(ptr) * dir;
	ptr += ft_fmt_fwd(csi->offset);
	if (*ptr == '.')
		csi->prec = ft_atoi(++ptr);
	csi->cslen += ft_fmt_fwd(csi->prec) + ptr - fmt;
	return (ft_check_fmt(fmt, csi));
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putres(const char *res, p_struct *csi)
{
	int i;
	
	while (--csi->offset >= ft_strintlen(res))
		ft_putchar(csi->zero == 0 ? ' ' : '0');
	if (csi->prec)
	{
		while (csi->prec-- > ft_strintlen(res))
			ft_putchar('0');
		i = 0;
		while (i < csi->prec && res[i])
			ft_putchar(res[i++]);
	}
	else
		ft_putstr(res);
	while (++csi->offset < 0 && -(csi->offset) > ft_strintlen(res))
		ft_putchar(' ');
}

char	*ft_ctostr(int arg)
{
	char *res;

	res = (char *)malloc(sizeof(char) * 2);
	if (!res)
		return (NULL);
	res[0] = arg;
	res[1] = '\0';
	return (res);
}

int		ft_printf(const char *fmt, ...)
{
	va_list			ap;
	p_struct		*csi;
	char			*res;
	unsigned int	len;
	int				i;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (!(csi = ft_create_struct()))
			return (0);
		while (*fmt != '%' && *fmt)
		{
			ft_putchar(*fmt++);
			len++;
		}
		if (*fmt == '%')
		{
			while (*(fmt + 1) == '%')
			{
				ft_putchar('%');
				fmt += 2;
				len += 2;
			}
			if (*fmt != '%')
				continue ;
			if (!ft_check_flags(fmt, csi))
				return (len);
			fmt += csi->cslen + 1;
			if (!ft_strcmp(csi->cstype, "c"))
				res = ft_ctostr(va_arg(ap, int));
			else
				res = ft_conversion_interface(csi->cstype, va_arg(ap, void *));
			if (!res)
			{
				res = (char *)malloc(sizeof(char) * 7);
				ft_strlcpy(res, "(null)", 7);
			}
			i = csi->offset >= 0 ? csi->offset : -(csi->offset);
			len += ft_strintlen(res) >= i ? ft_strintlen(res) : i;
			ft_putres(res, csi);
			//free(res);
			ft_destroy_struct(csi);
		}
	}
	return (len);
}
