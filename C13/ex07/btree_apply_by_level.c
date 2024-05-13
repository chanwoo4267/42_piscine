/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:56:37 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/15 01:14:10 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count_two(t_btree *root)
{
	int	count;

	count = 0;
	if (root == 0)
		return (0);
	if (count < btree_level_count_two(root->left) + 1)
		count = btree_level_count_two(root->left) + 1;
	if (count < btree_level_count_two(root->right) + 1)
		count = btree_level_count_two(root->right) + 1;
	return (count);
}

void	trav_by_level(t_btree *root, t_level lv, int *isfirst, \
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (root == 0)
		return ;
	if (lv.object_level == lv.current_level)
	{
		(*applyf)(root->item, lv.current_level, *isfirst);
		*isfirst = 0;
		return ;
	}
	lv.current_level += 1;
	trav_by_level(root->left, lv, isfirst, applyf);
	trav_by_level(root->right, lv, isfirst, applyf);
	lv.current_level -= 1;
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, \
								int current_level, int is_first_elem))
{
	t_level	lv;
	int		target_level;
	int		obj_level;
	int		isfirst;

	if (root == 0)
		return ;
	target_level = btree_level_count_two(root);
	obj_level = 0;
	while (obj_level < target_level)
	{
		isfirst = 1;
		lv.object_level = obj_level;
		lv.current_level = 0;
		trav_by_level(root, lv, &isfirst, applyf);
		obj_level++;
	}
}
