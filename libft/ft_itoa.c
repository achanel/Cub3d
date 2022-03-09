#include "libft.h"

static int	num_count(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0 )
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*int_to_str(int n, int count, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	str[count] = '\0';
	while (n > 0)
	{
		str[--count] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = num_count(n);
	str = malloc(count + 1);
	if (str == NULL)
		return (NULL);
	str = int_to_str(n, count, str);
	return (str);
}
