/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:39:29 by chanwopa          #+#    #+#             */
/*   Updated: 2022/08/24 18:21:40 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_int_as_two_char(int a)
{
	char	left;
	char	right;
	int		div;
	int		mod;

	div = a / 10;
	mod = a % 10;
	left = div + 48;
	right = mod + 48;
	ft_putchar(left);
	ft_putchar(right);
}

void	print_combo2_format(int left, int right, int end)
{
	print_int_as_two_char(left);
	ft_putchar(' ');
	print_int_as_two_char(right);
	if (!end)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	left;
	int	right;

	left = 0;
	while (left <= 98)
	{
		right = left + 1;
		while (right <= 99)
		{
			if (left == 98 && right == 99)
				print_combo2_format(left, right, 1);
			else
				print_combo2_format(left, right, 0);
			right++;
		}
		left++;
	}
}
