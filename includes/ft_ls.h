/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:40:01 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/15 17:10:26 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <uuid/uuid.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# define _DARWIN_NO_64_BIT_INODE
# define FALSE 0
# define TRUE !FALSE
# define SUCCESS 0
# define ERROR -1
# define NOT_DIRECTORY -2
# define NO_RIGHTS -3
# define STDERR 2
# define PERMISSIONS_BUF_LEN 11
# define DATE_BUF_LEN        13
# define MAX_FORMAT sizeof("%%s  %%-%dd %%-%ds  %%-%ds %%%dd,  %%%dd %%s ")

typedef int				(t_statf)(const char *path, struct stat *buf);
typedef int				(t_cmpf)(void *, void *);

typedef struct			s_format {
	int					p_link;
	int					p_name;
	int					p_group;
	int					p_major;
	int					p_minor;
	int					p_size;
	int					p_total;
	char				format_std[MAX_FORMAT];
	char				format_dev[MAX_FORMAT];
}						t_format;

typedef struct			s_options {
	int					sort_reverse : 1;
	int					sort_timemod : 1;
	int					display_dots : 1;
	int					display_long : 1;
	int					display_headers : 1;
	int					recursive : 1;
	int					first_display : 1;
	int					files_done : 1;
	t_format			*format;
	t_listcmp			*cmp_f;
	t_statf				*stat_f;
}						t_options;

typedef struct			s_file {
	char				*path;
	char				*error;
	struct stat			stat;
	t_options			*options;
}						t_file;

int						is_hidden(t_file *file);
void					ft_ls(t_file *parent);
int						get_options(t_options *options, int ac, char **av);
void					add_t_file_to_list(char *fullpath, t_list **alst,
		t_options *options);
//t_list		*t_file_lstnew(char *path, struct stat *statbuf, t_options *options)
//t_list					*t_file_lstnew(char *path, struct stat *statbuf);
void					t_file_lstdel(void *l, size_t size);
char					*make_full_path(char *dirname, char *basename);
void					list_dir_contents(t_file *file, t_list **alst);
void					exit_msg(char *str);
void					exit_perror(char *str);
void					display_children(t_list *children);
void					display_parent_and_children(t_file *parent,
		t_list *children);
int						cmp_names(t_list *l1, t_list *l2);
int						cmp_timemod(t_list *l1, t_list *l2);
void					print_filename(t_file *child);
void					display_long(t_list *children);

#endif
