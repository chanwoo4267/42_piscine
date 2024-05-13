/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:21:27 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/13 07:21:20 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	hexdump_stdin(char **av, int ac)
{
	t_hexdump	vars;

	initialize_hexdump(&vars);
	set_flag(&vars, av, ac);
	vars.fd = 0;
	read_until_eof(&vars);
	if (vars.current_bytes != 0)
		print_by_flag(&vars, 1);
	vars.total_bytes += vars.current_bytes;
	if (vars.total_bytes != 0)
		print_by_flag(&vars, 2);
	return (vars.result);
}

void	bad_file_des(char **av, int ac)
{
	unsigned int	bytes;
	char			buffer[10];

	bytes = read(99, buffer, 10);
	print_error(av[0], av[ac - 1]);
}
