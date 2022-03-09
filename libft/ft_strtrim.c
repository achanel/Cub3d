#include "libft.h"

static unsigned int	checker (const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (checker(set, s1[start]))
		start++;
	if (start != end)
		while (end >= 0 && (checker(set, s1[end - 1])))
			end--;
	str = malloc(&s1[end - 1] - &s1[start] + 2);
	if (str == NULL)
		return (NULL);
	while (start < end)
	{
		str[i++] = s1[start++];
	}
	str[i] = '\0';
	return (str);
}
