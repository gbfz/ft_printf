/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meldora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:38:11 by meldora           #+#    #+#             */
/*   Updated: 2020/12/21 15:06:06 by meldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_init(char **line, char **buf, int *was_read)
{
	*line = (char *)malloc(1);
	(*line)[0] = '\0';
	if (BUFFER_SIZE <= 0)
		return (-1);
	if (*buf == NULL)
	{
		*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (*buf == NULL)
			return (-1);
	}
	*was_read = 0;
	return (0);
}

int		ft_exit(int was_read, char **buf)
{
	if (was_read >= 1)
		return (1);
	free(*buf);
	*buf = NULL;
	if (was_read == 0)
		return (0);
	return (-1);
}
