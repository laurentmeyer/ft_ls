#include "ft_ls.h"

t_file		*t_file_new(char *path, char *name, struct stat *statbuf)
{
	t_file	*new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (!(new->dirname = ft_strdup(path)))
	{
		free(new);
		return (NULL);
	}
	if (!(new->basename = ft_strdup(name)))
	{
		free(new->dirname);
		free(new);
		return (NULL);
	}
	ft_memcpy(&(new->stat), statbuf, sizeof(struct stat));
	return (new);
}
