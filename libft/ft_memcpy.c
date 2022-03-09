#include "libft.h"

void	*ft_memcpy(void *dest, const void *sour, size_t n)
{
	unsigned int	i;
	char			*s;
	char			*d;

	if (!dest && !sour)
		return (NULL);
	s = (char *)sour;
	d = (char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
