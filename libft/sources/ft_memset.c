/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:38:52 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 09:38:53 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	char	*p;

	p = (char *)src;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (src);
}
