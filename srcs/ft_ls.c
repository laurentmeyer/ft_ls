#include "ft_ls.h"

void		handle_multi_args(int argc, char **argv, t_options *options)
{
	(void)argc;
	(void)argv;
	(void)options;
//	struct stat		statbuf;
//	int				err;
//
//	err = 0;
//	while (argc--)
//	{
//		if ((err = stat(argv[argc], &statbuf)) == ERROR)
//		{
//			perror(NULL);
//			break ;
//		}
//		if ((err = insert_ordered(t_file_new(".", argv[argc], &statbuf),
//						alst, options)) == ERROR)
//			break;
//	}
//	return (err);
}

int			main(int argc, char **argv)
{
	t_options 	options;
	int			arg_pos;
	//t_list		*args;

	arg_pos = get_options(&options, argc, argv); // rajouter une gestion d'erreurs
	if (arg_pos == argc)
		display_dir_contents(".", &options);
	else if (argc - arg_pos == 1)
		display_dir_contents(argv[arg_pos], &options);
	else if (argc - arg_pos > 1)
		handle_multi_args(argc, argv, &options);
//	while (1)
//		;
	return (0);
}
