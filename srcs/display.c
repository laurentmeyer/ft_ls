#include "ft_ls.h"

static void		display_file_name(t_list *elem)
{
	ft_printf("%s\n", ((t_file *)(elem->content))->basename);
}

static t_listdisplay	*select_display_function(t_options *options)
{
	(void)options;
	return (&display_file_name);
}

static inline void	sort_dir_contents(t_list **alst, t_options *options)
{
	t_listcmp		*f;

	f = select_sort_function(options);
	ft_lstsort(alst, f);
}

void				display_dir_contents(char *dirpath, t_options *options)
{
	t_list			*children;

	children = NULL;
	if (list_contents(dirpath, &children) == NOT_DIRECTORY)
	{
		ft_printf("%s is not a directory\n", dirpath);
		return ;
	}
	sort_dir_contents(&children, options);
	ft_lstiter(children, select_display_function(options));
	//if (!options->recursive || !*children)
	//	return ;
	//child_ptr = children;
	//while (child_ptr)
	//{
	//}
}
