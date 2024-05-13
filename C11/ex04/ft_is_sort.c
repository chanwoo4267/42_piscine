/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:15:28 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/08 09:33:30 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	incre;
	int	decre;
	int	temp;

	i = 0;
	incre = 0;
	decre = 0;
	if (length <= 0)
		return (1);
	while (i < length - 1)
	{
		temp = f(tab[i], tab[i + 1]);
		if (temp >= 0)
			decre++;
		if (temp <= 0)
			incre++;
		i++;
	}
	if (incre == length - 1 || decre == length - 1)
		return (1);
	else
		return (0);
}
