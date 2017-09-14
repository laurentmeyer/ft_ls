/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:41:24 by lmeyer            #+#    #+#             */
/*   Updated: 2017/09/14 18:43:20 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			recurse_ft_ls(t_list *children, t_options *options)
{
	t_list	*child;
	t_file	*file;

	child = children;
	while (child)
	{
		file = (t_file *)(child->content);
		if (S_ISDIR(file->stat.st_mode) && !ft_strequ((ft_basename(file->path)),
					".") && !ft_strequ((ft_basename(file->path)), ".."))
			ft_ls(file, options);
		child = child->next;
	}
}

void				ft_ls(t_file *parent, t_options *options)
{
	t_list			*children;

	children = NULL;
	list_dir_contents(parent, &children, options);
	if (parent->error)
		display_parent_and_children(parent, children, options);
	else
	{
		ft_lstsort(&children, options->cmp_f);
		display_parent_and_children(parent, children, options);
		if (options->recursive)
			recurse_ft_ls(children, options);
		ft_lstdel(&children, &t_file_lstdel);
	}
}
