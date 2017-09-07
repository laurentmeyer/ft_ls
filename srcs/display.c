#include "ft_ls.h"

static void		display_file_name(t_list *elem)
{
	ft_printf("%s\n", (ft_basename(((t_file *)(elem->content))->path)));
//	char	*basename;
//
//	basename = ft_basename(((t_file *)(elem->content))->path);
//	if (*basename != '.')
//		ft_printf("%s\n", basename);
}

//static void		display_dots(t_list *elem)
//{
//	ft_printf("%s\n", (ft_basename(((t_file *)(elem->content))->path)));
//}

static t_listdisplay	*select_display_function(t_options *options)
{
//	if (options->display_dots)
//		return (&display_dots);
	(void)options;
	return (&display_file_name);
}

static inline void	sort_dir_contents(t_list **alst, t_options *options)
{
	t_listcmp		*f;

	f = select_sort_function(options);
	ft_lstsort(alst, f);
}

static void			recurse_display_dir_contents(t_list *children,
		t_options *options)
{
	char			*child_path;

	options->display_headers = 1;
	while (children)
	{
		child_path = ((t_file *)(children->content))->path;
		if (!ft_strequ(ft_basename(child_path), ".")
				&& !ft_strequ(ft_basename(child_path), ".."))
			display_dir_contents(child_path, options);
		children = children->next;
	}
}

void				display_dir_contents(char *dirpath, t_options *options)
{
	t_list			*children;
	int				list_res;

	children = NULL;
	if ((list_res = list_dir_contents(dirpath, &children, options))
			== NOT_DIRECTORY)
		return ;
	if (list_res == NO_RIGHTS || !children)
		return ;
	sort_dir_contents(&children, options);
	ft_lstiter(children, select_display_function(options));
	if (options->recursive)
		recurse_display_dir_contents(children, options);
	ft_lstdel(&children, &t_file_lstdel);
}
