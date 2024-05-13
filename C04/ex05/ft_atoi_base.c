/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:36:55 by chanwopa          #+#    #+#             */
/*   Updated: 2022/08/30 14:43:54 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_invalid_base(char *base)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	len = ft_strlen(base);
	if (len <= 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	jump_to_start(char *str, int *i, int *sign)
{
	*i = 0;
	*sign = 1;
	while (str[(*i)] == ' ' || (str[(*i)] >= 9 && str[(*i)] <= 13))
		(*i)++;
	while (str[(*i)] == '+' || str[(*i)] == '-')
	{
		if (str[(*i)] == '-')
			(*sign) *= -1;
		(*i)++;
	}
}

int	calculate_result(char *str, char *base, int i, int j)
{
	int				result;
	unsigned int	base_len;

	result = 0;
	base_len = ft_strlen(base);
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
			{
				result = result * base_len + j;
				break ;
			}
			j++;
		}
		if (base[j] == '\0')
			return (result);
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int				result;
	int				sign;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (check_invalid_base(base))
		return (0);
	jump_to_start(str, &i, &sign);
	result = calculate_result(str, base, i, j);
	return (result * sign);
}
