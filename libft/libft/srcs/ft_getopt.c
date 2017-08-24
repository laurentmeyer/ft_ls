/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:34:00 by lmeyer            #+#    #+#             */
/*   Updated: 2017/05/23 14:52:10 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#define UNKNOWN 0
#define MISSING_ARG 1

char	*g_optarg;
int		g_optind = 1;
int		g_optopt;
int		g_opterr = 1;
int		g_optreset;

int			ft_getopt(int argc, char **argv, const char *optstring)
{
	static char *curarg_ptr = NULL;
	char		*optstr_ptr;
	
	if (g_optreset || curarg_ptr == NULL)
	{
		g_optreset = 0;
		if (g_optind >= argc || (curarg_ptr = (argv[g_optind]))[0] != '-')
		{
			curarg_ptr = NULL;
			return (-1);
		}
		if (curarg_ptr[1] && (++curarg_ptr)[0] == '-') 
		{
			g_optind++;
			curarg_ptr = NULL;
			return (-1);
		}
	}
	if ((g_optopt = (int)(*curarg_ptr++)) == (int)':' ||
			(optstr_ptr = ft_strchr(optstring, g_optopt)) == NULL)
	{
		if (g_optopt == (int)'-')
			return (-1);
		if (curarg_ptr[0] == '\0')
			g_optind++;
		if (g_opterr && optstring[0] != ':')
			ft_fprintf(stderr, "illegal option -- %c\n", g_optopt);
		return ('?');
	}
	if ((++optstr_ptr)[0] != ':')
	{
		g_optarg = NULL;
		if (curarg_ptr[0] == '\0')
			g_optind++;
	}
	else
	{
		if (curarg_ptr[0] != '\0')
			g_optarg = curarg_ptr;
		else if (++g_optind >= argc)
		{
			curarg_ptr = NULL;
			if (optstring[0] == ':')
				return (':');
			if (g_opterr)
				ft_fprintf(stderr, "illegal option -- %c\n", g_optopt);
			return ('?');
		}
		else
			g_optarg = argv[g_optind];
		curarg_ptr = NULL;
		++g_optind;
	}
	return (g_optopt);
}
