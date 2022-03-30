/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:33:02 by achanel           #+#    #+#             */
/*   Updated: 2022/03/30 17:33:03 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l_needle;
	size_t	i;

	i = 0;
	l_needle = ft_strlen(needle);
	if (!needle || needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (i + l_needle > len)
			return (NULL);
		if (ft_memcmp(haystack, needle, l_needle) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
