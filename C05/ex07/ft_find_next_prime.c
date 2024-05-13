/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:52:10 by chanwopa          #+#    #+#             */
/*   Updated: 2022/08/31 12:49:20 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt_int(unsigned int nb)
{
	unsigned int		pow2;
	unsigned int		sqrt;

	sqrt = 0;
	pow2 = 0;
	while (pow2 <= nb)
	{
		sqrt++;
		pow2 = sqrt * sqrt;
	}
	return (sqrt - 1);
}

int	ft_is_prime(int nb)
{
	int	index;
	int	sqrt;

	index = 2;
	if (nb < 2)
		return (0);
	if (nb < 4)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	sqrt = ft_sqrt_int(nb);
	while ((index <= sqrt) && (nb % index != 0))
		index++;
	if (index <= sqrt)
		return (0);
	else
		return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		nb = 2;
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
	return (-1);
}
