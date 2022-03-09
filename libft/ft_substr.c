#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = malloc(sizeof(*s) * len + 1);
	if (sub == NULL)
		return (NULL);
	while (ft_strlen(s) >= start && (int)len > 0)
	{
		sub[i++] = s[start++];
		len--;
	}
	sub[i] = '\0';
	return (sub);
}
