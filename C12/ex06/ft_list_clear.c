/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 05:38:26 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 16:41:23 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*temp;
	t_list	*remover;

	temp = begin_list;
	while (temp != 0)
	{
		remover = temp;
		temp = temp->next;
		if (remover->data != 0)
			(*free_fct)(remover->data);
		free(remover);
	}
}
