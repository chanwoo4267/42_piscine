/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:22:56 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/10 18:45:27 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

void	display(char *path)
{
	int				fd;
	unsigned int	bytes;
	char			buffer[4097];

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	bytes = read(fd, buffer, 4096);
	while (bytes > 0)
	{
		write(1, &buffer[0], bytes);
		bytes = read(fd, buffer, 4096);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		display(av[1]);
	}
	return (0);
}
