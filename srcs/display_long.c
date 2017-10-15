/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:51:56 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/15 17:05:32 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <stdio.h>//

#define SECS_IN_6_MONTHS    365 / 2 * 24 * 3600
#define OFFSET 2

static void		get_precisions(t_list *children)
{
	int			l;
	t_format	*format;
	struct stat	s;

	if (is_hidden((t_file *)(children->content)))
		return;
	format = ((t_file *)(children->content))->options->format;
	s = ((t_file *)(children->content))->stat;
	if ((l = ft_intlen(s.st_nlink)) > format->p_link)
		format->p_link = l;
	if ((l = ft_strlen(getpwuid(s.st_uid)->pw_name)) > format->p_name)
		format->p_name = l;
	if ((l = ft_strlen(getgrgid(s.st_gid)->gr_name)) > format->p_group)
		format->p_group = l;
	if (S_ISBLK(s.st_mode) || S_ISCHR(s.st_mode))
	{
		if ((l = ft_intlen(major(s.st_rdev))) > format->p_major)
			format->p_major = l;
		if ((l = ft_intlen(minor(s.st_rdev))) > format->p_minor)
			format->p_minor = l;
	}
	else if ((l = ft_intlen(s.st_size)) > format->p_size)
			format->p_size = l;
	format->p_total += s.st_blocks;
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

void			display_long_line(t_list *child)
{
	struct stat	s;
	t_format	*format;
	char		perms[PERMISSIONS_BUF_LEN];
	char		date[DATE_BUF_LEN];

	format = ((t_file *)(child->content))->options->format;
	if (is_hidden((t_file *)(child->content)))
		return ;
	s = ((t_file *)(child->content))->stat;
	permissions_str(perms, s.st_mode);
	date_str(date, (const time_t *)(&(s.st_mtimespec.tv_sec)));
	if (S_ISCHR(s.st_mode) || S_ISBLK(s.st_mode))
		ft_printf(format->format_dev,
				perms, s.st_nlink, getpwuid(s.st_uid)->pw_name,
				getgrgid(s.st_gid)->gr_name, major(s.st_rdev),
				minor(s.st_rdev), date);
	else
		ft_printf(format->format_std,
				perms, s.st_nlink, getpwuid(s.st_uid)->pw_name,
				getgrgid(s.st_gid)->gr_name, s.st_size, date);
	print_filename((t_file *)(child->content));
}

void			make_format(t_options *options)
{
	t_format	*f;

	f = options->format;
	if (f->p_major)
	{
		if (f->p_size > OFFSET + f->p_minor + f->p_major)
			f->p_major = f->p_size - f->p_minor - OFFSET;
		else
			f->p_size = f->p_major + f->p_minor + OFFSET;
		sprintf(f->format_dev, "%%s  %%-%dd %%-%ds  %%-%ds %%%dd,  %%%dd %%s ",
				f->p_link, f->p_name, f->p_group, f->p_major, f->p_minor);
	}
	sprintf(f->format_std, "%%s  %%%dd %%-%ds  %%-%ds  %%%dd %%s ",
			f->p_link, f->p_name, f->p_group, f->p_size);
}

void			display_long(t_list *children)
{
	t_options	*options;

	options = ((t_file *)(children->content))->options;
	ft_bzero(options->format, sizeof(t_format));
	ft_lstiter(children, &get_precisions);
	make_format(options);
	if (options->format->p_total || options->files_done)
		ft_printf("total %d\n", options->format->p_total);
	ft_lstiter(children, &display_long_line);
}
