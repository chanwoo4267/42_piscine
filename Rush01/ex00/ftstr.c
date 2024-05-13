/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:04:13 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/05 14:28:50 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
// 문자열 길이
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
// 보드 출력
void	test_print_board(int **board, int size)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			if (j != size - 2)
				write(1, &" ", 1);
			j++;
		}
		write(1, &"\n", 1);
		i++;
	}
}
// 동적할당 해제 
void	free_board(int **board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}
