#include "ft_ls.h"

extern char	*g_optarg;
extern int	g_optind;
extern int	g_optopt;
extern int	g_opterr;
extern int	g_optreset;

int		get_options(t_options *options, int ac, char **av)
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
	return (g_optind);
}
