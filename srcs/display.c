/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:39:50 by lmeyer            #+#    #+#             */
/*   Updated: 2017/09/14 18:54:18 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_simple(t_list *children, t_options *options)
{
	char	*filename;

	while (children)
	{
		filename = ft_basename(((t_file *)(children->content))->path);
		if (options->display_dots
				|| (!ft_strequ(filename, ".")
					&& !ft_strequ(filename, "..")))
			ft_printf("%s\n", filename);
		children = children->next;
	}
}

void		display_children(t_list *children, t_options *options)
{
	if (!(options->display_long))
		display_simple(children, options);
}

void		display_parent_and_children(t_file *parent, t_list *children,
		t_options *options)
{
	if (options->display_headers)
		ft_printf("\n%s:\n", parent->path);
	options->display_headers = 1;
	if (parent->error)
		ft_dprintf(STDERR, "ls: %s: %s\n", ft_basename(parent->path), parent->error);
	else
		display_children(children, options);
}
