/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 05:32:42 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 18:03:49 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_node;

	new_node = ft_create_elem(data);
	new_node->next = (*begin_list);
	(*begin_list) = new_node;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	int		i;

	i = 0;
	head = 0;
	while (i < size)
	{
		ft_list_push_front(&head, strs[i]);
		i++;
	}
	return (head);
}
