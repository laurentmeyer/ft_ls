/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 11:34:58 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/20 18:58:51 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*make_full_path(char *dirname, char *basename)
{
	char	*res;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(dirname);
	l2 = ft_strlen(basename);
	if (!(res = (char *)malloc(l1 + l2 + 2)))
		exit_msg("make_full_path malloc failed");
	ft_memcpy(res, dirname, l1);
	res[l1] = '/';
	ft_memcpy(res + l1 + 1, basename, l2 + 1);
	return (res);
}
