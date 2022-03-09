#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_element = ft_lstnew(f(lst->content));
		if (!new_element)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_list, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, new_element);
	}
	return (new_list);
}
