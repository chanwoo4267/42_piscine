/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:25:44 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 16:42:13 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	remove_node(t_list *remover, void (*free_fct)(void *))
{
	(*free_fct)(remover->data);
	free(remover);
}

int	delete_node(t_list **begin_list, void *data_ref, int (*cmp)(), \
					void (*free_fct)(void *))
{
	t_list	*temp;
	t_list	*remover;

	temp = *begin_list;
	if (temp == 0)
		return (0);
	if ((*cmp)(temp->data, data_ref) == 0)
	{
		*begin_list = (*begin_list)->next;
		remove_node(temp, free_fct);
		return (1);
	}
	while (temp->next != 0)
	{
		if ((*cmp)(temp->next->data, data_ref) == 0)
		{
			remover = temp->next;
			temp->next = temp->next->next;
			remove_node(remover, free_fct);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), \
							void (*free_fct)(void *))
{
	int	result;

	result = 1;
	while (result)
	{
		result = delete_node(begin_list, data_ref, cmp, free_fct);
	}
}
