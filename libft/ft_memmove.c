#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	if (!dst && !src)
		return (NULL);
	s = (char *)src;
	d = (char *)dst;
	if (s >= d)
		return (ft_memcpy(d, s, len));
	while (len--)
		d[len] = s[len];
	return (dst);
}
