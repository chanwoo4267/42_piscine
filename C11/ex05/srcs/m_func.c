/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:12:16 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/07 14:24:25 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_func.h"
#include "ft_lib.h"

int	validate_operator(char **av)
{
	if (av[2][0] != '+' && av[2][0] != '-' && av[2][0] != '*' \
		&& av[2][0] != '/' && av[2][0] != '%')
		return (0);
	if (av[2][1] != '\0')
		return (0);
	return (1);
}

int	set_operator(char **av)
{
	if (av[2][0] == '+')
		return (0);
	else if (av[2][0] == '-')
		return (1);
	else if (av[2][0] == '*')
		return (2);
	else if (av[2][0] == '/')
		return (3);
	else
		return (4);
}

void	print_error(int op)
{
	if (op == 3)
		ft_putstr("Stop : division by zero");
	else
		ft_putstr("Stop : modulo by zero");
	ft_putchar('\n');
}

void	set_args(int *left, int *right, int *op, char **av)
{
	*op = set_operator(av);
	*left = ft_atoi(av[1]);
	*right = ft_atoi(av[3]);
}
