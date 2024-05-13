/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:56:19 by chanwopa          #+#    #+#             */
/*   Updated: 2022/08/29 20:23:55 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	str_idx;

	i = 0;
	str_idx = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[str_idx] != '\0')
	{
		i = 0;
		while (to_find[i] != '\0')
		{
			if (str[str_idx + i] != to_find[i])
				break ;
			i++;
		}
		if (to_find[i] == '\0')
			return ((char *)(str + str_idx));
		str_idx++;
	}
	return (NULL);
}
