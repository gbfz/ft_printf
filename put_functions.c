/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:18:24 by meldora           #+#    #+#             */
/*   Updated: 2020/12/06 15:56:43 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	ft_putcstr(const char **fmt, int *len)
{
	while (*(*fmt) != '%' && *(*fmt) != '\0')
	{
		ft_putchar(*(*fmt));
		(*fmt)++;
		(*len)++;
	}
	return (*(*fmt));
}
