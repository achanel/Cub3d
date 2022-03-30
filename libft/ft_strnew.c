/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:33:00 by achanel           #+#    #+#             */
/*   Updated: 2022/03/30 17:36:31 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(size + 1);
	if (!str)
		return (NULL);
	while (size > 0)
		str[size--] = 0;
	str[0] = '\0';
	return (str);
}
