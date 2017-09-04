#include "ft_ls.h"

//int			insert_ordered(t_file *file, t_list **alst, t_options opt)
//{
//	t_list		*new;
//	t_list		*cur;
//	t_list		*tmp;
//	t_listcmp	*f;
//
//	if (!alst || )
//		exit_msg("cannot insert new item in list\n");
//	f = select_sort_function(opt);
//	cur = *alst;
//	if (!cur || (*f)(new, cur) <= 0)
//		ft_lstadd(alst, new);
//	else
//	{
//		while ((tmp = cur->next) && (*f)(new, tmp) > 0)
//			cur = tmp;
//		cur->next = new;
//		new->next = tmp;
//	}
//	return (0);
//}

int			list_contents(char *path, t_list **alst)
{
	DIR				*dirp;
	struct dirent	*dir;
	struct stat		statbuf;
	char			*fpath;
	t_list			*new;

	if (stat(path, &statbuf) == ERROR)
		exit_perror(NULL);
	if (!S_ISDIR(statbuf.st_mode))
		return (NOT_DIRECTORY);
	if ((dirp = opendir(path)) == NULL)
		exit_perror(NULL);
	while ((dir = readdir(dirp)))
	{
		fpath = make_full_path(path, dir->d_name);
		if (stat(fpath, &statbuf) == ERROR)
			exit_perror(NULL);
		free(fpath);
		if (!(new = ft_lstnew(t_file_new(path, dir->d_name, &statbuf),
						sizeof(t_file))))
			exit_msg("struct s_list memory allocation failed\n");
		ft_lstadd(alst, new);
	}
	return (closedir(dirp));
}
