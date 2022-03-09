#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = 0;
	if (ft_strchr(str, (unsigned char)ch) == NULL)
		return (NULL);
	while (*str)
		str++;
	while (*str != (unsigned char)ch)
	{
		str--;
	}
	return ((char *)str);
}
