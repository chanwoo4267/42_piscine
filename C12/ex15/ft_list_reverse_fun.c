/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:26:29 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 20:55:46 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

unsigned int	count_node_two(t_list *begin_list)
{
	t_list			*temp;
	unsigned int	count;

	count = 0;
	temp = begin_list;
	while (temp != 0)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	ft_swap(void **a, void **b)
{
	void	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list			*temp;
	t_list			*target;
	unsigned int	count;
	unsigned int	i;
	unsigned int	j;

	count = count_node_two(begin_list);
	i = 0;
	while (i < count / 2)
	{
		j = 0;
		temp = begin_list;
		while (j++ < i)
			temp = temp->next;
		j = 0;
		target = begin_list;
		while (j++ < count - 1 - i)
			target = target->next;
		ft_swap(&(target->data), &(temp->data));
		i++;
	}
}
