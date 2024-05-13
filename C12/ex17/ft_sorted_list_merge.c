/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:26:47 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 21:03:27 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

unsigned int	count_node_four(t_list **begin_list)
{
	t_list			*temp;
	unsigned int	count;

	count = 0;
	temp = *begin_list;
	while (temp != 0)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	find_s_node_four(t_list **all_list, int (*cmp)(), t_list **smallest)
{
	t_list	*s_before;
	t_list	*temp;

	*smallest = *all_list;
	temp = *all_list;
	s_before = 0;
	if (temp == 0)
		return ;
	while (temp->next != 0)
	{
		if ((*cmp)((*smallest)->data, temp->next->data) > 0)
		{
			*smallest = temp->next;
			s_before = temp;
		}
		temp = temp->next;
	}
	if (s_before == 0)
		*all_list = (*all_list)->next;
	else if (s_before->next != 0)
		s_before->next = s_before->next->next;
	else
		s_before->next = 0;
}

void	ft_list_sort_four(t_list **begin_list, int (*cmp)())
{
	t_list			*temp;
	t_list			*smallest;
	t_list			*new_list;
	unsigned int	count;
	unsigned int	i;

	if (*begin_list == 0)
		return ;
	count = count_node_four(begin_list);
	i = -1;
	while (++i < count)
	{
		find_s_node_four(begin_list, cmp, &smallest);
		smallest->next = 0;
		if (i == 0)
			new_list = smallest;
		else
		{
			temp = new_list;
			while (temp->next != 0)
				temp = temp->next;
			temp->next = smallest;
		}
	}
	*begin_list = new_list;
}

void	ft_list_merge_four(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*temp;

	temp = *begin_list1;
	if (temp == 0)
		*begin_list1 = begin_list2;
	else
	{
		while (temp->next != 0)
			temp = temp->next;
		temp->next = begin_list2;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, \
								t_list *begin_list2, int (*cmp)())
{
	ft_list_merge_four(begin_list1, begin_list2);
	ft_list_sort_four(begin_list1, cmp);
}
