/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:38:00 by chanwopa          #+#    #+#             */
/*   Updated: 2022/08/29 20:56:56 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_strlen(char *str)
{
	long long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_single_inbase(int data, char *base)
{
	char	c;

	c = base[data];
	write(1, &c, 1);
}

int	check_invalid_parameter(long long base_len, char *base)
{
	int	i;
	int	j;

	if (base_len <= 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base_long(long long nbr, char *base)
{
	long long	base_len;

	base_len = ft_strlen(base);
	if (check_invalid_parameter(base_len, base))
		return ;
	if (nbr < 0)
	{
		write(1, &"-", 1);
		ft_putnbr_base_long(-nbr, base);
	}
	else
	{
		if (nbr >= base_len)
			ft_putnbr_base_long(nbr / base_len, base);
		print_single_inbase(nbr % base_len, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	ft_putnbr_base_long(nbr, base);
}
