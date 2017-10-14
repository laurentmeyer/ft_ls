/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:34:47 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/14 12:07:19 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern char	*g_optarg;
extern int	g_optind;
extern int	g_optopt;
extern int	g_opterr;
extern int	g_optreset;

static void	select_cmp_function(t_options *options)
{
	if (options->sort_timemod)
		options->cmp_f = &cmp_timemod;
	else
		options->cmp_f = &cmp_names;
}

static void	select_stat_function(t_options *options)
{
	options->stat_f = &lstat;
}

int			get_options(t_options *options, int ac, char **av)
{
	int			ch;

	ft_bzero(options, sizeof(t_options));
	while ((ch = ft_getopt(ac, av, "alRrt")) != -1)
	{
		if (ch == 'a')
			options->display_dots = 1;
		else if (ch == 'l')
			options->display_long = 1;
		else if (ch == 'R')
			options->recursive = 1;
		else if (ch == 'r')
			options->sort_reverse = 1;
		else if (ch == 't')
			options->sort_timemod = 1;
	}
	select_cmp_function(options);
	select_stat_function(options);
	options->first_display = 1;
	return (g_optind);
}
