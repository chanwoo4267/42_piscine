/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:13:30 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/04 17:07:16 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_num_len(unsigned int number, int radix, int negative);
int	is_space(char c);
int	is_base_valid(char *str);

int	convert_base(char *base, char match)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == match)
			return (i);
		i++;
	}
	return (-1);
}

int	get_string_len(int len, int i, int negative)
{
	if (negative)
		return (len - i);
	else
		return (len - i - 1);
}

char	*ft_int_to_base(char *base, unsigned int number, int negative)
{
	int		i;
	int		radix;
	int		len;
	char	*str;

	radix = ft_strlen(base);
	len = ft_num_len(number, radix, negative);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (negative)
	{
		i = 1;
		str[0] = '-';
	}
	else
		i = 0;
	while (i < len)
	{
		str[get_string_len(len, i, negative)] = base[number % radix];
		number /= radix;
		i++;
	}
	str[len] = '\0';
	return (str);
}

void	move_i_to_start(int *i, int *minus, char *nbr, unsigned int *result)
{
	*result = 0;
	*minus = 1;
	*i = 0;
	while (is_space(nbr[*i]))
		(*i)++;
	while (nbr[*i] == '+' || nbr[*i] == '-')
	{
		if (nbr[*i] == '-')
			(*minus) *= -1;
		(*i)++;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				radix;
	int				minus;
	int				converted;
	int				i;
	unsigned int	result;

	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (NULL);
	radix = ft_strlen(base_from);
	move_i_to_start(&i, &minus, nbr, &result);
	converted = convert_base(base_from, nbr[i]);
	while (converted != -1)
	{
		result *= radix;
		result += converted;
		i++;
		converted = convert_base(base_from, nbr[i]);
	}
	if (result == 0)
		minus = 1;
	if (minus > 0)
		return (ft_int_to_base(base_to, result, 0));
	else
		return (ft_int_to_base(base_to, result, 1));
}
