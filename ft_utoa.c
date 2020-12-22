/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:07:52 by meldora           #+#    #+#             */
/*   Updated: 2020/12/04 15:30:32 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nlen(unsigned int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_utoa(unsigned int n)
{
	char	*res;
	int		len;

	len = ft_nlen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(res = (char *)malloc(sizeof(char) + (len + 1))))
		return (NULL);
	res[len--] = '\0';
	while (n)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
