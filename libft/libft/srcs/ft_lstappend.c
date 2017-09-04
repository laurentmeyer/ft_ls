#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *to_append)
{
	t_list	*cur;

	if (!*alst)
	{
		*alst = to_append;
		return ;
	}
	cur = *alst;
	while (cur->next)
		cur = cur->next;
	cur->next = to_append;
}
