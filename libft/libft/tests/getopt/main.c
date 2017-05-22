#include "libft.h"
#include "ft_printf.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char	*g_optarg;
extern int	g_optind;
extern int	g_optopt;
extern int	g_opterr;
extern int	g_optreset;

static void	printargs(int ac, char **av)
{
	int i;

	i = 0;
	ft_printf("arguments = ");
	while (++i < ac)
		ft_printf("%s ", av[i]);
	ft_printf("\n");
}

int			main(int argc, char **argv)
{
	int		c;
	int		d;
	int		nb_errs;

	nb_errs = 0;
	printargs(argc, argv);
	opterr = 0;				//à vérifier
	g_opterr = 0;			//à vérifier
	//if (optarg && g_optarg && ft_strcmp(optarg, g_optarg))
		nb_errs += ft_printf("Optarg: UNIX: %s | FT: %s\n", optarg, g_optarg);
	//if (optind != g_optind)
		nb_errs += ft_printf("Optind: UNIX: %d | FT: %d\n", optind, g_optind);
	//if (optopt != g_optopt)
		nb_errs += ft_printf("Optopt: UNIX: %c | FT: %c\n", optopt, g_optopt);
	//if (opterr != g_opterr)
		nb_errs += ft_printf("Opterr: UNIX: %d | FT: %d\n", opterr, g_opterr);
	//if (optreset != g_optreset)
		nb_errs += ft_printf("Optreset: UNIX: %d | FT: %d\n", optreset, g_optreset);
	if (nb_errs)
		ft_printf("\n");
	nb_errs = 0;
	while ((c = getopt(argc, argv, "abc:")) != -1)
	{
		printf("coucou\n");
		d = ft_getopt(argc, argv, "abc:");
		printf("cca va ?\n");
		//if (c != d)
			nb_errs += ft_printf("Return value: UNIX: %c | FT: %c\n", c, d);
		//if (optarg && g_optarg && ft_strcmp(optarg, g_optarg))
			nb_errs += ft_printf("Optarg: UNIX: %s | FT: %s\n", optarg, g_optarg);
		//if (optind != g_optind)
			nb_errs += ft_printf("Optind: UNIX: %d | FT: %d\n", optind, g_optind);
		//if (optopt != g_optopt)
			nb_errs += ft_printf("Optopt: UNIX: %c | FT: %c\n", optopt, g_optopt);
		//if (opterr != g_opterr)
			nb_errs += ft_printf("Opterr: UNIX: %d | FT: %d\n", opterr, g_opterr);
		//if (optreset != g_optreset)
			nb_errs += ft_printf("Optreset: UNIX: %d | FT: %d\n", optreset, g_optreset);
		if (nb_errs)
			ft_printf("\n");
		nb_errs = 0;
	}
	d = ft_getopt(argc, argv, "abc:");
	//if (c != d)
		nb_errs += ft_printf("Return value: UNIX: %d | FT: %d\n", c, d);
	//if (optarg && g_optarg && ft_strcmp(optarg, g_optarg))
		nb_errs += ft_printf("Optarg: UNIX: %s | FT: %s\n", optarg, g_optarg);
	//if (optind != g_optind)
		nb_errs += ft_printf("Optind: UNIX: %d | FT: %d\n", optind, g_optind);
	//if (optopt != g_optopt)
		nb_errs += ft_printf("Optopt: UNIX: %c | FT: %c\n", optopt, g_optopt);
	//if (opterr != g_opterr)
		nb_errs += ft_printf("Opterr: UNIX: %d | FT: %d\n", opterr, g_opterr);
	//if (optreset != g_optreset)
		nb_errs += ft_printf("Optreset: UNIX: %d | FT: %d\n", optreset, g_optreset);
	if (nb_errs)
		ft_printf("\n");
	nb_errs = 0;
	return (0);
}

//int			old(int argc, char **argv)
//{
//	int aflag = 0;
//	int bflag = 0;
//	char *cvalue = NULL;
//	int index;
//	int c;
//
//	opterr = 0;
//	while ((c = getopt (argc, argv, "abc:")) != -1)
//		switch (c)
//		{
//			case 'a':
//				aflag = 1;
//				break;
//			case 'b':
//				bflag = 1;
//				break;
//			case 'c':
//				cvalue = optarg;
//				break;
//			case '?':
//				if (optopt == 'c')
//					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
//				else if (isprint (optopt))
//					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
//				else
//					fprintf (stderr,
//							"Unknown option character `\\x%x'.\n",
//							optopt);
//				return 1;
//			default:
//				abort ();
//		}
//	printf ("aflag = %d, bflag = %d, cvalue = %s\n",
//			aflag, bflag, cvalue);
//
//	for (index = optind; index < argc; index++)
//		printf ("Non-option argument %s\n", argv[index]);
//	return 0;
//}
