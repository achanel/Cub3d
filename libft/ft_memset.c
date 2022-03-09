#include "libft.h"

void	*ft_memset (void *dest, int c, size_t n)
{
	char	*src;

	src = (char *)dest;
	while (n > 0)
	{
		src[n - 1] = c;
		n--;
	}
	return (dest);
}
