/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:42:12 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/17 14:33:32 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		split_files_dirs(t_list *parents, t_list **files, t_list **dirs,
		t_options *options)
{
	t_file	*file;

	ft_lstsort(&parents, options->cmp_f);
	if (options->sort_reverse == 0)
		ft_lstrev(&parents);
	while (parents)
	{
		file = (t_file *)(parents->content);
		if (S_ISDIR(file->stat.st_mode))
			ft_lstadd(dirs, ft_lstpop(&parents));
		else if (file->error)
		{
			ft_dprintf(STDERR, "ft_ls: %s: %s\n", file->path, strerror(errno));
			parents = parents->next;
		}
		else
			ft_lstadd(files, ft_lstpop(&parents));
	}
}

static void		display_files(t_list *files)
{
	if (!files)
		return ;
	display_children(files);
	((t_file *)(files->content))->options->first_display = 0;
}

static void		display_dirs(t_list *dirs)
{
	if (!dirs)
		return ;
	ft_lstiter(dirs, &ft_ls);
}

int				main(int argc, char **argv)
{
	t_options	options;
	int			arg_pos;
	t_list		*parents;
	t_list		*files;
	t_list		*dirs;

	arg_pos = get_options(&options, argc, argv);
	// rajouter une gestion d'erreurs et un usage
	parents = NULL;
	if (arg_pos == argc)
		add_t_file_to_list(".", &parents, &options);
	else
		while (arg_pos < argc)
			add_t_file_to_list(argv[arg_pos++], &parents, &options);
	files = NULL;
	dirs = NULL;
	split_files_dirs(parents, &files, &dirs, &options);
	display_files(files);
	options.files_done = 1;
	display_dirs(dirs);
	return (0);
}
