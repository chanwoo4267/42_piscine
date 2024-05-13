/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:29:53 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/05 14:28:51 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str);
int		init_ft_join(int *str_i, int *ret_i, int *int_flag, char *ret);
char	*ft_join(char *str);
int		check_invalid_input(char *str, int size);
int		**initialize_board(int **board, int len);
void	input_args(int **board, char *args, int size);
int		put_init(int **arr, char *args, int size);
int		check_left(int **board, int row, int column, int size);
int		check_right(int **board, int row, int column, int size);
int		check_all(int **board, int size);
int		check_dup_line(int **board, int row, int size);
void	dfs(int **board, int row, int column, int size);
void	test_print_board(int **board, int size);
void	free_board(int **board, int size);

// 상하좌우 숫자를 고려하여 현재 위치에 올수 있는 최대 숫자보다 크다면 0을 반환
int	check_input_valid(int **board, int row, int column, int size) 
{
	int	left;
	int	right;
	int	top;
	int	bottom;

	left = board[row][0];
	right = board[row][size - 1];
	top = board[0][column];
	bottom = board[size - 1][column];
	if (board[row][column] > (size - 2) - left + column)
		return (0);
	if (board[row][column] > (size - 2) - right + (size - 1 - column))
		return (0);
	if (board[row][column] > (size - 2) - top + row)
		return (0);
	if (board[row][column] > (size - 2) - bottom + (size - 1 - row))
		return (0);
	return (1);
}

//dfs 과정에서 값을 1~size-1까지 넣어보고, 들어갈 수 있는지 여러 조건을 확인한 뒤 dfs 재귀호출
void	fill_a_num(int **board, int row, int column, int size)
{
	int	num;

	num = 1;
	while (num < size - 1)
	{
		board[row][column] = num;
		if (check_input_valid(board, row, column, size)) // 상하좌우를 고려하여 현 위치에 올수있는 최대숫자와 비교
		{
			if (column == size - 2) // 가로로 한줄이 꽉찼다면
			{
				if (check_dup_line(board, row, size)) // 가로 중복 확인
					if (check_left(board, row, column, size)) // 왼쪽 변 값과 일치하는지 확인
						if (check_right(board, row, column, size)) // 오른쪽 변 값과 일치하는지 확인
							dfs(board, row + 1, 1, size);
			}
			else
				dfs(board, row, column + 1, size);
		}
		board[row][column] = 0;
		num++;
	}
}

void	dfs(int **board, int row, int column, int size)
{
	if (board[0][0] == 1) // 이미 하나를 출력했다면 그냥 return
		return ;
	if (row == size - 1 && column == 1)
	{
		if (check_all(board, size)) // 상하좌우, 가로세로 중복검사 전부 수행
		{
			test_print_board(board, size); // 출력
			board[0][0] = 1;
		}
	}
	else if (board[row][column] != 0) // 이미 들어온 값이 있다면 -> 초기화시 1,2,3,4, .. 순차적으로 넣어준 경우가 존재
	{
		if (column == size - 2)
			dfs(board, row + 1, 1, size);
		else
			dfs(board, row, column + 1, size);
	}
	else
	{
		fill_a_num(board, row, column, size);
	}
}

int	check_args(int argc, char **args, char **argv, int *size)
{
	if (argc != 2)
		return (0);
	(*args) = ft_join(argv[1]); // argv[1]에서 invalid판단 및 공백잘라서 args에 저장
	if (*args == 0)
		return (0);
	*size = ft_strlen(*args) / 4; // size 얻기
	return (1);
}

int	main(int argc, char **argv)
{
	int		**board;
	char	*args;
	int		size;

	args = 0;
	if (!check_args(argc, &args, argv, &size) || ft_strlen(args) % 4 != 0 \
	|| !check_invalid_input(args, size))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	board = 0;
	board = initialize_board(board, size + 2);
	input_args(board, args, size + 2);
	if (!put_init(board, args, size))
	{
		write(1, "Error\n", 6);
		free_board(board, size + 2);
		return (0);
	}
	dfs(board, 1, 1, size + 2);
	if (board[0][0] == 0)
		write(1, "Error\n", 6);
	free_board(board, size + 2);
	return (0);
}
