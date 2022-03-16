#include "cub3D.h"

static char	*end_line(int fd, char **buf_gl)
{
	char	*end;

	end = ft_strchr(buf_gl[fd], '\n');
	if (!end)
		end = ft_strchr(buf_gl[fd], '\0');
	return (end);
}

static int	trim_line(int fd, char **line, char **buf_gl, int i)
{
	char	*end;
	char	*tmp;
	int		len;

	end = end_line(fd, buf_gl);
	len = end - buf_gl[fd];
	if (*end == '\n')
		end++;
	*line = (char *)malloc(len + 1);
	tmp = ft_strdup(end);
	if (!(*line) || !tmp)
		return (-1);
	while (++i < len)
		(*line)[i] = buf_gl[fd][i];
	(*line)[i] = '\0';
	free(buf_gl[fd]);
	if (*tmp == '\0')
	{
		buf_gl[fd] = NULL;
		free(tmp);
	}
	else
		buf_gl[fd] = tmp;
	return (1);
}

static int	read_line(int fd, char **buf_gl)
{
	int		bwr;
	char	*tmp;
	char	*buf;

	if (!buf_gl[fd])
		buf_gl[fd] = ft_strnew(1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bwr = read(fd, buf, BUFFER_SIZE);
	while (bwr)
	{
		buf[bwr] = '\0';
		tmp = buf_gl[fd];
		buf_gl[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n') || bwr == 0)
			break ;
		bwr = read(fd, buf, BUFFER_SIZE);
	}
	if (bwr > 0)
		bwr = 1;
	free(buf);
	buf = NULL;
	return (bwr);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf_gl[65535];
	int			bwr;
	int			trim;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0
		|| read(fd, buf_gl[fd], 0) < 0)
		return (-1);
	if (ft_strchr(buf_gl[fd], '\n'))
		return (trim_line(fd, line, buf_gl, -1));
	bwr = read_line(fd, buf_gl);
	if (bwr > -1)
	{
		trim = trim_line(fd, line, buf_gl, -1);
		if (trim > -1)
			return (bwr);
	}
	// printf("%s\n", buf_gl[fd]);
	free(buf_gl[fd]);
	buf_gl[fd] = NULL;
	return (-1);
}
