#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

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

int		ft_exit(int was_read, char **buf)
{
		if (was_read == 0)
		{
				if (*buf != NULL)
				{
						free(*buf);
						*buf = NULL;
				}
				return (0);
		}
		if (was_read == -1)
				return (-1);
		return (1);
}

int		ft_init(char **line, char **buf)
{
		*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (*buf == NULL)
				return (-1);
		*line = (char *)ft_calloc(sizeof(char), 1);
		return (0);
}

int		get_next_line(int fd, char **line)
{
		static char 	*buf;
		static char		*rem[256];
		int				was_read;
		int				was_written;

		if (fd < 0 || BUFFER_SIZE <= 0 || ft_init(line, &buf) == -1)
				return (-1);
		if (rem[fd] != NULL)
				if ((was_read = read_rem(line, &rem[fd])) == -1)
						return (ft_exit(-1, &buf));
		if (rem[fd] == NULL)
				while ((was_read = read(fd, buf, BUFFER_SIZE)) && \
								buf[was_written] != '\n')
				{
						if (was_read == -1)
								return (ft_exit(-1, &buf));
						buf[was_read] = '\0';
						if ((was_written = ft_line(line, buf)) == -1)
								return (ft_exit(-1, &buf));
						rem[fd] = buf + was_written;
						if (buf[was_written] == '\n')
								break ;
				}
		return (ft_exit(was_read, &buf));
}

int		main(void)
{
		char	*line;
		int		nabokov = open("nabokov", O_RDONLY);
		int		test = open("test", O_RDONLY);
		int		ret;

		/*
		while (get_next_line(nabokov, &line) > 0)
		{
				printf("%s\n", line);
				free(line);
				//sleep(1);
		}
		*/

		ret = get_next_line(nabokov, &line);
		printf("%s\n", line);
		free(line);
		//printf("ret = %d\n", ret);

		ret = get_next_line(test, &line);
		printf("%s\n", line);
		free(line);
		//printf("ret = %d\n", ret);
		ret = get_next_line(test, &line);
		printf("%s\n", line);
		free(line);
		//printf("ret = %d\n", ret);
		ret = get_next_line(test, &line);
		printf("%s\n", line);
		free(line);
		//printf("ret = %d\n", ret);
		ret = get_next_line(test, &line);
		printf("%s\n", line);
		free(line);
		//printf("ret = %d\n", ret);
		ret = get_next_line(test, &line);
		printf("%s\n", line);
		free(line);
		//printf("ret = %d\n", ret);

		ret = get_next_line(nabokov, &line);
		printf("%s\n", line);
		free(line);
		//printf("ret = %d\n", ret);
		ret = get_next_line(nabokov, &line);
		printf("%s\n", line);
		free(line);
		//printf("ret = %d\n", ret);

		printf("%s", ret == 0 ? "" : "");
		close(nabokov);
		close(test);
		_CrtDumpMemoryLeaks();
		return (0);
}
