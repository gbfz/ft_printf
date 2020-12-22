/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:02:23 by meldora           #+#    #+#             */
/*   Updated: 2020/12/19 17:26:28 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_s(const char *res, t_fsi interface)
{
	int	len;
	int	i;

	if (interface.null_prec == 1)
		ft_bzero((char *)res, ft_strlen(res));
	len = ft_strlen(res);
	if (!interface.prec)
		interface.prec = len;
	if (interface.prec && interface.prec < len)
		len = interface.prec;
	while (--interface.field >= len)
		ft_putchar(' ');
	i = 0;
	while (i < len && i < interface.prec && res[i])
		ft_putchar(res[i++]);
	while (++interface.field < -len)
		ft_putchar(' ');
}

void		ft_display_c(const char *res, t_fsi interface)
{
	while (--interface.field >= 1)
		ft_putchar(' ');
	ft_putchar(res[0]);
	while (++interface.field <= -2)
		ft_putchar(' ');
}

void		ft_display_arg(const char *res, t_fsi *interface)
{
	if (interface->prec < 0)
		interface->prec = 0;
	if (res == NULL)
		ft_display_s("\0", *interface);
	if (interface->type == 's')
		ft_display_s(res, *interface);
	else if (interface->type == 'c')
		ft_display_c(res, *interface);
	else if (interface->type == 'd' || interface->type == 'i' || \
			interface->type == 'u' || interface->type == '%')
		ft_display_d(res, *interface);
	else if (interface->type == 'p')
		ft_display_p(res, *interface);
	else if (interface->type == 'x' || interface->type == 'X')
		ft_display_x(res, interface);
}
