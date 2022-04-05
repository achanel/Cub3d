/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:38:42 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 09:38:43 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	cn;

	dst = (unsigned char *)src;
	cn = (unsigned char)c;
	while (n-- > 0)
	{
		if (*dst == cn)
		{
			return (dst);
		}
		dst++;
	}
	return (0);
}
