/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:54:26 by meldora           #+#    #+#             */
/*   Updated: 2020/12/17 14:43:28 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_process_flags(int sign, t_fsi *interface)
{
	if ((sign || interface->plus) && interface->field < 0)
		interface->field--;
	if (interface->space)
	{
		if (interface->field > 0)
			interface->field--;
		else if (interface->field < 0)
			interface->field++;
	}
}

static void	ft_check_sign(const char **res, t_fsi *interface, \
		int *sign, int *len)
{
	*sign = 0;
	if (*res[0] == '-')
	{
		*sign = 1;
		(*res)++;
		(*len)--;
		if (interface->space == 1)
		{
			if (interface->field > 0)
				interface->field++;
			else if (interface->field < 0)
				interface->field--;
		}
	}
}

static void	ft_display_sp(t_fsi *interface, int offset)
{
	if (interface->space && offset == 0)
	{
		interface->space--;
		ft_putchar(' ');
	}
}

static void	ft_manage_zero_prec(char *res, t_fsi *interface, int offset)
{
	interface->prec = ft_strlen(res) - offset;
	interface->zero = 0;
	if (!ft_strcmp(res, "0"))
	{
		ft_bzero(res, ft_strlen(res));
		if (interface->field > 0)
			interface->field++;
		else if (interface->field < 0)
			interface->field--;
	}
}

void		ft_display_d(const char *res, t_fsi interface)
{
	int sign;
	int i;
	int len;
	int offset;

	len = ft_strlen(res);
	ft_check_sign(&res, &interface, &sign, &len);
	offset = sign || interface.plus;
	if (interface.null_prec == 1)
		ft_manage_zero_prec((char *)res, &interface, offset);
	ft_process_flags(sign, &interface);
	ft_display_sp(&interface, offset);
	if (interface.zero == 1)
		ft_display_zero(interface, len, sign);
	else
		ft_display_nonzero(interface, len, sign);
	i = interface.prec;
	while (--i >= len)
		ft_putchar('0');
	ft_putstr(res);
	ft_display_right_offset(len, offset, interface);
}
