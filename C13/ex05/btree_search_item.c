/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:31:57 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/15 04:13:31 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
							int (*cmpf)(void *, void *))
{
	void	*ret;

	ret = 0;
	if (root == 0)
		return (0);
	ret = btree_search_item(root->left, data_ref, cmpf);
	if (ret != 0)
		return (ret);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	ret = btree_search_item(root->right, data_ref, cmpf);
	if (ret != 0)
		return (ret);
	return (0);
}
