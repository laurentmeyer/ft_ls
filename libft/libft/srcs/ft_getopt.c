/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:34:00 by lmeyer            #+#    #+#             */
/*   Updated: 2017/03/11 23:01:29 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#define UNKNOWN 0
#define MISSING_ARG 1

char	*g_optarg = NULL;
int		g_optind = 1;
int		g_optopt = '\0';
int		g_opterr = 1;
int		g_optreset = 0;

static int	st_error(int errcode)
{
	(void)errcode;		//
	write(2, "erreur", 7);
	return (-1);
}

int			ft_getopt(int argc, char * const argv[], const char *optstring)
{
	(void)argc;			// ca sent pas bon

	if (g_optreset == 1 && !(g_optopt = '\0'))
		g_optreset = 0; // vraiment pas sur pour cette partie la
	if (argv[g_optind] == NULL || argv[g_optind][0] != '-' ||
			ft_strcmp(argv[g_optind], "-") || ft_strcmp(argv[g_optind], "--"))
		return (-1);
	g_optopt = (g_optopt == '\0') ? argv[g_optind][1]
		: ft_strchr(argv[g_optind], g_optopt)[1];
	if (!ft_strchr(optstring, g_optopt))
		return (st_error(UNKNOWN));
	if (ft_strchr(optstring, g_optopt)[1] == ':')
	{
		if ((*(g_optarg = ft_strchr(argv[g_optind++], g_optopt) + 1) != '\0' ||
					((g_optarg = (char *)argv[g_optind++]) != NULL
					 && ft_strcmp(g_optarg, "--"))) && (g_optreset = 1))
			return (g_optopt);
		g_optarg = NULL;
		return (st_error(MISSING_ARG));
	}
	if (ft_strchr(optstring, g_optopt)[1] == '\0' && (g_optreset = 1))
		g_optind++;
	return (g_optopt);
}
