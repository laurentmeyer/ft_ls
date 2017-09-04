#include "ft_ls.h"

//t_file		*t_file_new(char *path, char *name, struct stat *statbuf)
//{
//	t_file	*new;
//
//	if (!(new = (t_file *)malloc(sizeof(t_file)))
//			|| !(new->dirname = ft_strdup(path))
//			|| !(new->basename = ft_strdup(name)))
//		exit_msg("struct s_file memory allocation failed\n");
//	ft_memcpy(&(new->stat), statbuf, sizeof(struct stat));
//	return (new);
//}

t_list		*t_file_lstnew(char *path, char *name, struct stat *statbuf)
{
	t_file	new;
	t_list	*ret;

	if (!(new.dirname = ft_strdup(path))
			|| !(new.basename = ft_strdup(name)))
		exit_msg("t_file creation failed\n");
	ft_memcpy(&(new.stat), statbuf, sizeof(struct stat));
	if (!(ret = ft_lstnew(&new, sizeof(t_file))))
		exit_msg("ft_lstnew failed\n");
	return (ret);
}
