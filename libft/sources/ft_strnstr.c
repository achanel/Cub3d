#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	size_t	i;
	size_t	j;

	b = (char *)big;
	if (*little == '\0' || little == NULL)
		return (b);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((i + j) < len && little[j] == b[i + j])
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
