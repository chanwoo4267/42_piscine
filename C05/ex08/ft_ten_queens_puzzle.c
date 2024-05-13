/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:37:52 by chanwopa          #+#    #+#             */
/*   Updated: 2022/08/31 13:13:03 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	is_available(int board[11], int cdx)
{
	int	i;

	i = 0;
	while (i < cdx)
	{
		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_board(int board[11])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	nqueen(int board[11], int cdx, int *count)
{
	int	i;

	if (cdx == 10)
	{
		print_board(board);
		(*count)++;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		board[cdx] = i;
		if (is_available(board, cdx))
			nqueen(board, cdx + 1, count);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[11];
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}
	nqueen(board, 0, &count);
	return (count);
}
