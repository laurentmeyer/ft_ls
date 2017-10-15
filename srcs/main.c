/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:42:12 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/15 15:01:51 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		split_files_dirs(t_list *parents, t_list **files, t_list **dirs,
		t_options *options)
{
	ft_lstsort(&parents, options->cmp_f);
	if (options->sort_reverse == 0)
		ft_lstrev(&parents);
	while (parents)
	{
		if (S_ISDIR(((t_file *)(parents->content))->stat.st_mode))
			ft_lstadd(dirs, ft_lstpop(&parents));
		else
			ft_lstadd(files, ft_lstpop(&parents));
	}
}

static void		display_files_dirs(t_list *files, t_list *dirs,
		t_options *options)
{
	if (files)
		display_children(files);
	options->files_done = 1;
	while (dirs)
	{
		ft_ls((t_file *)(dirs->content));
		dirs = dirs->next;
	}
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
	display_files_dirs(files, dirs, &options);
	return (0);
}
