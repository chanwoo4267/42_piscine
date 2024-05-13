/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:34:54 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/06 16:12:41 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	result;
	int	i;
	int	add;

	i = 0;
	result = 0;
	while (tab[i] != 0)
	{
		add = f(tab[i]);
		if (add)
			result = 1;
		i++;
	}
	return (result);
}
