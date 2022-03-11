#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	if (!str)
		return (NULL);
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
