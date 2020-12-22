/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_interface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:12:59 by meldora           #+#    #+#             */
/*   Updated: 2020/12/20 13:18:59 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strtoupper(char *res)
{
	unsigned int i;

	if (res == NULL)
		return (NULL);
	i = 0;
	while (res[i])
	{
		res[i] = ft_toupper(res[i]);
		i++;
	}
	return (res);
}

char		*ft_hextoa(size_t n)
{
	char	*res;
	int		i;
	size_t	hex;
	size_t	divisor;

	i = 0;
	divisor = 1;
	while (++i && divisor * 16 < n)
		divisor *= 16;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (divisor)
	{
		hex = n / divisor;
		if (hex < 10)
			res[i++] = hex + '0';
		else
			res[i++] = hex + 87;
		n %= divisor;
		divisor /= 16;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_ptoa(size_t arg)
{
	char	*res;
	char	*tmp;
	int		len;

	tmp = ft_hextoa(arg);
	len = ft_strlen(tmp);
	res = (char *)malloc(sizeof(char) * (len + 3));
	if (res == NULL)
		return (NULL);
	res[0] = '0';
	res[1] = 'x';
	ft_strlcpy(res + 2, tmp, len + 1);
	free(tmp);
	tmp = NULL;
	return (res);
}

char		*ft_convert_arg(t_fsi *interface, va_list ap)
{
	if (interface->type == 's')
		return (ft_string(ap));
	else if (interface->type == 'c')
		return (ft_ctoa(va_arg(ap, int)));
	else if (interface->type == 'd' || interface->type == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (interface->type == 'u')
		return (ft_utoa(va_arg(ap, unsigned int)));
	else if (interface->type == 'p')
		return (ft_ptoa(va_arg(ap, size_t)));
	else if (interface->type == 'x')
		return (ft_hextoa(va_arg(ap, unsigned int)));
	else if (interface->type == 'X')
		return (ft_strtoupper(ft_hextoa(va_arg(ap, unsigned int))));
	else if (interface->type == '%')
		return (ft_strdup("%"));
	return (NULL);
}
