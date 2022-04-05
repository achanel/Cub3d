/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:38:40 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 09:38:41 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int		i;
	char	*dst;
	char	*sorc;

	dst = (char *)dest;
	sorc = (char *)src;
	i = 0;
	while (i < (int)n)
	{
		dst[i] = sorc[i];
		if (sorc[i] == (char)c || dst[i] == (char)c)
			return (dest + (++i));
		i++;
	}
	return (0);
}
