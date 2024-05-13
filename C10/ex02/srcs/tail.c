/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:16:11 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/13 03:08:37 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	print_error(char *exec_name, char *path)
{
	if (errno == 0)
		return ;
	ft_putstr(2, basename(exec_name));
	ft_putstr(2, ": ");
	ft_putstr(2, path);
	ft_putstr(2, ": ");
	ft_putstr(2, strerror(errno));
	ft_putstr(2, "\n");
	errno = 0;
}

unsigned long long	ft_tail_count(char *exec_name, char *path, int fd)
{
	unsigned long long	count;
	unsigned long long	bytes;
	char				buffer[2];

	count = 0;
	bytes = read(fd, buffer, 1);
	while (bytes > 0)
	{
		if (errno != 0)
		{
			print_error(exec_name, path);
			break ;
		}
		count++;
		bytes = read(fd, buffer, 1);
	}
	if (fd > 2)
	{
		close(fd);
		fd = open(path, O_RDONLY);
	}
	return (count);
}

void	ft_tail(int fd, unsigned long long count, unsigned long long len)
{
	unsigned long long	bytes;
	unsigned long long	i;
	char				buffer[2];

	i = 0;
	while (i < count - len)
	{
		bytes = read(fd, buffer, 1);
		i++;
	}
	while (i < count)
	{
		bytes = read(fd, buffer, 1);
		write(1, &buffer[0], 1);
		i++;
	}
	if (fd > 2)
		close(fd);
}

void	tail_operate(char **av, int fd, int i, int ent_flag)
{
	unsigned long long	len;
	unsigned long long	count;
	int					flag;

	ent_flag += 0;
	flag = 0;
	len = ft_atoi(av[2], &flag);
	count = ft_tail_count(av[0], av[i], fd);
	if (len >= count)
		len = count;
	ft_tail(fd, count, len);
}

int	tail(char **av, int ac, int ent_flag)
{
	int	result;
	int	fd;
	int	i;

	result = 0;
	i = 2;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
		{
			print_error(av[0], av[i]);
			result = 1;
		}
		else
		{
			if (ent_flag)
				write(1, "\n", ent_flag--);
			if (ac > 4)
				print_case(av[i]);
			tail_operate(av, fd, i, ++ent_flag);
		}
	}
	return (result);
}
