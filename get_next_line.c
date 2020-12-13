#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/*
** problems arise on:
** BUFFER_SIZE=1: empty lines contain garbage.
** BUFFER_SIZE=2: empty lines still contain garbage,
** but in fewer amounts than with 1.
** problems stop on BUFFER_SIZE >= 3.
*/

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

void	ft_bzero(char *s, size_t size)
{
		size_t i;

		if (s == NULL)
				return ;
		i = 0;
		while (i < size)
		{
				s[i] = '\0';
				i++;
		}
}

void	*ft_calloc(size_t count, size_t size)
{
		void *res;

		res = malloc(count * size);
		if (res == NULL)
				return (NULL);
		ft_bzero(res, count * size);
		return (res);
}

char	*ft_strappend(char *s, int c)
{
		int last;

		last = ft_strlen(s);
		s[last] = c;
		return (s);
}

char	*ft_realloc(char *str, size_t newsize)
{
		char	*res;
		char	*tmp;
		size_t	i;

		tmp = str;
		res = (char *)malloc(sizeof(char) * (newsize + 1));
		if (res == NULL)
				return (NULL);
		i = 0;
		while (tmp[i])
		{
				res[i] = tmp[i];
				i++;
		}
		while (i < newsize + 1)
		{
				res[i] = '\0';
				i++;
		}
		free(tmp);
		return (res);
}

int		ft_line(char **line, char *buf)
{
		int		was_written;
		int		len;
		int		i;

		len = ft_strlen(*line);
		i = 0;
		was_written = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
		{
				*line = ft_realloc(*line, len + 1);
				if (*line == NULL)
						return (-1);
				*line = ft_strappend(*line, buf[i]);
				i++;
				len++;
				was_written++;
		}
		return (was_written);
}

int		read_rem(char **line, char **rem)
{
		int	was_written;

		if ((*rem)[0] == '\n')
				(*rem)++;
		was_written = ft_line(line, *rem);
		if (was_written == -1)
				return (-1);
		*rem += was_written;
		if ((*rem)[0] == '\0')
				*rem = NULL;
		return (1);
}

int		get_next_line(int fd, char **line)
{
		char 			buf[256][BUFFER_SIZE + 1];
		static char		*rem[256];
		int				was_read;
		int				was_written;

		if (fd < 0 || BUFFER_SIZE <= 0)
				return (-1);
		*line = (char *)ft_calloc(sizeof(char), 1);
		if (rem[fd] != NULL)
				if ((was_read = read_rem(line, &rem[fd])) == -1)
						return (-1);
		if (rem[fd] == NULL)
				while ((was_read = read(fd, buf[fd], BUFFER_SIZE)))
				{
						if (was_read == -1)
								return (-1);
						buf[fd][was_read] = '\0';
						if ((was_written = ft_line(line, buf[fd])) == -1)
								return (-1);
						rem[fd] = buf[fd] + was_written;
						if (buf[fd][was_written] == '\n')
								break ;
				}
		return (!!was_read);
}

int		main(void)
{
		char	*line;
		int		nabokov = open("nabokov", O_RDONLY);
		int		test = open("test", O_RDONLY);

		/*
		while (get_next_line(nabokov, &line) > 0)
		{
				printf("%s\n", line);
				free(line);
				//sleep(1);
		}
		*/

		get_next_line(nabokov, &line);
		printf("%s\n", line);
		free(line);

		get_next_line(test, &line);
		printf("%s\n", line);
		free(line);
		get_next_line(test, &line);
		printf("%s\n", line);
		free(line);
		get_next_line(test, &line);
		printf("%s\n", line);
		free(line);
		get_next_line(test, &line);
		printf("%s\n", line);
		free(line);
		get_next_line(test, &line);
		printf("%s\n", line);
		free(line);

		get_next_line(nabokov, &line);
		printf("%s\n", line);
		free(line);
		get_next_line(nabokov, &line);
		printf("%s\n", line);
		free(line);

		close(nabokov);
		close(test);
		return (0);
}
