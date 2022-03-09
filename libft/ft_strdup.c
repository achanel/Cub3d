#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*buffer;

	i = 0;
	len = ft_strlen(s1);
	buffer = malloc(len + 1);
	if (buffer == NULL)
		return (NULL);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
