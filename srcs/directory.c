#include "ft_ls.h"

int			insert_ordered(t_file *file, t_list **alst, t_options opt)
{
	t_list		*new;
	t_list		*cur;
	t_list		*tmp;
	t_listcmp	*f;

	if (!alst || !(new = ft_lstnew(file, sizeof(t_file))))
		return (ERROR);
	f = select_sort_function(opt);
	cur = *alst;
	if (!cur || (*f)(new, cur) <= 0)
		ft_lstadd(alst, new);
	else
	{
		while ((tmp = cur->next) && (*f)(new, tmp) > 0)
			cur = tmp;
		cur->next = new;
		new->next = tmp;
	}
	return (0);
}

int			list_and_order_dir_contents(char *path, t_list **alst,
											t_options options)
{
	DIR				*dirp;
	struct dirent	*dir;
	struct stat		statbuf;
	char			*fpath;
	int				err;

	if ((dirp = opendir(path)) == NULL)
		return (ERROR);
	err = 0;
	while ((dir = readdir(dirp)))
	{
		if (!(fpath = make_full_path(path, dir->d_name)) && (err = ERROR))
			break ;
		if ((err = stat(fpath, &statbuf)) == ERROR)
			perror(NULL);
		free(fpath);
		if (err == ERROR)
			break ;
		if ((err = insert_ordered(t_file_new(path, dir->d_name, &statbuf),
						alst, options)) == ERROR)
			break;
	}
	return (closedir(dirp) == ERROR || err == ERROR ? ERROR : 0);
}
