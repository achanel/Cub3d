/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:37:47 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 09:37:48 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	long int	num;
	int			i;
	int			np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		||str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		if (num * 10 + (str[i] + '0') < num && np > 0)
			return (-1);
		else if (num * 10 + (str[i] + '0') < num && np < 0)
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}
