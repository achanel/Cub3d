#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*list;

	list = *lst;
	while (list)
	{
		tmp = list->next;
		if (del)
			del(list->content);
		free (list);
		list = tmp;
	}
	*lst = NULL;
}
