/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:01:19 by meldora           #+#    #+#             */
/*   Updated: 2020/12/12 12:52:15 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_len_util_int(const char *res, t_fsi *interface, int *len)
{
	*len = ft_strlen(res) + interface->space + \
			(interface->plus == 1 && !(res[0] == '-'));
	if (interface->field < 0)
		interface->field *= -1;
	interface->field += interface->space;
	interface->prec += interface->space;
	if (interface->prec >= *len)
		interface->prec += (interface->plus || (res[0] == '-'));
	if (interface->prec < *len)
		interface->prec = *len;
	if (interface->hash == 1 && res[0] != '\0' && res[0] != '0')
	{
		interface->field += 2;
		interface->prec += 2;
		*len += 2;
	}
}

static void		ft_len_util_other(const char *res, t_fsi *interface, int *len)
{
	*len = ft_strlen(res);
	if (interface->type == 'c' && res[0] == '\0')
		*len = 1;
	if (interface->field < 0)
		interface->field *= -1;
	if (interface->prec >= *len)
		interface->prec = *len;
	else if (interface->prec < *len && interface->prec != 0)
		*len = interface->prec;
}

int				ft_lencheck(const char *res, t_fsi *interface)
{
	int len;

	if (res == NULL)
		return (0);
	if (ft_strchr(interface->int_types, interface->type))
	{
		ft_len_util_int(res, interface, &len);
		if (interface->field > len && interface->field > interface->prec)
			return (interface->field);
		if (interface->field > len && interface->field < interface->prec)
			return (interface->prec);
		if (interface->prec > len)
			return (interface->prec);
		return (len);
	}
	else if (ft_strchr(interface->oth_types, interface->type))
	{
		ft_len_util_other(res, interface, &len);
		if (interface->field > len && interface->field > interface->prec)
			return (interface->field);
		if (interface->prec < len && interface->prec != 0)
			return (interface->prec);
		return (len);
	}
	return (0);
}
