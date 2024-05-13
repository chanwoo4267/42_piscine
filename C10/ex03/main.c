/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:38:55 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/13 03:48:25 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (hexdump_stdin(av, ac));
	else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'C' && av[1][2] == '\0')
		return (hexdump_stdin(av, ac));
	else
		return (hexdump(av, ac));
	return (1);
}
