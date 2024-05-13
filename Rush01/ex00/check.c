/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:37:20 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/05 14:28:50 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_left(int **board, int row, int column, int size)
{
	int	max;
	int	count;

	max = 0;
	count = 0;
	column = 1;
	while (column < size - 1)
	{
		if (board[row][column] > max)
		{
			max = board[row][column];
			count++;
		}
		column++;
	}
	if (count == board[row][0])
		return (1);
	else
		return (0);
}

int	check_right(int **board, int row, int column, int size)
{
	int	max;
	int	count;

	max = 0;
	count = 0;
	column = size - 2;
	while (column > 0)
	{
		if (board[row][column] > max)
		{
			max = board[row][column];
			count++;
		}
		column--;
	}
	if (count == board[row][size - 1])
		return (1);
	else
		return (0);
}

int	check_top(int **board, int row, int column, int size)
{
	int	max;
	int	count;

	max = 0;
	count = 0;
	row = 1;
	while (row < size - 1)
	{
		if (board[row][column] > max)
		{
			max = board[row][column];
			count++;
		}
		row++;
	}
	if (count == board[0][column])
		return (1);
	else
		return (0);
}

int	check_bottom(int **board, int row, int column, int size)
{
	int	max;
	int	count;

	max = 0;
	count = 0;
	row = size - 2;
	while (row > 0)
	{
		if (board[row][column] > max)
		{
			max = board[row][column];
			count++;
		}
		row--;
	}
	if (count == board[size - 1][column])
		return (1);
	else
		return (0);
}

/* 현재 row, column 기준으로 상하좌우의 변 값을 확인하고 실제로 그 값과 visible한 박스가 동일한지 확인 */
int	check_safe(int **board, int row, int column, int size)
{
	if (!check_left(board, row, column, size))
		return (0);
	if (!check_right(board, row, column, size))
		return (0);
	if (!check_top(board, row, column, size))
		return (0);
	if (!check_bottom(board, row, column, size))
		return (0);
	return (1);
}
