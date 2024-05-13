/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:10:45 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/07 15:35:21 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	i;
	int	add;

	i = 0;
	count = 0;
	while (i < length)
	{
		add = f(tab[i]);
		if (add)
			count++;
		i++;
	}
	return (count);
}
