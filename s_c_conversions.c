/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_c_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:00:56 by meldora           #+#    #+#             */
/*   Updated: 2020/12/20 13:18:51 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string(va_list ap)
{
	char *res;

	res = va_arg(ap, char *);
	if (res == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(res));
}

char	*ft_ctoa(int arg)
{
	char *res;

	res = (char *)malloc(sizeof(char) * 2);
	if (res == NULL)
		return (NULL);
	res[0] = arg;
	res[1] = '\0';
	return (res);
}
