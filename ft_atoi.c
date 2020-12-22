/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:58:47 by meldora           #+#    #+#             */
/*   Updated: 2020/11/02 13:36:13 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	len;
	int	sign;
	int	result;

	while (*str == '\t' || *str == '\n' || *str == '\r' \
			|| *str == '\v' || *str == '\f' || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	len = 0;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		len++;
	}
	if (len >= 20)
		return ((-sign - 1) / 2);
	return (result * sign);
}
