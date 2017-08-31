#include "ft_ls.h"

static void				display_file_name(t_list *elem)
{
	ft_printf("%s\n", ((t_file *)(elem->content))->basename);
}

static t_listdisplay	*select_display_function(t_options options)
{
	(void)options;
	return (&display_file_name);
}

int						display_dir_contents(char *dirpath, t_options options)
{
	t_list			*children;

	children = NULL;
	if (list_and_order_dir_contents(dirpath, &children, options) == ERROR)
		return (ERROR);
	ft_lstiter(children, select_display_function(options));
	return (0);
}
