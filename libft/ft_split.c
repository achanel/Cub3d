#include "libft.h"

static char	**malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	word_counter(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return ((int)count);
}

static void	next_str(char **str, size_t *len, char c)
{
	size_t	i;

	i = 0;
	*str += *len;
	*len = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t		n;
	char		*str;
	char		**tab;
	size_t		len;

	if (!s)
		return (NULL);
	n = 0;
	len = 0;
	str = (char *)s;
	tab = malloc(sizeof(char *) * ((word_counter(s, c) + 1)));
	if (tab == NULL)
		return (NULL);
	while (n < word_counter(s, c))
	{	
		next_str(&str, &len, c);
		tab[n] = malloc(sizeof(char) * (len + 1));
		if (tab[n] == NULL)
			return (malloc_error(tab));
		ft_strlcpy(tab[n], str, len + 1);
		n++;
	}
	tab[n] = NULL;
	return (tab);
}
