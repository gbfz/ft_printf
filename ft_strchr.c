/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:46:37 by meldora           #+#    #+#             */
/*   Updated: 2020/11/02 17:27:28 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr != c && *ptr)
		ptr++;
	if (*ptr == '\0' && c == '\0')
		return (ptr);
	if (*ptr == '\0')
		return (NULL);
	return (ptr);
}
