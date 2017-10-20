/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:51:56 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/19 16:09:01 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define SECS_IN_6_MONTHS    365 / 2 * 24 * 3600

static int	max(int a, int b)
{
	return (a > b ? a : b);
}

void		get_precisions(t_list *children)
{
	int			l;
	t_format	*format;
	struct stat	s;

	s = ((t_file *)(children->content))->stat;
	if (is_hidden((t_file *)(children->content)))
		return ;
	format = ((t_file *)(children->content))->options->format;
	format->p_link = max(ft_intlen(s.st_nlink), format->p_link);
	l = getpwuid(s.st_uid) ? ft_strlen(getpwuid(s.st_uid)->pw_name)
		: ft_intlen(s.st_uid);
	format->p_name = max(l, format->p_name);
	l = getgrgid(s.st_gid) ? ft_strlen(getgrgid(s.st_gid)->gr_name)
		: ft_intlen(s.st_gid);
	format->p_group = max(l, format->p_group);
	if (S_ISBLK(s.st_mode) || S_ISCHR(s.st_mode))
	{
		format->p_major = max(ft_intlen(major(s.st_rdev)), format->p_major);
		format->p_minor = max(ft_intlen(minor(s.st_rdev)), format->p_minor);
	}
	format->p_size = max(ft_intlen(s.st_size), format->p_size);
	format->p_total += s.st_blocks;
}

void		permissions_str(char buf[PERMISSIONS_BUF_LEN], mode_t mode)
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
	if (mode & S_ISUID)
		buf[3] = (buf[3]) == 'x' ? 's' : 'S';
	buf[4] = (mode & S_IRGRP) ? 'r' : '-';
	buf[5] = (mode & S_IWGRP) ? 'w' : '-';
	buf[6] = (mode & S_IXGRP) ? 'x' : '-';
	if (mode & S_ISGID)
		buf[6] = (buf[6]) == 'x' ? 's' : 'S';
	buf[7] = (mode & S_IROTH) ? 'r' : '-';
	buf[8] = (mode & S_IWOTH) ? 'w' : '-';
	buf[9] = (mode & S_IXOTH) ? 'x' : '-';
	if (mode & S_ISVTX)
		buf[9] = (buf[9] == 'x') ? 't' : 'T';
	buf[10] = '\0';
}

void		date_str(char date[DATE_BUF_LEN], const time_t *clock)
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

void		display_long_line(t_list *child)
{
	struct stat	s;
	t_format	*format;
	char		perms[PERMISSIONS_BUF_LEN];
	char		date[DATE_BUF_LEN];
	char		*n[2];

	format = ((t_file *)(child->content))->options->format;
	if (is_hidden((t_file *)(child->content)))
		return ;
	s = ((t_file *)(child->content))->stat;
	n[0] = getpwuid(s.st_uid) ? getpwuid(s.st_uid)->pw_name : ft_itoa(s.st_uid);
	n[1] = getgrgid(s.st_gid) ? getgrgid(s.st_gid)->gr_name : ft_itoa(s.st_gid);
	permissions_str(perms, s.st_mode);
	date_str(date, (const time_t *)(&(s.st_mtimespec.tv_sec)));
	if (S_ISCHR(s.st_mode) || S_ISBLK(s.st_mode))
		ft_printf(format->format_dev, perms, s.st_nlink, n[0], n[1],
				major(s.st_rdev), minor(s.st_rdev), date);
	else
		ft_printf(format->format_std, perms, s.st_nlink,
				n[0], n[1], s.st_size, date);
	print_filename((t_file *)(child->content));
	if (!getpwuid(s.st_uid))
		free(n[0]);
	if (!getgrgid(s.st_gid))
		free(n[1]);
}
