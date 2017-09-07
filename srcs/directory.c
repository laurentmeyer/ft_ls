#include "ft_ls.h"

void		add_t_file_to_list(char *fullpath, t_list **alst)
{
	struct stat		statbuf;
	t_list			*new;

	if (lstat(fullpath, &statbuf) == ERROR) // stat vs lstat
		exit_perror(NULL);
	if (!(new = t_file_lstnew(fullpath, &statbuf)))
		exit_msg("struct s_list memory allocation failed\n");
	ft_lstadd(alst, new);
}

//int			list_args(char *path, t_list **alst)
//{
//	DIR				*dirp;
//	struct dirent	*dir;
//	struct stat		statbuf;
//	char			*fpath;
//	t_list			*new;
//
//	if (stat(path, &statbuf) == ERROR)
//		exit_perror(NULL);
//	if (!S_ISDIR(statbuf.st_mode))
//		return (NOT_DIRECTORY);
//	if ((dirp = opendir(path)) == NULL)
//		exit_perror(NULL);
//	while ((dir = readdir(dirp)))
//	{
//		fpath = make_full_path(path, dir->d_name);
//		if (stat(fpath, &statbuf) == ERROR)
//			exit_perror(NULL);
//		free(fpath);
//		if (!(new = t_file_lstnew(fpath, &statbuf)))
//			exit_msg("struct s_list memory allocation failed\n");
//		ft_lstadd(alst, new);
//	}
//	return (closedir(dirp));
//}

int			list_dir_contents(char *dirpath, t_list **alst, t_options *options)
{
	DIR				*dirp;
	struct dirent	*dir;
	struct stat		statbuf;
	char			*fpath;

	if (lstat(dirpath, &statbuf) == ERROR)	// stat vs lstat
		exit_perror(NULL);					// faux ne doit pas être bloquant
	if (!S_ISDIR(statbuf.st_mode))
		return (NOT_DIRECTORY);
	if (options->display_headers)
		ft_printf("\n%s:\n", dirpath);
	if ((dirp = opendir(dirpath)) == NULL)
	{
		perror(NULL);
		return (NO_RIGHTS);
	}
	while ((dir = readdir(dirp)))
	{
		fpath = make_full_path(dirpath, dir->d_name);
		if (options->display_dots || *(dir->d_name) != '.')
			add_t_file_to_list(fpath, alst);
		free(fpath);
	}
	return (closedir(dirp));
}
