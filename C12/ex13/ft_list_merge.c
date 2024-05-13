/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:25:54 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 16:41:49 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
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
