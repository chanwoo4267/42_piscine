/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:32:31 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/12 23:44:22 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	write_char_safe(char *c)
{
	if (*c >= 32 && *c != 127)
		write(1, c, 1);
	else
		write(1, &".", 1);
}

void	str_number_hex(unsigned long long num, int str[16], int index)
{
	if (num >= 16)
		str_number_hex(num / 16, str, index + 1);
	str[index] = num % 16;
}

void	write_hex(unsigned long long num, int str_last_index)
{
	int	str[16];
	int	i;
	int	rev_i;

	i = 0;
	while (i <= 15)
	{
		str[i] = 0;
		i++;
	}
	str_number_hex(num, str, 0);
	i = 0;
	while (i <= str_last_index)
	{
		rev_i = str_last_index - i;
		write(1, &"0123456789abcdef"[str[rev_i]], 1);
		i++;
	}
}

void	print_memory(void *addr, char *current_addr, int size)
{
	int	i;

	i = 0;
	write(1, &"  ", 2);
	while (i < 16)
	{
		if ((void *)(current_addr + i) >= addr + size)
			write(1, &"  ", 2);
		else
			write_hex((unsigned long long)*(current_addr + i), 1);
		write(1, &" ", 1);
		if (i == 7 || i == 15)
			write(1, &" ", 1);
		i++;
	}
	i = 0;
	write(1, &"|", 1);
	while (i < 16)
	{
		if ((void *)(current_addr + i) < addr + size)
			write_char_safe((char *)current_addr + i);
		i++;
	}
	write(1, &"|", 1);
}

void	*ft_print_memory(void *addr, unsigned int size, \
						unsigned long long i)
{
	char				*current_addr;

	current_addr = (char *)addr;
	while ((void *)current_addr < (addr + size))
	{
		write_hex(i, 7);
		print_memory(addr, current_addr, size);
		write(1, &"\n", 1);
		current_addr += 16;
	}
	return (addr);
}
