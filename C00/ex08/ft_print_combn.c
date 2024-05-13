/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:37:06 by chanwopa          #+#    #+#             */
/*   Updated: 2022/08/25 13:40:30 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_num(char arr[10], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i]);
		i++;
	}
	if (arr[0] <= '9' - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	recursive_increase(char arr[10], int current_level, int object_level)
{
	int	i;

	if (current_level == object_level)
	{
		print_num(arr, object_level);
		return ;
	}
	if (current_level == 0)
		i = 0;
	else
		i = arr[current_level - 1] - 48 + 1;
	while (i <= 9 - object_level + current_level + 1)
	{
		arr[current_level] = i + 48;
		recursive_increase(arr, current_level + 1, object_level);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	recursive_increase(arr, 0, n);
}
