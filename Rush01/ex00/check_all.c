/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:17:38 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/05 14:28:52 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_left(int **board, int row, int column, int size);
int	check_right(int **board, int row, int column, int size);
int	check_top(int **board, int row, int column, int size);
int	check_bottom(int **board, int row, int column, int size);
int	check_safe(int **board, int row, int column, int size);

void	init_temp(int **temp, int size)
{
	int	i;

	i = 0;
	while (i < size - 2)
	{
		(*temp)[i] = 0;
		i++;
	}
}

int	check_temp(int *temp, int size)
{
	int	i;

	i = 0;
	while (i < size - 2)
	{
		if (temp[i] != 1)
			return (0);
		i++;
	}
	return (1);
}
/* 가로줄 중에 중복이 발생하는지 확인하는 함수. */
int	check_duplicate_row(int **board, int size) 
{
	int	row;
	int	i;
	int	*temp;

	temp = (int *)malloc(sizeof(int) * (size - 2));
	row = 1;
	while (row < size - 1)
	{
		init_temp(&temp, size);
		i = 1;
		while (i < size - 1)
		{
			temp[board[row][i] - 1]++;
			i++;
		}
		if (!check_temp(temp, size))
			return (0);
		row++;
	}
	free(temp);
	return (1);
}
/* 세로줄 중에 중복이 발생하는지 확인하는 함수. */
int	check_duplicate_col(int **board, int size)
{
	int	column;
	int	i;
	int	*temp;

	temp = (int *)malloc(sizeof(int) * (size - 2));
	column = 1;
	while (column < size - 1)
	{
		init_temp(&temp, size);
		i = 1;
		while (i < size - 1)
		{
			temp[board[i][column] - 1]++;
			i++;
		}
		if (!check_temp(temp, size))
			return (0);
		column++;
	}
	free(temp);
	return (1);
}
/* 보드가 전부 채워졌을때, 모든 조건을 한번 확인 */
int	check_all(int **board, int size)
{
	int	row;

	row = 1;
	if (!check_duplicate_row(board, size) || !check_duplicate_col(board, size)) // 중복 확인
		return (0);
	while (row < size - 1)
	{
		if (!check_safe(board, row, row, size)) // 상하좌우의 변 값과 실제로 보이는 값이 동일한지 확인
			return (0);
		row++;
	}
	return (1);
}
