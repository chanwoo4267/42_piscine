/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:46:00 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/15 01:14:08 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	count;

	count = 0;
	if (root == 0)
		return (0);
	if (count < btree_level_count(root->left) + 1)
		count = btree_level_count(root->left) + 1;
	if (count < btree_level_count(root->right) + 1)
		count = btree_level_count(root->right) + 1;
	return (count);
}
