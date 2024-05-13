/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:14:45 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/05 14:28:51 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* args의 값들을 순차적으로 board에 사방 변에 넣어줌. */
void	input_args(int **board, char *args, int size)
{
	int	row;
	int	column;
	int	args_i;

	args_i = 0;
	row = 0;
	while (row < size) // row = 0, row = size - 1 이렇게 두번만 순회. 각각 윗변, 아랫변
	{
		column = 1;
		while (column < size - 1) // column이 1부터 size - 1까지 순회
		{
			board[row][column++] = args[args_i++] - '0'; // 값을 int형 변수로 넣어줌
		}
		row = row + size - 1;
	}
	column = 0;
	while (column < size) // column = 0, column = size - 1 두번순회, 각 왼,오른변
	{
		row = 1;
		while (row < size - 1)
		{
			board[row++][column] = args[args_i++] - '0';
		}
		column = column + size - 1;
	}
}

/*	아래와 세트. 길이때문에 둘로 나눠서 구현함.	*/
int	check_args_range_c(int **arr, int i, int j, int size)
{
	if (i >= size * 2 && i < size * 3) // index가 size*2 ~ size*3, 즉 왼변
	{
		if (arr[i - size * 2 + 1][j] != 0 && \
		arr[i - size * 2 + 1][j] != j)
			return (0);
		arr[i - size * 2 + 1][j] = j; // 이번에는 row가 고정된 상태로 column만 j=1 ~ size까지 순회하며 넣어줌
	}
	else if (i >= size * 3 && i < size * 4) // 오른변
	{
		if (arr[i - size * 3 + 1][size + 1 - j] != 0 && \
		arr[i - size * 3 + 1][size + 1 - j] != j)
			return (0);
		arr[i - size * 3 + 1][size + 1 - j] = j; // 순회하며 넣어줌, 이때는 column이 오른쪽 -> 왼쪽으로 순회
	}
	return (1);
}

/*	각 변의 인자중 최대 size 숫자를 만난다면, 그 줄에는 1부터 최대값가지 순차적으로 와야한다. *
*	따라서 args의 index값에 따라 어느 변에 속했는지 조건문으로 확인하고, 적절한 값을 넣어줌. *
*	이때 다른 값과 충돌한다면, 잘못된 문제이므로 바로 0을 반환해줌. 					*/
int	check_args_range(int **arr, int i, int j, int size)
{
	if (i >= 0 && i < size) // index가 0 ~ size, 즉 윗변이므로
	{
		/* 이전에 값이 들어왔는데(0이 아님) 그 값이 지금 넣으려는 값과 다르면 */
		if (arr[j][i + 1] != 0 && arr[j][i + 1] != j) 
			return (0);
		arr[j][i + 1] = j; // j는 1~size를 순회한다. 윗변인 상태이므로, column은 i+1로 고정된 상태로 row만 순회하며 넣어줌
	}
	else if (i >= size && i < size * 2) // index가 size ~ size*2, 즉 아랫변
	{
		if (arr[size + 1 - j][i - size + 1] != 0 && \
		arr[size + 1 - j][i - size + 1] != j)
			return (0);
		arr[size + 1 - j][i - size + 1] = j; // 똑같이 column은 i+1번재, row는 순회. 이때는 아래->위로 순회
	}
	if (!check_args_range_c(arr, i, j, size))
		return (0);
	return (1);
}

/*	초기값들을 넣어준다. 여기서 말하는 초기값은, 각 변의 인자중 최대 size 숫자를 만나면	 *
*	그 위치에 대해 check_args_range 함수를 활용하여 1~size 값을 순차적으로 넣어줌. */
int	put_init(int **arr, char *args, int size)
{
	int	i;
	int	j;

	i = 0;
	while (args[i]) // args를 한글자씩 탐색
	{
		if (args[i] == '0' + size) // 만약 최대size값이 주어진다면, ex 4x4 크기의 각 변에 4가 들어온다면
		{
			j = 1;
			while (j <= size)
			{
				if (!check_args_range(arr, i, j, size))
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}
