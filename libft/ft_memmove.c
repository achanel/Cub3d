/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:31:38 by achanel           #+#    #+#             */
/*   Updated: 2022/03/30 17:31:40 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	if (!dst && !src)
		return (NULL);
	s = (char *)src;
	d = (char *)dst;
	if (s >= d)
		return (ft_memcpy(d, s, len));
	while (len--)
		d[len] = s[len];
	return (dst);
}
