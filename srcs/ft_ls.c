#include "ft_ls.h"

int			list_and_order_args(int argc, char **argv,
									t_list **alst, t_options options)
{
	struct stat		statbuf;
	int				err;

	err = 0;
	while (argc--)
	{
		if ((err = stat(argv[argc], &statbuf)) == ERROR)
		{
			perror(NULL);
			break ;
		}
		if ((err = insert_ordered(t_file_new(".", argv[argc], &statbuf),
						alst, options)) == ERROR)
			break;
	}
	return (err);
}

int			main(int argc, char **argv)
{
	t_options 	options;

	options = get_options(&argc, &argv); // rajouter une gestion d'erreurs
	display_dir_contents(argv[0], &options); // en attendant de gerer multiargs

	//t_list		*arglist;
	//if (argc > 1)
	//{
	//	if (list_and_order_args(argc, argv, &arglist, options) == ERROR)
	//		return (ERROR);
	//}
	//else
	//{
	//	if (display_dir_contents(argv[0], options) == ERROR)
	//		return (ERROR);
	//}

	return (0);
}
