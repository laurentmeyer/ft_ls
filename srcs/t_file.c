/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:50:23 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/19 17:17:04 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				t_file_lstdel(void *content, size_t size)
{
	(void)size;
	free(((t_file *)content)->path);
	free((t_file *)content);
}

static t_list		*t_file_lstnew(char *path, struct stat *statbuf,
		t_options *options)
{
	t_file	new;
	t_list	*ret;

	new.path = path;
	new.error = NULL;
	new.options = options;
	ft_memcpy(&(new.stat), statbuf, sizeof(struct stat));
	if (!(ret = ft_lstnew(&new, sizeof(t_file))))
		exit_msg("ft_lstnew failed\n");
	return (ret);
}

void				add_t_file_to_list(char *fullpath, t_list **alst,
		t_options *options)
{
	struct stat		lsbuf;
	struct stat		sbuf;
	struct stat		*to_copy;
	t_list			*new;
	char			*error;

	error = NULL;
	ft_bzero(&lsbuf, sizeof(struct stat));
	ft_bzero(&sbuf, sizeof(struct stat));
	if ((*(options->stat_f))(fullpath, &lsbuf) == ERROR)
		error = strerror(errno);
	if (!error && S_ISLNK(lsbuf.st_mode) && stat(fullpath, &sbuf) == ERROR)
		error = strerror(errno);
	to_copy = &lsbuf;
	if (S_ISDIR(sbuf.st_mode) && options->display_long == 0)
		to_copy = &sbuf;
	if (!(new = t_file_lstnew(fullpath, to_copy, options)))
		exit_msg("struct s_list memory allocation failed\n");
	if (error)
		((t_file *)(new->content))->error = error;
	ft_lstadd(alst, new);
}
