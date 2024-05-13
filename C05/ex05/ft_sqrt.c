/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:25:19 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/01 14:18:43 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

double	sqrt_babilon(double val)
{
	double	x;
	int		i;

	x = 1;
	i = 0;
	while (i <= 100)
	{
		x = (x + (val / x)) / 2;
		i++;
	}
	return (x);
}

int	ft_sqrt(int nb)
{
	int		lower_bound;
	int		upper_bound;
	int		i;
	double	x;

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	x = sqrt_babilon((double)nb);
	lower_bound = (int)(x) - 10;
	upper_bound = (int)(x) + 10;
	if (lower_bound < 1)
		lower_bound = 2;
	i = lower_bound;
	while (i <= upper_bound)
	{
		if (i * i == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
