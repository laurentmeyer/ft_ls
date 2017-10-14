/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 11:34:13 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/14 11:34:19 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	exit_msg(char *str)
{
	ft_dprintf(STDERR, "%s", str);
	exit(EXIT_FAILURE);
}

void	exit_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
