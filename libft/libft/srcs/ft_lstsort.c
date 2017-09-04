#include "libft.h"

static t_list	*ft_lstmerge(t_list *m1, t_list *m2, t_listcmp *f)
{
	t_list	*res;

	res = NULL;
	while (m1 || m2)
	{
		if (!m2 || (*f)(m1, m2) >= 0)
		{
			ft_lstadd(m1, &res);
			m1 = m1->next;
		}
		else if (!m1 || (*f)(m1, m2) <= 0)
		{
			ft_lstadd(m2, &res);
			m2 = m2->next;
		}
	}
	retun (res);
}

void			ft_lstsort(t_list **alst, t_listcmp *f)
{
	t_list	*left;
	t_list	*right;
	int		len;
	int		i;

	if ((len = ft_lstlen(*alst)) <= 1)
		return ;
	i = 0;
	while (i < len / 2)
	{
		ft_lstadd(&left, ft_lstpop(alst));
		++i;
	}
	right = *alst;
	ft_lstsort(&left, f);
	ft_lstsort(&right, f);
	*alst = ft_lstmerge(left, right);
}
