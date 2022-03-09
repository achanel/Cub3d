#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str)
	{
		if (*str == (unsigned char)ch)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)ch == *str)
		return ((char *)str);
	return (NULL);
}
