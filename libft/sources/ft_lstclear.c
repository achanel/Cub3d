/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:38:25 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 09:38:26 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*last_save;

	l = *lst;
	while (l)
	{
		last_save = l->next;
		if (del)
			del(l->content);
		free(l);
		l = last_save;
	}
	*lst = NULL;
}
