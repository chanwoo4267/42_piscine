/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:30:21 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/05 14:28:50 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str);

/* 길이로 자른 함수 1. ft_join 내부 함수 */
int	init_ft_join(int *str_i, int *ret_i, int *int_flag, char *ret)
{
	*str_i = 0;
	*ret_i = 0;
	*int_flag = 1;
	if (!ret)
		return (0);
	return (1);
}

/* 길이로 자른 함수 2. ft_join 내부 함수 */
char	*ft_join_return(char *ret, char *str, int str_i)
{
	ret[str_i] = '\0';
	if (str[str_i - 1] <= '0' || str[str_i - 1] > '9') // 만약 마지막에 추가적인 공백이 존재한다면
		return (NULL); //잘못된 입력
	return (ret);
}

/* 입력값 str을 공백없는 하나의 문자열로 정돈하고, 그 와중 에러를 발견하면 이를 검출하는 함수. */
char	*ft_join(char *str)
{
	int		str_i;
	int		ret_i;
	int		int_flag;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1)); // 넉넉히 동적할당.
	if (!init_ft_join(&str_i, &ret_i, &int_flag, ret)) // 각 값을 초기화.
		return (NULL);
	while (str[str_i] != '\0')
	{  	//int_flag는 숫자가 와야되는 상황에서 1, 아닌 상황에서 0으로 set됨.
		if (int_flag && str[str_i] > '0' && str[str_i] <= '9') // 1~9 사이 숫자만으로 되어있는지 확인하고 넣기
		{
			ret[ret_i] = str[str_i];
			ret_i++;
			int_flag = 0;
		}
		else if (!int_flag && str[str_i] == ' ') //
			int_flag = 1;
		else
			return (NULL);
		str_i++;
	}
	return (ft_join_return(ret, str, str_i));
}

int	check_invalid_input(char *str, int size) // 들어온 숫자들 중 size 최대 크기를 벗어난 숫자가 존재할경우
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] - '0' > size)
			return (0);
		i++;
	}
	return (1);
}

int	**initialize_board(int **board, int len) // 보드를 size로 초기화. 4x4면 각 변에 넣을 인자를 포함해서 6x6으로 동적할당.
{
	int	row;
	int	i;

	board = (int **)malloc(sizeof(int *) * len);
	row = 0;
	while (row < len)
	{
		board[row] = (int *)malloc(sizeof(int) * len);
		i = 0;
		while (i < len)
		{
			board[row][i] = 0; // 모두 0으로 초기화.
			i++;
		}
		row++;
	}
	return (board);
}
