/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:35:57 by meldora           #+#    #+#             */
/*   Updated: 2020/12/17 15:28:43 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_0x(const char **res)
{
	ft_putchar((*res)[0]);
	ft_putchar((*res)[1]);
	*res += 2;
}

void		ft_display_p(const char *res, t_fsi interface)
{
	int len;

	len = ft_strlen(res);
	if (interface.null_prec == 1 && ft_strcmp(res, "0x0") == 0)
	{
		((char *)res)[2] = '\0';
		len--;
	}
	if (interface.zero == 1)
	{
		ft_display_0x(&res);
		ft_display_zero(interface, len, 0);
	}
	else
	{
		ft_display_nonzero(interface, len, 0);
		ft_display_0x(&res);
	}
	ft_putstr(res);
	ft_display_right_offset(len, 0, interface);
}
