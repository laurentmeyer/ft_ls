/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:51:56 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/14 11:36:10 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define PERMISSIONS_BUF_LEN 11
#define DATE_BUF_LEN        13
#define SECS_IN_6_MONTHS    365 / 2 * 24 * 3600
#define PRECISIONS_COUNT    4
#define LINK 0
#define NAME 1
#define GROUP 2
#define SIZE 3

static int		max(int a, int b)
{
	return ((a > b) ? a : b);
}

static int		format_str(char **format, t_list *children, t_options *options)
{
	int			total;
	int			m[PRECISIONS_COUNT];
	struct stat	s;

	ft_bzero(m, sizeof(m));
	total = 0;
	while (children)
	{
		if (options->display_dots
				|| *(ft_basename(((t_file *)(children->content))->path)) != '.')
		{
			s = ((t_file *)(children->content))->stat;
			m[LINK] = max(ft_intlen(s.st_nlink), m[LINK]);
			m[NAME] = max(ft_strlen(getpwuid(s.st_uid)->pw_name), m[NAME]);
			m[GROUP] = max(ft_strlen(getpwuid(s.st_uid)->pw_name), m[GROUP]);
			m[SIZE] = max(ft_intlen(s.st_size), m[SIZE]);
			total += s.st_blocks;
		}
		children = children->next;
	}
	ft_asprintf(format, "%%s  %%%dd %%%ds  %%%ds  %%%dd %%s ",
			m[LINK], m[NAME], m[GROUP], m[SIZE]);
	return (total);
}

static void		permissions_str(char buf[PERMISSIONS_BUF_LEN], mode_t mode)
{
	buf[0] = '-';
	buf[0] = (buf[0] == '-' && S_ISDIR(mode)) ? 'd' : buf[0];
	buf[0] = (buf[0] == '-' && S_ISCHR(mode)) ? 'c' : buf[0];
	buf[0] = (buf[0] == '-' && S_ISBLK(mode)) ? 'b' : buf[0];
	buf[0] = (buf[0] == '-' && S_ISFIFO(mode)) ? 'p' : buf[0];
	buf[0] = (buf[0] == '-' && S_ISSOCK(mode)) ? 's' : buf[0];
	buf[0] = (buf[0] == '-' && S_ISLNK(mode)) ? 'l' : buf[0];
	buf[1] = (mode & S_IRUSR) ? 'r' : '-';
	buf[2] = (mode & S_IWUSR) ? 'w' : '-';
	buf[3] = (mode & S_IXUSR) ? 'x' : '-';
	buf[4] = (mode & S_IRGRP) ? 'r' : '-';
	buf[5] = (mode & S_IWGRP) ? 'w' : '-';
	buf[6] = (mode & S_IXGRP) ? 'x' : '-';
	buf[7] = (mode & S_IROTH) ? 'r' : '-';
	buf[8] = (mode & S_IWOTH) ? 'w' : '-';
	buf[9] = (mode & S_IXOTH) ? 'x' : '-';
	buf[10] = '\0';
}

static void		date_str(char date[DATE_BUF_LEN], const time_t *clock)
{
	char	*ct;
	time_t	diff;

	ft_memset(date, ' ', DATE_BUF_LEN);
	date[DATE_BUF_LEN - 1] = '\0';
	ct = ctime(clock);
	ft_strncpy(date, ct + 4, 6);
	diff = time(NULL) - (time_t)*clock;
	if (diff > SECS_IN_6_MONTHS || diff < 0)
		ft_strncpy(date + 8, ct + 20, 4);
	else
		ft_strncpy(date + 7, ct + 11, 5);
}

void			display_long(t_list *children, t_options *options)
{
	char		perms[PERMISSIONS_BUF_LEN];
	char		date[DATE_BUF_LEN];
	char		*format;
	struct stat	s;
	int			total;

	format = NULL;
	if ((total = format_str(&format, children, options)))
		ft_printf("total %d\n", total);
	while (children)
	{
		if (options->display_dots
				|| *ft_basename(((t_file *)(children->content))->path) != '.')
		{
			s = ((t_file *)(children->content))->stat;
			permissions_str(perms, s.st_mode);
			date_str(date, (const time_t *)(&(s.st_mtimespec.tv_sec)));
			ft_printf(format, perms, s.st_nlink, getpwuid(s.st_uid)->pw_name,
					getgrgid(s.st_gid)->gr_name, s.st_size, date);
			print_filename((t_file *)(children->content), options);
		}
		children = children->next;
	}
	free(format);
}
