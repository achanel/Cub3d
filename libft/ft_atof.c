#include "libft.h"

double	ft_atof(const char *str)
{
	double	res1;
	double	res2;
	char	*c;
	int		len;

	c = (char *)str;
	res1 = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res1 >= 0)
		return (res1 + res2);
	else
		return (res1 + -res2);
}	