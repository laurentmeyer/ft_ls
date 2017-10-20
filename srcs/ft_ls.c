/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:41:24 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/20 18:14:20 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					is_hidden(t_file *file)
{
	return (!(file->options->display_dots
				|| *(ft_basename(file->path)) != '.'));
}

static void			recurse_ft_ls(t_list *child)
{
	t_file	*file;

	file = (t_file *)(child->content);
	if (S_ISDIR(file->stat.st_mode)
			&& !is_hidden(file)
			&& !ft_strequ(ft_basename(file->path), ".")
			&& !ft_strequ(ft_basename(file->path), ".."))
		ft_ls(child);
}

void				ft_ls(t_list *list)
{
	t_file			*parent;
	t_list			*children;

	children = NULL;
	parent = (t_file *)(list->content);
	list_dir_contents(parent, &children);
	if (parent->error)
		display_parent_and_children(parent, children);
	else
	{
		ft_lstsort(&children, parent->options->cmp_f);
		if (parent->options->sort_reverse)
			ft_lstrev(&children);
		display_parent_and_children(parent, children);
		if (parent->options->recursive)
			ft_lstiter(children, &recurse_ft_ls);
		ft_lstdel(&children, &t_file_lstdel);
	}
}
