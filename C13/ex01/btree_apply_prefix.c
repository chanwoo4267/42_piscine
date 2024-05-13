/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:11:15 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 23:02:28 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	t_btree	*temp;

	temp = root;
	if (temp == 0)
		return ;
	if (temp->item != 0)
		(*applyf)(temp->item);
	if (temp->left != 0)
		btree_apply_prefix(temp->left, applyf);
	if (temp->right != 0)
		btree_apply_prefix(temp->right, applyf);
}
