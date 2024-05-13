/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:56:40 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/05 14:28:49 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* 현재 row가 주어졌을 때, 그 row 가로에서 중복이 발생하는지 확인하는 함수. */
int	check_dup_line(int **board, int row, int size)
{
	int	i;
	int	*temp;

	temp = (int *)malloc(sizeof(int) * (size - 2));
	i = 0;
	while (i < size - 2)
	{
		temp[i] = 0;
		i++;
	}
	i = 1;
	while (i < size - 1)
	{
		temp[board[row][i] - 1]++;
		i++;
	}
	i = 0;
	while (i < size - 2)
	{
		if (temp[i] != 1)
			return (0);
		i++;
	}
	free(temp);
	return (1);
}
