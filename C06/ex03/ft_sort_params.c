/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:03:13 by chanwopa          #+#    #+#             */
/*   Updated: 2022/08/31 17:03:13 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap_cpt(char **s1, char **s2)
{
	char	*temp;

	temp = (*s1);
	(*s1) = (*s2);
	(*s2) = temp;
}

void	ft_sort_cpt(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			str1 = argv[i];
			str2 = argv[j];
			if (ft_strcmp(str1, str2) > 0)
				ft_swap_cpt(&(argv[i]), &(argv[j]));
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*ptr;

	ft_sort_cpt(argc, argv);
	i = 1;
	while (i < argc)
	{
		ptr = argv[i];
		while (*ptr)
		{
			write(1, ptr, 1);
			ptr++;
		}
		write(1, &"\n", 1);
		i++;
	}
	return (0);
}
