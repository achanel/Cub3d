/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:38:50 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 09:38:51 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;
	char	*ptr2;

	if (!dst && !src)
		return (NULL);
	ptr = (char *)dst;
	ptr2 = (char *)src;
	if (ptr2 >= ptr)
		return (ft_memcpy(ptr, ptr2, len));
	while (len--)
		ptr[len] = ptr2[len];
	return (dst);
}
