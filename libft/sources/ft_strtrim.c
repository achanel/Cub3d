/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:39:25 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 09:39:26 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_check(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (0);
	k = ft_strlen(s1);
	j = 0;
	i = 0;
	while (ft_check(s1[i], set) == 1 && s1[i])
		i++;
	if (i != k)
		while (ft_check(s1[k - 1], set) == 1 && k >= 0)
			k--;
	dst = (char *)malloc((k - i + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < k && s1[i])
		dst[j++] = s1[i++];
	dst[j] = '\0';
	return (dst);
}
