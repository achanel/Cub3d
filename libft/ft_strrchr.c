/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:33:04 by achanel           #+#    #+#             */
/*   Updated: 2022/03/30 17:33:05 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = 0;
	if (ft_strchr(str, (unsigned char)ch) == NULL)
		return (NULL);
	while (*str)
		str++;
	while (*str != (unsigned char)ch)
	{
		str--;
	}
	return ((char *)str);
}
