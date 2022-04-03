#include "../includes/libft.h"

int	trim_next_line(char **str, char **line, int read_line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_substr((*str), 0, i);
		tmp = *str;
		(*str) = ft_strchr((*str), '\n');
		if (*str)
			*(str) = ft_strdup((*str));
		free(tmp);
	}
	else
	{
		*line = ft_strdup((*str));
		free(*str);
		*str = NULL;
	}
	if (read_line == 0 && *str == NULL)
		return (0);
	return (1);
}

int	output(char **str, char **line, int read_line)
{
	if (read_line < 0)
	{
		free(*str);
		return (-1);
	}
	else
		return (trim_next_line(str, line, read_line));
}

int	ft_read(int fd, char **buf, char **str)
{
	char	*tmp;
	int		read_line;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, *buf, BUFFER_SIZE);
		(*buf)[read_line] = '\0';
		if (*str == NULL)
			*str = ft_strdup(*buf);
		else
		{
			tmp = *str;
			*str = ft_strjoin(*str, *buf);
			free(tmp);
		}
		if (ft_strchr(*buf, '\n'))
			break ;
	}
	return (read_line);
}

int	get_next_line(int fd, char **line)
{
	int			read_line;
	static char	*str = NULL;
	char		*buf;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		return (-1);
	}
	read_line = ft_read(fd, &buf, &str);
	free(buf);
	return (output(&str, line, read_line));
}
