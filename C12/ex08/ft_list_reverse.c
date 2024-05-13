/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 05:46:26 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 20:57:16 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

unsigned int	count_node(t_list **begin_list, t_list **new_start)
{
	t_list			*temp;
	unsigned int	count;

	count = 0;
	temp = *begin_list;
	while (temp != 0)
	{
		*new_start = temp;
		temp = temp->next;
		count++;
	}
	return (count);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list			*temp;
	t_list			*temp_before;
	t_list			*new_start;
	unsigned int	count;
	unsigned int	i;

	count = count_node(begin_list, &new_start);
	if (count <= 1)
		return ;
	while (count > 1)
	{
		i = -1;
		temp = *begin_list;
		while (++i < count - 2)
			temp = temp->next;
		temp_before = temp;
		temp = temp->next;
		temp->next = temp_before;
		count--;
	}
	temp_before->next = 0;
	*begin_list = new_start;
}
