/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:42:12 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/20 18:40:27 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		split_files_dirs(t_list **parents, t_list **files,
		t_list **dirs)
{
	t_file	*file;
	t_list	*errors;

	errors = NULL;
	ft_lstsort(parents, &cmp_names);
	while (*parents)
	{
		file = (t_file *)((*parents)->content);
		if (S_ISDIR(file->stat.st_mode))
			ft_lstadd(dirs, ft_lstpop(parents));
		else if (file->error)
		{
			ft_dprintf(STDERR, "ft_ls: %s: %s\n", file->path, strerror(errno));
			ft_lstadd(&errors, ft_lstpop(parents));
		}
		else
			ft_lstadd(files, ft_lstpop(parents));
	}
	*parents = errors;
}

static void		display_files(t_list **files)
{
	t_options	*options;

	if (!*files)
		return ;
	options = ((t_file *)((*files)->content))->options;
	ft_lstsort(files, options->cmp_f);
	if (options->sort_reverse)
		ft_lstrev(files);
	display_children(*files);
	options->first_display = 0;
	options->display_headers = 1;
}

static void		display_dirs(t_list **dirs)
{
	t_options	*options;

	if (!*dirs)
		return ;
	options = ((t_file *)((*dirs)->content))->options;
	ft_lstsort(dirs, options->cmp_f);
	if (options->sort_reverse)
		ft_lstrev(dirs);
	ft_lstiter(*dirs, &ft_ls);
}

int				main(int argc, char **argv)
{
	t_options	options;
	int			arg_pos;
	t_list		*parents;
	t_list		*files;
	t_list		*dirs;

	arg_pos = get_options(&options, argc, argv);
	parents = NULL;
	if (arg_pos == argc)
		add_t_file_to_list(".", &parents, &options);
	else
		while (arg_pos < argc)
			add_t_file_to_list(argv[arg_pos++], &parents, &options);
	ft_lstrev(&parents);
	files = NULL;
	dirs = NULL;
	split_files_dirs(&parents, &files, &dirs);
	display_files(&files);
	options.files_done = 1;
	options.display_headers = 1;
	display_dirs(&dirs);
	return (0);
}
