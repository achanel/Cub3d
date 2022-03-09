#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			nbr;
	unsigned int	a;

	a = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		a *= -1;
	}
	if (a >= 10)
		ft_putnbr_fd(a / 10, fd);
	nbr = a % 10 + '0';
	ft_putchar_fd(nbr, fd);
	a /= 10;
}
