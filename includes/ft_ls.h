/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:40:01 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/02 19:16:36 by lmeyer           ###   ########.fr       */
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
# include <string.h> 
# include <errno.h> 
# define _DARWIN_NO_64_BIT_INODE
# define FALSE 0
# define TRUE !FALSE
# define SUCCESS 0
# define ERROR -1
# define NOT_DIRECTORY -2
# define NO_RIGHTS -3
# define STDERR 2

typedef int				(t_statf)(const char *path, struct stat *buf);
typedef int				(t_cmpf)(void *, void *);

typedef struct			s_options {
	int					sort_reverse : 1;
	int					sort_timemod : 1;
	int					display_dots : 1;
	int					display_long : 1;
	int					display_headers : 1;
	int					recursive : 1;
	t_listcmp			*cmp_f;
	t_statf				*stat_f;
}						t_options;

typedef struct			s_file {
	char				*path;
	char				*error;
	struct stat			stat;
}						t_file;

void					ft_ls(t_file *parent, t_options *options);
int						get_options(t_options *options, int ac, char **av);
void					add_t_file_to_list(char *fullpath, t_list **alst,
		t_options *options);
t_list					*t_file_lstnew(char *path, struct stat *statbuf);
void					t_file_lstdel(void *l, size_t size);
char					*make_full_path(char *dirname, char *basename);
void					list_dir_contents(t_file *file, t_list **alst,
		t_options *options);
void					exit_msg(char *str);
void					exit_perror(char *str);
void					display_children(t_list *children, t_options *options);
void					display_parent_and_children(t_file *parent, t_list *children,
		t_options *options);
int						cmp_names(t_list *l1, t_list *l2);
int						cmp_timemod(t_list *l1, t_list *l2);

#endif
