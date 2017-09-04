#include "ft_ls.h"

void	exit_msg(char *str)
{
	ft_dprintf(STDERR, "%s", str);
	exit(EXIT_FAILURE);
}

void	exit_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
