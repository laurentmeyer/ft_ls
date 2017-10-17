/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:39:50 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/17 14:39:37 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>//

#define ARROW_LEN    4
#define LINK_MAX_LEN 255

static const char	*g_colors[16] = {
	"",
	CF_YEL,
	"\033[34;43m",
	"",
	C_BOLD,
	"",
	"\033[34;46m",
	"",
	"",
	"",
	CF_MAG,
	"",
	CF_GRE,
	"",
	"",
	""
};

void		print_filename(t_file *child)
{
	char		*filename;
	mode_t		mode;
	char		lnbuf[LINK_MAX_LEN + ARROW_LEN + 1];
	t_options	*options;

	ft_bzero(lnbuf, sizeof(lnbuf));
	options = child->options;
	filename = options->files_done ? ft_basename(child->path) : child->path;
	ft_bzero(lnbuf, sizeof(lnbuf));
	mode = (child->stat.st_mode & S_IFMT) >> 12;
	if (S_ISLNK(child->stat.st_mode) && options->display_long)
	{
		ft_strncpy(lnbuf, " -> ", ARROW_LEN);
		readlink(child->path, lnbuf + ARROW_LEN, LINK_MAX_LEN);
	}
	if (S_ISREG(child->stat.st_mode) && (S_IXUSR & child->stat.st_mode))
		ft_printf(CF_RED "%s" C_RESET "\n", filename);
	else
		ft_printf("%s%s" C_RESET "%s\n", g_colors[mode], filename, lnbuf);
}

void		display_simple(t_list *children)
{
		if (!is_hidden((t_file *)(children->content)))
			print_filename((t_file *)(children->content));
}

void		display_children(t_list *children)
{
	t_options *options;

	options = ((t_file *)(children->content))->options;
	options->display_headers = 1;
	options->first_display = 0;
	if (options->display_long)
	{
		ft_bzero(options->format, sizeof(t_format));
		ft_lstiter(children, &get_precisions);
		make_format(options);
		//if (options->format->p_total || options->files_done)
		if (options->files_done)
			ft_printf("total %d\n", options->format->p_total);
		ft_lstiter(children, &display_long_line);
	}
	else
		ft_lstiter(children, &display_simple);
}

void		display_parent_and_children(t_file *parent, t_list *children)
{
	t_options *options;

	options = parent->options;
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
