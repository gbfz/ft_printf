#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		get_next_line(int fd, char **line);
char	*ft_strappend(char *str, char c);
int		read_rem(char **line, char **buf);
int		ft_line(char **line, char *buf);
char	*ft_strdup(char const *s);
size_t	ft_strlen(char const *s);
int		ft_exit(int was_read, char **buf);

int		main(void)
{
	char	*line;

	int asmb = open("what.s", O_RDONLY);
	int nabokov = open("nabokov", O_RDONLY);
	
	while (get_next_line(nabokov, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	close(asmb);
	close(nabokov);
	return (0);
}

size_t	ft_strlen(char const *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char const *s)
{
	char	*res;
	int		i;

	if (s == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strappend(char *str, char c)
{
	char	*res;
	int	i;

	if (str == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[++i] = '\0';
	return (res);
}

int		ft_line(char **line, char *buf)
{
	int was_processed;

	was_processed = 0;
	while (*buf != '\n' && *buf != '\0')
	{
		*line = ft_strappend(*line, *buf);
		if (*line == NULL)
			return (-1);
		buf++;
		was_processed++;
	}
	return (was_processed);
}


int		read_rem(char **line, char **rem)
{
	int was_processed;

	if (*(*rem) == '\n')
		(*rem)++;
	was_processed = ft_line(line, *rem);
	if (was_processed == -1)
		return (-1);
	*rem += was_processed + 1;
	if (*(*rem) == '\0')
		*rem = NULL;
	return (1);
}

int		ft_exit(int was_read, char **buf)
{
	free(buf);
	if (was_read == -1)
		return (-1);
	if (was_read > 0)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	char static	*rem;
	int			was_read;
	int			was_processed;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	*line = ft_strdup("");
	if (rem != NULL)
		if ((was_read = read_rem(line, &rem)) == -1)
			return (ft_exit(-1, &buf));
	if (rem == NULL)
		while ((was_read = read(fd, buf, BUFFER_SIZE)))
		{
			if (was_read == -1)
				return (ft_exit(-1, &buf));
			buf[BUFFER_SIZE] = '\0';
			if ((was_processed = ft_line(line, buf)) == -1)
				return (ft_exit(-1, &buf));
			rem = buf + was_processed + 1;
			if (*(buf + was_processed) == '\n')
				break ;
		}
	return (ft_exit(was_read, &buf));
}
