/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:59:15 by ecaceres          #+#    #+#             */
/*   Updated: 2022/09/04 17:08:02 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	find_char(char c, char *set)
{
	int	i;

	i = 0;
	while (1)
	{
		if (set[i] == '\0')
		{
			if (c == '\0')
				return (1);
			else
				return (0);
		}
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	set_find_count(char *str, char *charset)
{
	int	count;
	int	i;
	int	prev;
	int	next;

	count = 0;
	i = 0;
	prev = 0;
	next = 0;
	while (1)
	{
		if (find_char(str[i], charset))
			next = i;
		if (next - prev > 1)
			count++;
		if (str[i] == '\0')
			break ;
		prev = next;
		i++;
	}
	return (count);
}

void	input_slice(char **entry, char *prev, int size, char *charset)
{
	int	i;

	i = 0;
	if (find_char(prev[0], charset))
	{
		prev += 1;
		size -= 1;
	}
	*entry = (char *)malloc(sizeof(char) * (size + 1));
	while (prev[i] != '\0' && i < size)
	{
		(*entry)[i] = prev[i];
		i++;
	}
	(*entry)[i] = '\0';
}

void	initialize(char **origin, char **prev, char **next, char *str)
{
	*origin = str;
	*prev = str;
	*next = str;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	*origin;
	char	*prev;
	char	*next;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (set_find_count(str, charset) + 2));
	i = 0;
	initialize(&origin, &prev, &next, str);
	while (1)
	{
		if (find_char(*str, charset))
			next = str;
		if (prev == origin && next == origin + 1 && \
		!find_char(*prev, charset))
			input_slice(&arr[i++], prev, next - prev, charset);
		if (next - prev > 1)
			input_slice(&arr[i++], prev, next - prev, charset);
		if (*str == '\0')
			break ;
		prev = next;
		str++;
	}
	arr[i] = NULL;
	return (arr);
}
