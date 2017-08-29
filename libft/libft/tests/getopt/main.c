#include "libft.h"
#include "ft_printf.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char	*g_optarg;
extern int	g_optind;
extern int	g_optopt;
extern int	g_opterr;
extern int	g_optreset;


extern char *optarg;
extern int optind;
extern int optopt;
extern int opterr;
extern int optreset;

static void	printargs(int ac, char **av)
{
	int i;

	i = 0;
	ft_printf("\narguments = ");
	while (++i < ac)
		ft_printf("%s ", av[i]);
	ft_printf("\n\n");
}

void		print_values(void)
{
	char	s1[20] = { 0 };
	char	s2[20] = { 0 };

	snprintf(s1, 20, "%s", optarg);
	snprintf(s2, 20, "%s", g_optarg);
	if (strcmp(s1, s2))
		printf("Optarg: UNIX: %s  | FT : %s\n", s1, s2);
	snprintf(s1, 20, "%d", optind);
	snprintf(s2, 20, "%d", g_optind);
	if (strcmp(s1, s2))
		printf("Optind: UNIX: %s  | FT : %s\n", s1, s2);
	snprintf(s1, 20, "%c", optopt);
	snprintf(s2, 20, "%c", g_optopt);
	if (strcmp(s1, s2))
		printf("optopt: UNIX: %s  | FT : %s\n", s1, s2);
	snprintf(s1, 20, "%d", opterr);
	snprintf(s2, 20, "%d", g_opterr);
	if (strcmp(s1, s2))
		printf("opterr: UNIX: %s  | FT : %s\n", s1, s2);
	snprintf(s1, 20, "%d", optreset);
	snprintf(s2, 20, "%d", g_optreset);
	if (strcmp(s1, s2))
		printf("optreset: UNIX: %s  | FT : %s\n", s1, s2);
//	ft_printf("%.10s| UNIX: | FT:\n%10s%10s\n", "Optarg:", optarg, g_optarg);
//	ft_printf("%.10s| UNIX: | FT:\n%10d%10d\n", "Optind:", optind, g_optind);
//	ft_printf("%.10s| UNIX: | FT:\n%10c%10c\n", "Optopt:", optopt, g_optopt);
//	ft_printf("%.10s| UNIX: | FT:\n%10d%10d\n", "Opterr:", opterr, g_opterr);
//	ft_printf("%.10s| UNIX: | FT:\n%10d%10d\n\n", "Optreset:", optreset, g_optreset);
}

int			main(int argc, char **argv)
{
	int		c;
	int		d;
	char	*optstring = "abc:";
	char	s1[20] = { 0 };
	char	s2[20] = { 0 };

	printargs(argc, argv);
	print_values();
	while ((c = getopt(argc, argv, optstring)) != -1)
	{
		d = ft_getopt(argc, argv, optstring);
		snprintf(s1, 20, "%c", c);
		snprintf(s2, 20, "%c", d);
		if (strcmp(s1, s2))
			printf("Return: UNIX: %s  | FT : %s\n", s1, s2);
		print_values();
	}
	d = ft_getopt(argc, argv, optstring);
	snprintf(s1, 20, "%c", c);
	snprintf(s2, 20, "%c", d);
	if (strcmp(s1, s2))
		printf("Return: UNIX: %s  | FT : %s\n", s1, s2);
	print_values();
	return (0);
}
