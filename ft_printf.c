/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:58:07 by meldora           #+#    #+#             */
/*   Updated: 2020/12/20 13:20:14 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_manager(char **res, t_fsi *interface, \
			const char **fmt, va_list ap)
{
	if (ft_process_fmt(*fmt, interface, ap) == -1)
		return (-1);
	*res = ft_convert_arg(interface, ap);
	if (*res == NULL)
		return (-1);
	ft_display_arg(*res, interface);
	*fmt += interface->fslen;
	return (ft_lencheck(*res, interface));
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*res;
	t_fsi		*interface;
	int			len;
	int			manager;

	va_start(ap, format);
	len = 0;
	res = NULL;
	interface = NULL;
	while (*format)
	{
		if ((interface = ft_create_interface()) == NULL)
			return (ft_cleanup(&res, &interface, ap, 1));
		if (ft_putcstr(&format, &len) == '\0')
			break ;
		manager = ft_manager(&res, interface, &format, ap);
		if (manager == -1)
			return (ft_cleanup(&res, &interface, ap, 1));
		len += manager;
		if (*format != '\0')
			ft_cleanup(&res, &interface, ap, 0);
	}
	ft_cleanup(&res, &interface, ap, 1);
	return (len);
}
