/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:55:23 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/02 17:15:52 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	cmp_timemod(t_list *l1, t_list *l2)
{
	struct timespec t1;
	struct timespec t2;

	t1 = ((t_file *)(l1->content))->stat.st_mtimespec;
	t2 = ((t_file *)(l2->content))->stat.st_mtimespec;

	if (t1.tv_sec != t2.tv_sec)
		return (t1.tv_sec < t2.tv_sec ? -1 : 1);
	if (t1.tv_nsec != t2.tv_nsec)
		return (t1.tv_nsec < t2.tv_nsec ? -1 : 1);
	return (-ft_strcmp(((t_file *)(l1->content))->path,
				((t_file *)(l2->content))->path));
}

int	cmp_names(t_list *l1, t_list *l2)
{
	return (-ft_strcmp(((t_file *)(l1->content))->path,
				((t_file *)(l2->content))->path));
}
