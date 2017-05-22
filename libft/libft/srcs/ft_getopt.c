/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:34:00 by lmeyer            #+#    #+#             */
/*   Updated: 2017/05/22 19:21:13 by lmeyer           ###   ########.fr       */
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

int			ft_getopt(int argc, const char **argv, const char *optstring)
{
	static char *current = "";
	char		*index;

	if (g_optreset || current[0] = '\0')
	{
		g_optreset = 0;
		if (g_optind >= argc || (current = argv[g_optind])[0] != '-'
				|| (current[1] && (++current)[0] == '-'))
		{
			current = "";
			return (-1);
		}
	}
	if ((g_optopt = (int)(current++)[0]) == (int)':' ||
			(index = ft_strchr(optstring, g_optopt)) == NULL)
	{
		if (g_optopt == (int)'-')
			return (-1);
		if (current[0] == '\0')
			g_optind++;
		if (optstring[0] != ':' && g_opterr == 1)
			ft_fprintf(stderr, "%s: illegal option -- %c\n", argv[0], g_optopt);
		return ((int)'?');
	}
	if ((++index)[0] != ':')
	{
		g_optarg = NULL;
		if (current[0] == '\0')
			g_optind++;
	}








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
