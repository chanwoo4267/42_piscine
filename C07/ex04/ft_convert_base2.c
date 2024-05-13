/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:35:38 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/04 17:05:14 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	is_base_valid(char *str)
{
	int		i;
	int		j;
	int		index;

	index = 0;
	if (str == NULL || ft_strlen(str) <= 1)
		return (0);
	while (str[index] != '\0')
	{
		if (is_space(str[index]) || str[index] == '+' || str[index] == '-')
			return (0);
		index++;
	}
	i = 0;
	while (i < index)
	{
		j = i + 1;
		while (j < index)
			if (str[i] == str[j++])
				return (0);
		i++;
	}
	return (1);
}

int	ft_num_len(unsigned int number, int radix, int negative)
{
	unsigned int	length;

	if (negative)
		length = 2;
	else
		length = 1;
	while (number / radix != 0)
	{
		number /= radix;
		length++;
	}
	return (length);
}
