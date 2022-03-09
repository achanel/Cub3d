#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(size + 1);
	if (!str)
		return (NULL);
	while (size > 0)
		str[size--] = 0;
	str[0] = '\0';
	return (str);
}