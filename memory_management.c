/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:30:04 by meldora           #+#    #+#             */
/*   Updated: 2020/12/20 13:20:48 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fsi	*ft_create_interface(void)
{
	t_fsi *interface;

	interface = NULL;
	interface = (t_fsi *)malloc(sizeof(t_fsi));
	if (interface == NULL)
		return (NULL);
	interface->type = 0;
	interface->int_types = "diuxX";
	interface->oth_types = "csp%";
	interface->field = 1;
	interface->prec = 0;
	interface->null_prec = 0;
	interface->zero = 0;
	interface->hash = 0;
	interface->space = 0;
	interface->plus = 0;
	interface->fslen = 0;
	return (interface);
}

void	ft_destroy_interface(t_fsi *interface)
{
	interface->int_types = NULL;
	interface->oth_types = NULL;
	interface->type = 0;
	interface->field = 0;
	interface->prec = 0;
	interface->null_prec = 0;
	interface->zero = 0;
	interface->hash = 0;
	interface->space = 0;
	interface->plus = 0;
	interface->fslen = 0;
	free(interface);
}

int		ft_cleanup(char **res, t_fsi **interface, va_list ap, int check)
{
	if (*res != NULL)
	{
		free(*res);
		*res = NULL;
	}
	if (*interface != NULL)
	{
		ft_destroy_interface(*interface);
		interface = NULL;
	}
	if (check == 1)
		va_end(ap);
	return (-1);
}
