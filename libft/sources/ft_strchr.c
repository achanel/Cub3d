#include "../includes/libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*s;

	s = (char *)str;
	while (*s != (unsigned char)ch)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	s++;
	return (s);
}
