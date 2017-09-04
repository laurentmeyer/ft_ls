#include "ft_ls.h"

t_file		*t_file_new(char *path, char *name, struct stat *statbuf)
{
	t_file	*new;

	if (!(new = (t_file *)malloc(sizeof(t_file)))
			|| !(new->dirname = ft_strdup(path))
			|| !(new->basename = ft_strdup(name)))
		exit_msg("struct s_file memory allocation failed\n");
	ft_memcpy(&(new->stat), statbuf, sizeof(struct stat));
	return (new);
}
