#include "libft.h"

size_t	ft_lstlen(t_list *start)
{
	size_t	ret;

	ret = 0;
	while (start)
	{
		++ret;
		start = start->next;
	}
	return (ret);
}
