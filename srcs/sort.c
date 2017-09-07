/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:55:23 by lmeyer            #+#    #+#             */
/*   Updated: 2017/09/07 14:55:25 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	cmp_names(t_list *l1, t_list *l2)
{
	return (-ft_strcmp(((t_file *)(l1->content))->path,
				((t_file *)(l2->content))->path));
}

//static int	cmp_time(t_list *l1, t_list *l2)
//{
//	return (-ft_strcmp(((t_file *)(l1->content))->basename,
//				((t_file *)(l2->content))->basename));
//}

t_listcmp	*select_sort_function(t_options *options)
{
	(void)options;
	return (&cmp_names);
}
