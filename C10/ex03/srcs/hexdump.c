/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:24:49 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/13 07:24:02 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	initialize_hexdump(t_hexdump *vars)
{
	vars->result = 0;
	vars->current_bytes = 0;
	vars->total_bytes = 0;
	vars->empty_flag = 0;
	vars->i = 0;
	ft_strncpy(vars->buffer_before, "", 16);
}

void	set_flag(t_hexdump *vars, char **av, int ac)
{
	if (ac > 1 && av[1][0] == '-' && av[1][1] == 'C' && av[1][2] == '\0')
	{
		vars->i = 2;
		vars->c_flag = 1;
	}
	else
	{
		vars->i = 1;
		vars->c_flag = 0;
	}
}

void	print_by_flag(t_hexdump *vars, int print_case)
{
	if (print_case == 1)
	{
		if (vars->c_flag)
			ft_print_memory(&(vars->buffer[0]), vars->current_bytes, \
								vars->total_bytes);
		else
			ft_print_memory_nc(&(vars->buffer[0]), vars->current_bytes, \
									vars->total_bytes);
		vars->empty_flag = 1;
	}
	else if (print_case == 2)
	{
		if (vars->c_flag)
			write_hex(vars->total_bytes, 7);
		else
			write_hex(vars->total_bytes, 6);
		write(1, "\n", 1);
	}
}

void	read_until_eof(t_hexdump *vars)
{
	vars->bytes = read(vars->fd, vars->buffc, 1);
	while (vars->bytes != 0)
	{
		vars->buffer[vars->current_bytes] = vars->buffc[0];
		vars->current_bytes++;
		if (vars->current_bytes == 16)
		{
			if (ft_strncmp(vars->buffer, vars->buffer_before, 16) == 0)
			{
				if (vars->empty_flag == 1)
				{
					write(1, "*\n", 2);
					vars->empty_flag = 0;
				}
			}
			else
				print_by_flag(vars, 1);
			vars->total_bytes += 16;
			vars->current_bytes = 0;
			ft_strncpy(vars->buffer_before, vars->buffer, 16);
		}
		vars->bytes = read(vars->fd, vars->buffc, 1);
	}
	close(vars->fd);
}

int	hexdump(char **av, int ac)
{
	t_hexdump	vars;

	initialize_hexdump(&vars);
	set_flag(&vars, av, ac);
	while (vars.i < ac)
	{
		vars.fd = open(av[vars.i], O_RDONLY);
		if (vars.fd < 0)
		{
			vars.result = 1;
			print_error(av[0], av[vars.i]);
		}
		else
			read_until_eof(&vars);
		vars.i++;
	}
	if (vars.current_bytes != 0)
		print_by_flag(&vars, 1);
	vars.total_bytes += vars.current_bytes;
	if (vars.total_bytes != 0)
		print_by_flag(&vars, 2);
	else
		bad_file_des(av, ac);
	return (vars.result);
}
