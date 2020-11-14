/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:25:41 by meldora           #+#    #+#             */
/*   Updated: 2020/11/08 15:27:19 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *one;
	const unsigned char *two;
	
	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	if (!one || !two)
		return (*one - *two);
	while (*one && *two)
	{
		if (*one != *two)
			return (*one - *two);
		one++;
		two++;
	}
	return (*one - *two);
}
