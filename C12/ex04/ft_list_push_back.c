/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 05:30:05 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 18:03:55 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*temp;

	temp = begin_list;
	if (temp == 0)
		return (0);
	while (temp->next != 0)
		temp = temp->next;
	return (temp);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = ft_create_elem(data);
	temp = ft_list_last(*begin_list);
	if (temp == 0)
		*begin_list = new_node;
	else
		temp->next = new_node;
}
