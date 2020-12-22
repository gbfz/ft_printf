/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_offset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 08:52:35 by meldora           #+#    #+#             */
/*   Updated: 2020/12/17 14:53:28 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_nonzero(t_fsi interface, int len, int sign)
{
	int offset;

	offset = sign || interface.plus;
	while (interface.field > len + offset \
			&& interface.field > interface.prec + offset)
	{
		ft_putchar(' ');
		interface.field--;
	}
	if (sign == 1)
	{
		interface.plus--;
		ft_putchar('-');
	}
	else if (interface.plus == 1)
		ft_putchar('+');
}

void	ft_display_zero(t_fsi interface, int len, int sign)
{
	int offset;

	offset = sign || interface.plus;
	while (interface.prec && interface.field > len + offset && \
			interface.field > interface.prec + offset)
	{
		ft_putchar(' ');
		interface.field--;
	}
	if (sign || interface.plus)
		interface.prec++;
	if (sign == 1)
	{
		interface.plus--;
		ft_putchar('-');
	}
	else if (interface.plus == 1)
		ft_putchar('+');
	while (interface.field > len + offset && \
			interface.field > interface.prec + offset)
	{
		ft_putchar('0');
		interface.field--;
	}
}

void	ft_display_right_offset(int len, int offset, t_fsi interface)
{
	while (++interface.field + offset <= -len - offset \
			&& -interface.prec - offset >= interface.field + offset)
		ft_putchar(' ');
	if (interface.space && offset == 0)
		ft_putchar(' ');
}
