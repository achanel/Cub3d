#include "libft.h"

void	*ft_memset (void *dest, int c, size_t n)
{
	char	*src;
	size_t	i;

	src = dest;
	i = 0;
	while (i < n)
		src[i++] = c;
	return (dest);
}
