#include <unistd.h>
#include <sys/types.h>	// pour fts.h
#include <sys/stat.h>
#include <fts.h>		//pour fts.h
#include "ft_ls.h"
#include "ft_printf.h"

#define g_optarg optarg
#define g_optind optind
#define g_optopt optopt
#define g_opterr opterr
#define g_optreset optreset
#define ft_getopt getopt

#define ftslite fts
///Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/fts.h

static int	read_args(int argc, char **argv)
{
	int	ch;
	int	res;

	res = 0;
	while ((ch = ft_getopt(argc, argv, "alRrt")) != -1) {
		if (ch == 'a')
			res |= DISPLAY_DOTS;
		else if (ch == 'l')
			res |= DISPLAY_LONG;
		else if (ch == 'R')
			res |= RECURSIVE;
		else if (ch == 'r')
			res |= SORT_REVERSE;
		else if (ch == 't')
			res |= SORT_TIMEMOD;
		else
			ft_printf("unknown option: %c", ch); // a faire evoluer, gerer erreurs etc
	}
	argc -= g_optind;
	argv += g_optind;
	return (res);
}



int			main(int argc, char **argv)
{
	char	*files[argc];
	char	*dirs[argc];
	int 	options;

	//ft_printf("%d\n", g_optind);
	ft_printf("=================\n");
	options = read_args(argc, argv);
	ft_printf("%d\n",options);
	//ft_printf("%d\n", S_IFWHT);
	ft_printf("g_optarg = %s\n", g_optarg);
	ft_printf("g_optind = %d\n", g_optind);
	ft_printf("g_optopt = %c\n", g_optopt);
	ft_printf("g_opterr = %d\n", g_opterr);
	ft_printf("g_optreset = %d\n", g_optreset);
	ft_printf("il reste %d arguments\n", argc - g_optind);
	argc -= g_optind;
	argv += g_optind;
	return (0);
}
