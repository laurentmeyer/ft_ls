/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 21:09:00 by lmeyer            #+#    #+#             */
/*   Updated: 2017/09/12 21:21:13 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void					btree_insert_node(t_btree **root, t_btree *node,
		int (*cmpf)(void *, void *))
{
	t_btree	*tmp;

	if (!*root)
		*root = node;
	else if ((*cmpf)((*root)->item, node->item) < 0)
	{
		if (!(tmp = (*root)->right) || (*cmpf)(tmp->item, node->item) < 0)
		{
			*root->right = node;
			node->right = tmp;
		}
		else
			btree_insert_node(&tmp, node, cmpf);
	}
	else
	{
		if (!(tmp = (*root)->left) || (*cmpf)(tmp->item, node->item) >= 0)
		{
			*root->left = node;
			node->left = tmp;
		}
		else
			btree_insert_node(&tmp, node, cmpf);
	}
}
