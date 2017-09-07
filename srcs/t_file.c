#include "ft_ls.h"

void		t_file_lstdel(void *content, size_t size)
{
	(void)size;
	free(((t_file *)content)->path);
	free((t_file *)content);
}

t_list		*t_file_lstnew(char *path, struct stat *statbuf)
{
	t_file	new;
	t_list	*ret;

	if (!(new.path = ft_strdup(path)))
		exit_msg("t_file creation failed\n");
	ft_memcpy(&(new.stat), statbuf, sizeof(struct stat));
	if (!(ret = ft_lstnew(&new, sizeof(t_file))))
		exit_msg("ft_lstnew failed\n");
	return (ret);
}
