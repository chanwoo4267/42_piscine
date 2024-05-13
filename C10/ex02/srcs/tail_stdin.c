/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:36:04 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/13 03:03:15 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	print_all(char **buffer, unsigned long long i, unsigned long long j)
{
	while (j < i)
	{
		write(1, buffer[j], ft_strlen(buffer[j]));
		j++;
	}
}

char	**make_buffer(char **buffer, unsigned long long *i, \
						unsigned long long *total_bytes)
{
	unsigned long long	bytes;

	while (1)
	{
		buffer[(*i)] = malloc(sizeof(char) * 1000001);
		bytes = read(0, buffer[(*i)], 1000000);
		if (bytes == 0)
			break ;
		else
		{
			buffer[*i][bytes] = '\0';
			(*i)++;
			(*total_bytes) += bytes;
		}
	}
	return (buffer);
}

void	initialize_stdin(unsigned long long *i, unsigned long long *j, \
							unsigned long long *total_bytes)
{
	*i = 0;
	*j = 0;
	*total_bytes = 0;
}

void	stdin_loop(char *exec_name, char *path, unsigned long long len)
{
	unsigned long long	i;
	unsigned long long	j;
	unsigned long long	total_bytes;
	char				**buffer;

	initialize_stdin(&i, &j, &total_bytes);
	buffer = malloc(sizeof(char *) * (len + 1));
	if (errno != 0)
	{
		print_error(exec_name, path);
		return ;
	}
	buffer = make_buffer(buffer, &i, &total_bytes);
	if (len >= total_bytes)
		print_all(buffer, i, j);
	else
	{
		total_bytes -= len;
		len = 0;
		while (len + ft_strlen(buffer[j]) < total_bytes)
			len += ft_strlen(buffer[j++]);
		len = total_bytes - len;
		write(1, buffer[j] + len, ft_strlen(buffer[j]) - len);
		print_all(buffer, i, ++j);
	}
}
