/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:30:46 by achanel           #+#    #+#             */
/*   Updated: 2022/03/30 17:30:47 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buffer;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	buffer = malloc(count * size);
	if (buffer == NULL)
		return (NULL);
	else
		ft_bzero(buffer, count * size);
	return (buffer);
}
