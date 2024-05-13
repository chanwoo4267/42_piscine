/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:39:29 by chanwopa          #+#    #+#             */
/*   Updated: 2022/08/24 18:29:27 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_comb_format(char left, char mid, char right, int end)
{
	ft_putchar(left);
	ft_putchar(mid);
	ft_putchar(right);
	if (!end)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	left;
	char	mid;
	char	right;

	left = '0';
	while (left <= '7')
	{
		mid = left + 1;
		while (mid <= '8')
		{
			right = mid + 1;
			while (right <= '9')
			{
				if (left == '7' && mid == '8' && right == '9')
					write_comb_format(left, mid, right, 1);
				else
					write_comb_format(left, mid, right, 0);
				right++;
			}
			mid++;
		}
		left++;
	}
}
