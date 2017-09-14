/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:42:12 by lmeyer            #+#    #+#             */
/*   Updated: 2017/09/14 18:55:15 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		handle_multi_args(int argc, char **argv, t_options *options)
{
	(void)argc;
	(void)argv;
	(void)options;
//	struct stat		statbuf;
//	int				err;
//
//	err = 0;
//	while (argc--)
//	{
//		if ((err = stat(argv[argc], &statbuf)) == ERROR)
//		{
//			perror(NULL);
//			break ;
//		}
//		if ((err = insert_ordered(t_file_new(".", argv[argc], &statbuf),
//						alst, options)) == ERROR)
//			break;
//	}
//	return (err);
}

int			main(int argc, char **argv)
{
	t_options 	options;
	int			arg_pos;
	t_list		*parents;

	arg_pos = get_options(&options, argc, argv); // rajouter une gestion d'erreurs
	parents = NULL;
	if (arg_pos == argc)
		add_t_file_to_list(".", &parents, &options);
	else
		while (arg_pos < argc)
			add_t_file_to_list(argv[arg_pos++], &parents, &options);
	if (parents)
		ft_ls((t_file *)(parents->content), &options);
//	while (1)
//		;
	return (0);
}
