/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:56:04 by meldora           #+#    #+#             */
/*   Updated: 2020/12/14 12:55:56 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hash(const char *res, t_fsi *interface)
{
	if (!ft_strcmp(res, "0") || res[0] == '\0')
		return ;
	if (interface->type == 'x')
		ft_putstr("0x");
	else if (interface->type == 'X')
		ft_putstr("0X");
}

static void	ft_process_field(const char *res, t_fsi *interface)
{
	if (!ft_strcmp(res, "0") || res[0] == '\0')
		return ;
	if (interface->field > 0)
		interface->field -= 2;
	else if (interface->field < 0)
		interface->field += 2;
}

static void	ft_display_x_util(const char *res, t_fsi *interface, int len)
{
	if (interface->hash == 1)
		ft_process_field(res, interface);
	if (interface->zero == 1 && interface->prec == 0)
	{
		if (interface->hash == 1)
			ft_put_hash(res, interface);
		ft_display_zero(*interface, len, 0);
	}
	else
	{
		ft_display_nonzero(*interface, len, 0);
		if (interface->hash == 1)
			ft_put_hash(res, interface);
	}
}

void		ft_display_x(const char *res, t_fsi *interface)
{
	int i;
	int len;

	if (interface->null_prec == 1)
	{
		interface->zero = 0;
		if (!ft_strcmp(res, "0"))
			ft_bzero((char *)res, ft_strlen(res));
	}
	len = ft_strlen(res);
	ft_display_x_util(res, interface, len);
	i = interface->prec;
	while (--i >= len)
		ft_putchar('0');
	ft_putstr(res);
	i = interface->field;
	while (++i <= -len && -(interface->prec) >= i)
		ft_putchar(' ');
}
