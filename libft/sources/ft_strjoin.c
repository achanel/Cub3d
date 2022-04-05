/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:39:09 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 09:39:10 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	dst = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	i = 0;
	if (!dst)
		return (0);
	while (*s1 != '\0')
	{
		dst[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		dst[i] = *s2;
		i++;
		s2++;
	}
	dst[i] = '\0';
	return (dst);
}
