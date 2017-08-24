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

static int	return_getopt(int retval, int incr, char **cur_arg_addr, int reset)
{
	return (retval);
}

int			ft_getopt(int argc, const char **argv, const char *optstring)
{
	static char *cur_arg_ptr = "";
	char		*optstr_ptr;
	
	//logique generale : on avance dans la liste des arguments qu'on cherche dans optstr
	//si reset, on recommence la recherche au debut du groupe d'options en cours
	//si le groupe d'arguments étudié ne commence pas par - , terminé
	//si le groupe d'options en cours est épuisé, on passe au suivant
	//si on a dépassé le nombre d'argc, terminé
	//si on rencontre --, terminé
	//si l'option étudiée nécessite un argument et qu'il n'y en a pas, retourne ?
	//si l'option étudiée ne se trouve pas dans optstr, retourne ?

	//reset ou initialisation
	if (g_optreset || cur_arg_ptr[0] == '\0')
	{
		g_optreset = 0;
		//remise au début du pointeur
		cur_arg_ptr = argv[g_optind];
		// verification et avancement du pointeur
		if (cur_arg_ptr[0] != '-' || g_optind >= argc)
			return (return_getopt(-1, 0, &cur_arg_ptr, 1));
		++cur_arg_ptr;
		if (cur_arg_ptr[0] == '-')
			return (return_getopt(-1, 0, &cur_arg_ptr, 1));
	}

	// on evalue la prochaine option et avance du cusreur
	g_optopt = (int)cur_arg_ptr[0];
	++cur_arg_ptr;
	optstr_ptr = ft_strchr(optstring, g_optopt);

	//cas ou on renvoie '?'
	if (g_optopt == (int)':' || !optstr_ptr)
	{
		if (g_opterr && optstring[0] == ':')
			fprintf(stderr, "%s: option requires an argument -- %c\n",
					argv[0], g_optopt); // a changer avec un fprintf maison
		if (cur_arg_ptr[0] == '\0')
			++g_optind;
		return ((int)'?');
	}

	// cas ou il n'y a pas besoin d'argument
	if (optstr_ptr[1] != ':')
	{
		g_optarg = NULL;
		// on change de groupe d'arguments si besoin
		if (


	// cas d'erreur
	if (

		//	if (cur_arg_ptr[0] == '\0' && (g_optind >= argc || (cur_arg_ptr =
		//		argv[g_optind]) != '-' || (cur_arg_ptr[1] && (++cur_arg_ptr)[0]) == '-'))
		//	{
		//		cur_arg_ptr = "";
		//		return (-1);
		//	}
		if ((g_optopt = (int)cur_arg_ptr[0]) == (int)':' ||
				(optstr_ptr = ft_strchr(optstring, g_optopt)) == NULL)
		{
			if (g_optopt == (int)'-')
				return (-1);
			cur_arg_ptr++;
			if (cur_arg_ptr[0] == '\0')
				g_optind++;
			if (optstring[0] != ':' && g_opterr == 1)
				ft_fprintf(stderr, "%s: illegal option -- %c\n", argv[0], g_optopt);
			return ((int)'?');
		}
	if ((++optstr_ptr)[0] != ':')
	{
		g_optarg = NULL;
		if (cur_arg_ptr[0] == '\0')
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
