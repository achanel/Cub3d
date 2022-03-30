/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:32:07 by achanel           #+#    #+#             */
/*   Updated: 2022/03/30 17:36:02 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	n;
	size_t	res;

	n = 0;
	j = 0;
	res = 0;
	j = ft_strlen(dst);
	if (j == size && size == 0)
		return (ft_strlen(src) + j);
	if (size < j)
		return (ft_strlen(src) + size);
	else
	{
		res = (ft_strlen(src) + j);
		while (src[n] && j < (size - 1))
		{
			dst[j] = src[n];
			n++;
			j++;
		}
		dst[j] = '\0';
	}
	return (res);
}
