#include "ft_ls.h"

extern char	*g_optarg;
extern int	g_optind;
extern int	g_optopt;
extern int	g_opterr;
extern int	g_optreset;

t_options	get_options(int *argc_ptr, char ***argv_ptr)
{
	int			ch;
	t_options	options;

	ft_bzero(&options, sizeof(t_options));
	while ((ch = ft_getopt(*argc_ptr, *argv_ptr, "alRrt")) != -1)
	{
		if (ch == 'a')
			options.display_dots = 1;
		else if (ch == 'l')
			options.display_long = 1;
		else if (ch == 'R')
			options.recursive = 1;
		else if (ch == 'r')
			options.sort_reverse = 1;
		else if (ch == 't')
			options.sort_timemod = 1;
	}
	*argc_ptr -= g_optind;
	*argv_ptr += g_optind;
	return (options);
}
