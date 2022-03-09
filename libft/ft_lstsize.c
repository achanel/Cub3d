#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*list;
	int		i;

	i = 0;
	list = lst;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
