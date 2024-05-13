/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:28:10 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/13 03:07:04 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	invalid_arg(char *exec_name, char *arg)
{
	ft_putstr(2, basename(exec_name));
	ft_putstr(2, ": ");
	ft_putstr(2, "illegal offset -- ");
	ft_putstr(2, arg);
	ft_putstr(2, "\n");
}

int	main(int ac, char **av)
{
	unsigned long long	len;
	int					flag;

	flag = 0;
	if (ac >= 3)
	{
		len = ft_atoi(av[2], &flag);
		if (flag == 1)
		{
			invalid_arg(av[0], av[2]);
			return (1);
		}
	}
	if (ac == 3 && av[1][0] == '-' && av[1][1] == 'c')
		stdin_loop(av[0], "malloc", len);
	else if (ac > 3)
		return (tail(av, ac, 0));
	return (1);
}
