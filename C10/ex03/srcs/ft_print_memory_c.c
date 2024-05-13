/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:32:31 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/13 03:45:05 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	print_memory_nc(void *addr, char *current_addr, unsigned int size)
{
	int	i;

	i = 0;
	write(1, &" ", 1);
	while (i < 16)
	{
		if ((void *)(current_addr + i) >= addr + size)
			write(1, &"  ", 2);
		else
			write_hex((unsigned long long)*(current_addr + i), 1);
		if (i != 15)
			write(1, &" ", 1);
		i++;
	}
}

void	*ft_print_memory_nc(void *addr, unsigned int size, \
						unsigned long long i)
{
	char				*current_addr;

	current_addr = (char *)addr;
	while ((void *)current_addr < (addr + size))
	{
		write_hex(i, 6);
		print_memory_nc(addr, current_addr, size);
		write(1, &"\n", 1);
		current_addr += 16;
	}
	return (addr);
}
