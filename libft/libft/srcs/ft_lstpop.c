#include "libft.h"

t_list	*ft_lstpop(t_list **elem_addr)
{
	t_list	*ret;

	ret = *elem_addr;
	if (*elem_addr)
		*elem_addr = *elem_addr->next;
	return (ret);
}
