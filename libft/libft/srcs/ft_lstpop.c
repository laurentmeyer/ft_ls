#include "libft.h"

t_list	*ft_lstpop(t_list **elem_addr)
{
	t_list	*ret;

	ret = NULL;
	if (elem_addr && (ret = *elem_addr))
	{
		*elem_addr = ret->next;
		ret->next = NULL;
	}
	return (ret);
}
