/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_interface.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:12:59 by meldora           #+#    #+#             */
/*   Updated: 2020/11/14 17:10:01 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int		main(void)
{
	char		a[] = "hello";
	char		b 	= 'l';
	int			c	= -1;
	int			d	= c;
	unsigned int e	= 2;
	unsigned int *f	= &e;
	
	printf("        a = %s\n", ft_conversion_interface("s", a));
	printf("        b = %s\n", ft_conversion_interface("c", b));
	printf("        c = %s\n", ft_conversion_interface("d", c));
	printf("        d = %s\n", ft_conversion_interface("i", d));
	printf("        e = %s\n", ft_conversion_interface("u", e));
	printf("Correct f = %p\n", f);
	printf("     My f = %s\n", ft_conversion_interface("p", f));
	printf("Correct g = %x\n", c);
	printf("     My g = %s\n", ft_conversion_interface("x", c));
	printf("Correct h = %X\n", c);
	printf("     My h = %s\n", ft_conversion_interface("X", c));
	printf("Correct h = %X\n", 0);
	printf("     My h = %s\n", ft_conversion_interface("X", 0));
	return (0);
}
*/

#include <stdio.h>

int		ft_nlen(unsigned int n)
{
	int i;

	if (n < 10)
		return (1);
	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char	*res;
	int		len;

	len = ft_nlen(n);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (res);
}

char	*ft_dtohex(size_t n)
{
	char	*res;
	int		i;
	size_t	hex;
	size_t	remainder;
	size_t	divisor;

	i = 0;
	divisor = 1;
	while (divisor < n / 16 && ++i)
		divisor *= 16;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	remainder = n;
	i = 0;
	while (divisor)
	{
		hex = remainder / divisor;
		remainder = n % divisor;
		res[i++] = hex < 10 ? hex + '0' : hex + 87;
		divisor /= 16;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strtoupper(char *s)
{
	size_t i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
	return (s);
}

char	*ft_ptostr(void *arg)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 15);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = 'x';
	res += 2;
	ft_strlcpy(res, ft_dtohex((size_t)arg), 13);
	res -= 2;
	return (res);
}

char	*ft_x_specs(size_t arg)
{
	char	*res;
	size_t	hex;
	size_t	len;
	int		sign;

	sign = 0;
	hex = arg;
	if (hex < 0)
	{
		sign = 1;
		hex *= -1;
	}
	len = ft_strlen(ft_dtohex(hex)) + 1;
	res = (char *)malloc(sizeof(char) * (len + sign + 1));
	if (!res)
		return (NULL);
	res[0] = sign == 0 ? '-' : res[0];
	ft_strlcpy(res, ft_dtohex(hex), len);
	return (res);
}

/*
char	*ft_ctoa(int arg)
{
	char *res;

	res = (char *)malloc(sizeof(char) * 2);
	res[0] = *ft_itoa(arg);
	printf("test1 - %s\n", res);
	if (ft_isprint(res[0]))
		return (res);
	free(res);
	res = (char *)malloc(sizeof(char) * 5);
	res = ft_dtohex(arg);
	ft_bzero(res + 2, 3);
	printf("test2 - %s\n", res);
	return (res);
}
*/

char	*ft_conversion_interface(const char *fmt, const void *arg)
{
	if (!ft_strcmp(fmt, "s"))
		return ((char *)arg);
	/*
	else if (!ft_strcmp(fmt, "c"))
	{
		res = (char *)malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = *(char *)arg;
		return (res);
	}
	*/
	else if (!ft_strcmp(fmt, "d") || !ft_strcmp(fmt, "i"))
		return (ft_itoa((int)arg));
	else if (!ft_strcmp(fmt, "u"))
		return (ft_utoa((unsigned int)arg));
	else if (!ft_strcmp(fmt, "p"))
		return (ft_ptostr((void *)arg));
	else if (!ft_strcmp(fmt, "x"))
		return (ft_x_specs((size_t)arg));
	else if (!ft_strcmp(fmt, "X"))
		return (ft_strtoupper(ft_x_specs((size_t)arg)));
	return (NULL);
}

/*
char	*ft_conversion_interface(const char *fm, ...)
{
	va_list	ap;
	char	*res;

	va_start(ap, fm);
	if (!(ft_strcmp(fm, "s")))
		return (va_arg(ap, char *));
	else if (!(ft_strcmp(fm, "c")))
		//return(ft_ctoa(va_arg(ap, int)));
	{
		//printf("test = %d\n", va_arg(ap, int));
		res = (char *)malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = va_arg(ap, int);
		if (ft_isprint(res[0]))
			return (res);
		//ft_printf("\\x%02x", va_arg(ap, int));
		return (NULL);
	}
	else if (!(ft_strcmp(fm, "d")) || !(ft_strcmp(fm, "i")))
		return (ft_itoa(va_arg(ap, int)));
	else if (!(ft_strcmp(fm, "u")))
		return (ft_utoa(va_arg(ap, unsigned int)));
	else if (!(ft_strcmp(fm, "p")))
		return (ft_ptostr(va_arg(ap, void *)));
	else if (!(ft_strcmp(fm, "x")))
		return (ft_x_specs(va_arg(ap, size_t)));
	else if (!(ft_strcmp(fm, "X")))
		return (ft_strtoupper(ft_x_specs(va_arg(ap, size_t))));
	return (NULL);
}
*/
