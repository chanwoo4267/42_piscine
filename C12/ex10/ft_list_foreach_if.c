/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:27:51 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 16:41:40 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), \
							void *data_ref, int (*cmp)())
{
	t_list	*temp;

	temp = begin_list;
	while (temp != 0)
	{
		if ((*cmp)(temp->data, data_ref) == 0)
			(*f)(temp->data);
		temp = temp->next;
	}
}
