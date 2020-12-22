/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:56:36 by meldora           #+#    #+#             */
/*   Updated: 2020/12/14 13:00:35 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_fmt_forward(int arg)
{
	unsigned int len;

	if (arg < 0)
		arg *= -1;
	len = 0;
	while (arg)
	{
		len++;
		arg /= 10;
	}
	return (len);
}

static void			ft_process_flags(const char *fmt, t_fsi *interface)
{
	while (++fmt && ++interface->fslen && \
			(*fmt == '0' || *fmt == '#' || \
			*fmt == ' ' || *fmt == '+' || *fmt == '-'))
	{
		if (*fmt == '0' && interface->field == 1)
			interface->zero = 1;
		if (*fmt == '#')
			interface->hash = 1;
		if (*fmt == ' ')
			interface->space = 1;
		if (*fmt == '+')
			interface->plus = 1;
		if (*fmt == '-')
		{
			interface->zero = 0;
			interface->field = -1;
		}
	}
}

static void			ft_process_field_prec(const char *fmt, t_fsi *interface)
{
	fmt += interface->fslen;
	interface->field *= ft_atoi((char *)fmt);
	fmt += ft_fmt_forward(interface->field);
	interface->fslen += ft_fmt_forward(interface->field);
	if (*fmt == '*')
	{
		fmt++;
		interface->fslen++;
	}
	if (*fmt++ == '.')
	{
		interface->fslen++;
		while (*fmt == '0')
		{
			fmt++;
			interface->fslen++;
		}
		interface->prec = ft_atoi((char *)fmt);
		if (*fmt == '*')
			interface->fslen++;
		interface->fslen += ft_fmt_forward(interface->prec);
		if (interface->prec == 0 && *fmt != '*')
			interface->null_prec = 1;
	}
}

static void			ft_process_star(const char *fmt, \
				t_fsi *interface, va_list ap)
{
	unsigned int i;

	i = 0;
	while (i++ < interface->fslen)
	{
		if (*(fmt + i) == '*' && *(fmt + i - 1) != '.')
		{
			interface->field = va_arg(ap, int);
			if (*(fmt + i - 1) == '-' && interface->field > 0)
				interface->field *= -1;
		}
		if (*(fmt + i) == '*' && *(fmt + i - 1) == '.')
		{
			interface->prec = va_arg(ap, int);
			if (interface->prec == 0)
				interface->null_prec = 1;
		}
	}
}

int					ft_process_fmt(const char *fmt, \
				t_fsi *interface, va_list ap)
{
	ft_process_flags(fmt, interface);
	ft_process_field_prec(fmt, interface);
	ft_process_star(fmt, interface, ap);
	fmt += interface->fslen;
	if (ft_strchr(interface->int_types, *fmt))
		interface->type = (unsigned char)*fmt;
	if (ft_strchr(interface->oth_types, *fmt) && \
			!interface->hash && !interface->space && !interface->plus)
		interface->type = (unsigned char)*fmt;
	if (interface->type != 0 && ++interface->fslen)
		return (0);
	return (-1);
}
