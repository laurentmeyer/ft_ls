/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:50:33 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/14 11:32:54 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		list_dir_contents(t_file *file, t_list **alst, t_options *options)
{
	DIR				*dirp;
	struct dirent	*dir;

	if ((dirp = opendir(file->path)) == NULL)
	{
		file->error = strerror(errno);
		return ;
	}
	while ((dir = readdir(dirp)))
		add_t_file_to_list(make_full_path(file->path, dir->d_name),
				alst, options);
	if (closedir(dirp))
		ft_dprintf(STDERR, "ls: %s: %s\n", file->path, strerror(errno));
}
