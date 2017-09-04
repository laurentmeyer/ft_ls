#include "ft_ls.h"

char		*make_full_path(char *dirname, char *basename)
{
	char	*res;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(dirname);
	l2 = ft_strlen(basename);

	if (!(res = (char *)malloc(l1 + l2 + 2)))
		exit_msg("make_full_path malloc failed");
	memcpy(res, dirname, l1);
	res[l1] = '/';
	memcpy(res + l1 + 1, basename, l2 + 1);
	return (res);
}
