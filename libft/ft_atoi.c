/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:58:47 by meldora           #+#    #+#             */
/*   Updated: 2020/11/18 18:12:49 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\r'
			|| ch == '\v' || ch == '\f' || ch == ' ')
		return (1);
	return (0);
}

int			ft_atoi(char *str)
{
	char	*ptr;
	int		len;
	int		sign;
	int		result;

	ptr = str;
	while (ft_isspace(*ptr))
		ptr++;
	sign = *ptr == '-' ? -1 : 1;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr == '0')
		ptr++;
	len = 0;
	result = 0;
	while (ft_isdigit(*ptr))
	{
		result = result * 10 + (*ptr - '0');
		ptr++;
		len++;
	}
	if (len >= 19)
		return ((-sign - 1) / 2);
	return (result * sign);
}
