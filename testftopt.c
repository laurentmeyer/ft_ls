#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char	*g_optarg;
extern int	g_optind;
extern int	g_optopt;
extern int	g_opterr;
extern int	g_optreset;

int		main (int argc, char **argv)
{
	int aflag = 0;
	int bflag = 0;
	char *cvalue = NULL;
	int index;
	int c;

	//opterr = 0;
	while ((c = ft_getopt (argc, argv, "abc:")) != -1)
		switch (c)
		{
			case 'a':
				aflag = 1;
				break;
			case 'b':
				bflag = 1;
				break;
			case 'c':
				cvalue = g_optarg;
				break;
	//		case '?':
	//			if (optopt == 'c')
	//				fprintf (stderr, "Option -%c requires an argument.\n", g_optopt);
	//			else if (isprint (g_optopt))
	//				fprintf (stderr, "Unknown option `-%c'.\n", g_optopt);
	//			else
	//				fprintf (stderr,
	//						"Unknown option character `\\x%x'.\n",
	//						g_optopt);
				return 1;
			default:
				abort ();
		}
	printf ("aflag = %d, bflag = %d, cvalue = %s\n",
			aflag, bflag, cvalue);

	for (index = g_optind; index < argc; index++)
	//	printf ("Non-option argument %s\n", argv[index]);
	return 0;
}
