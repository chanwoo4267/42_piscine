/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:29:35 by chanwopa          #+#    #+#             */
/*   Updated: 2022/08/27 11:18:41 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_capitalize(char c)
{
	if (c <= 'z' && c >= 'a')
		return (0);
	else if (c <= 'Z' && c >= 'A')
		return (0);
	else if (c <= '9' && c >= '0')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	capitalize_flag;
	int	i;

	capitalize_flag = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (capitalize_flag && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (!capitalize_flag && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		capitalize_flag = check_capitalize(str[i]);
		i++;
	}
	return (str);
}
