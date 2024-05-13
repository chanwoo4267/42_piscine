/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:55:29 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/10 18:48:18 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <sys/errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>

void	ft_putstr(int fd, char *str);
void	print_error(char *exec_name, char *path);
void	ft_cat(char *exec_name, char *path, int fd);
void	stdin_loop(void);
int		cat(char **av, int ac);

#endif
