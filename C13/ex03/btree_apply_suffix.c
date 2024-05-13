/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:21:25 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 23:25:18 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	t_btree	*temp;

	temp = root;
	if (temp == 0)
		return ;
	if (temp->left != 0)
		btree_apply_suffix(temp->left, applyf);
	if (temp->right != 0)
		btree_apply_suffix(temp->right, applyf);
	if (temp->item != 0)
		(*applyf)(temp->item);
}
