/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:40:01 by lmeyer            #+#    #+#             */
/*   Updated: 2017/09/07 18:49:41 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <stdio.h>
# include <dirent.h>

# define _DARWIN_NO_64_BIT_INODE
# define FALSE 0
# define TRUE !FALSE
# define SUCCESS 0
# define ERROR -1
# define NOT_DIRECTORY -2
# define NO_RIGHTS -3
# define STDERR 2

typedef struct			s_options {
	int					sort_reverse : 1;
	int					sort_timemod : 1;
	int					display_dots : 1;
	int					display_long : 1;
	int					display_headers : 1;
	int					recursive : 1;
}						t_options;

typedef struct			s_file {
	char				*path;
	struct stat			stat;
}						t_file;

typedef void			(t_displayf)(t_list *elem);
typedef void			(t_sortf)(t_list *elem);

t_list					*t_file_lstnew(char *path, struct stat *statbuf);
void					t_file_lstdel(void *l, size_t size);
t_listcmp				*select_sort_function(t_options *options);
t_options				get_options(int *argc_ptr, char ***argv_ptr);
char					*make_full_path(char *dirname, char *basename);
void					display_dir_contents(char *dirpath, t_options *options);
int						list_dir_contents(char *dirpath, t_list **alst,
		t_options *options);
int						insert_ordered(t_file *file,
		t_list **alst, t_options opt);
void					exit_msg(char *str);
void					exit_perror(char *str);

#endif
