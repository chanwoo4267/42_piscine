/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:44:51 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/11 12:28:50 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

void	ft_putstr(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

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

void	ft_cat(char *exec_name, char *path, int fd)
{
	unsigned int	bytes;
	char			buffer[4097];

	bytes = read(fd, buffer, 4096);
	while (bytes > 0)
	{
		if (errno != 0)
		{
			print_error(exec_name, path);
			break ;
		}
		write(1, &buffer[0], bytes);
		bytes = read(fd, buffer, 4096);
	}
	if (fd > 2)
		close(fd);
}

void	stdin_loop(void)
{
	ft_cat(0, 0, 0);
}

int	cat(char **av, int ac)
{
	int		result;
	int		fd;
	int		i;
	char	*path;

	result = 0;
	i = 1;
	while (i < ac)
	{
		path = av[i];
		fd = open(path, O_RDONLY);
		if (fd < 0)
		{
			print_error(av[0], path);
			result = 1;
		}
		else
			ft_cat(av[0], path, fd);
		i++;
	}
	return (result);
}
