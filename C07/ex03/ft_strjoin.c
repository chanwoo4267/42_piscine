/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:25:53 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/04 19:15:55 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

unsigned int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	unsigned int	src_len;
	char			*newstr;
	int				i;

	src_len = ft_strlen(src);
	newstr = (char *)malloc(sizeof(char) * (src_len + 1));
	i = 0;
	while (src[i] != '\0')
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned long long	get_length_sum(int size, char **strs, char *sep)
{
	unsigned long long	len;
	int					i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * (size - 1);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int						i;
	char					*ret_str;
	unsigned long long		len;

	if (size <= 0)
		return (ft_strdup(""));
	len = get_length_sum(size, strs, sep);
	ret_str = (char *)malloc(sizeof(char) * (len + 1));
	if (ret_str == NULL)
		return (NULL);
	ret_str[0] = '\0';
	i = 0;
	while (i < size - 1)
	{
		ft_strcat(ret_str, strs[i]);
		ft_strcat(ret_str, sep);
		i++;
	}
	ft_strcat(ret_str, strs[i]);
	ret_str[len] = '\0';
	return (ret_str);
}
