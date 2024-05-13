/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 05:43:06 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/14 16:41:26 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int		i;
	t_list				*temp;

	i = 0;
	temp = begin_list;
	while (i < nbr && temp != 0)
	{
		temp = temp->next;
		i++;
	}
	if (i == nbr)
		return (temp);
	else
		return (0);
}
