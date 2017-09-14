/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:50:23 by lmeyer            #+#    #+#             */
/*   Updated: 2017/09/14 15:29:11 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		t_file_lstdel(void *content, size_t size)
{
	(void)size;
	free(((t_file *)content)->path);
	free((t_file *)content);
}

t_list		*t_file_lstnew(char *path, struct stat *statbuf)
{
	t_file	new;
	t_list	*ret;

	new.path = path;
	new.error = NULL;
	ft_memcpy(&(new.stat), statbuf, sizeof(struct stat));
	if (!(ret = ft_lstnew(&new, sizeof(t_file))))
		exit_msg("ft_lstnew failed\n");
	return (ret);
}

void		add_t_file_to_list(char *fullpath, t_list **alst,
		t_options *options)
{
	struct stat		statbuf;
	t_list			*new;
	char			*error;

	error = NULL;
	ft_bzero(&statbuf, sizeof(struct stat));
	if ((*(options->stat_f))(fullpath, &statbuf) == ERROR)
		error = strerror(errno);
	if (!(new = t_file_lstnew(fullpath, &statbuf)))
		exit_msg("struct s_list memory allocation failed\n");
	if (error)
		((t_file *)(new->content))->error = error;
	ft_lstadd(alst, new);
}
