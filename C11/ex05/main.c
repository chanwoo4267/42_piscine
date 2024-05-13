/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:47:36 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/07 15:38:11 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"
#include "ft_lib.h"
#include "m_func.h"

void	set_func(int (*fp[5])(int, int))
{
	fp[0] = operate_plus;
	fp[1] = operate_minus;
	fp[2] = operate_mul;
	fp[3] = operate_div;
	fp[4] = operate_mod;
}

int	main(int ac, char **av)
{
	int	left;
	int	right;
	int	op;
	int	(*fp[5])(int, int);

	if (ac == 4)
	{
		if (!validate_operator(av))
		{
			write(1, &"0\n", 2);
			return (0);
		}
		set_args(&left, &right, &op, av);
		if ((op == 3 || op == 4) && right == 0)
		{
			print_error(op);
			return (0);
		}
		set_func(fp);
		ft_putnbr(fp[op](left, right));
		ft_putchar('\n');
	}
	return (0);
}
