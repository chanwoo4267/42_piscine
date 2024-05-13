/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:35:27 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/13 03:05:31 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	ft_putstr(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

unsigned long long	ft_atoi(char *str, int *flag)
{
	int					i;
	unsigned long long	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		*flag = 1;
	return (result);
}

void	print_case(char *path)
{
	ft_putstr(1, "==> ");
	ft_putstr(1, path);
	ft_putstr(1, " <==\n");
}

unsigned long long	ft_strlen(char *str)
{
	unsigned long long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
