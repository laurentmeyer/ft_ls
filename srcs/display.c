/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:39:50 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/15 17:27:01 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>//

#define ARROW_LEN           4
#define LINK_MAX_LEN		255

static const char	*g_colors[16] = {
	"", CF_YEL, "\033[34;43m", "", C_BOLD, "", "\033[34;46m", "",
	"", "", CF_MAG, "", CF_GRE, "", "", ""
};

void		print_filename(t_file *child)
{
	char		*filename;
	mode_t		mode;
	char		lnbuf[LINK_MAX_LEN + ARROW_LEN + 1];
	t_options	*options;

	ft_bzero(lnbuf, sizeof(lnbuf));
	options = child->options;
	filename = ft_basename(child->path);
	ft_bzero(lnbuf, sizeof(lnbuf));
	mode = (child->stat.st_mode & S_IFMT) >> 12;
	if (S_ISLNK(child->stat.st_mode) && options->display_long)
	{
		ft_strncpy(lnbuf, " -> ", ARROW_LEN);
		//readlink(child->path, lnbuf + ARROW_LEN, child->stat.st_size);
		readlink(child->path, lnbuf + ARROW_LEN, LINK_MAX_LEN);
	}
	if (S_ISREG(child->stat.st_mode) && (S_IXUSR & child->stat.st_mode))
		ft_printf(CF_RED "%s" C_RESET "\n", filename);
	else
		ft_printf("%s%s" C_RESET "%s\n", g_colors[mode], filename, lnbuf);
}

void		display_simple(t_list *children)
{
	char	*filename;
	mode_t	mode;
	t_options	*options;

	options = ((t_file *)(children->content))->options;
	while (children)
	{
		filename = ft_basename(((t_file *)(children->content))->path);
		mode = ((t_file *)(children->content))->stat.st_mode;
		if (options->display_dots || *filename != '.')
		{
			print_filename((t_file *)(children->content));
		}
		children = children->next;
	}
}

void		display_children(t_list *children)
{
	t_options *options;

	options = ((t_file *)(children->content))->options;
	options->display_headers = 1;
	options->first_display = 0;
	if (options->display_long)
		display_long(children);
	else
		display_simple(children);
}

void		display_parent_and_children(t_file *parent, t_list *children)
{
	t_options *options;

	options = ((t_file *)(children->content))->options;
	if (options->display_headers && options->first_display)
		ft_printf("%s:\n", parent->path);
	else if (options->display_headers)
		ft_printf("\n%s:\n", parent->path);
	options->display_headers = 1;
	options->first_display = 0;
	if (parent->error)
		ft_dprintf(STDERR, "ls: %s: %s\n", ft_basename(parent->path),
				parent->error);
	else if (options->display_long)
		display_long(children);
	else
		display_simple(children);
}
