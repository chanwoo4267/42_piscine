/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:15:54 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/13 03:08:06 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H

# include <sys/errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>
# include <stdlib.h>

void				print_error(char *exec_name, char *path);
unsigned long long	ft_tail_count(char *exec_name, char *path, int fd);
void				ft_tail(int fd, unsigned long long count, \
							unsigned long long len);
int					tail(char **av, int ac, int ent_flag);
void				ft_putstr(int fd, char *str);
unsigned long long	ft_atoi(char *str, int *flag);
void				print_case(char *path);
unsigned long long	ft_strlen(char *str);
void				stdin_loop(char *exec_name, char *path, \
								unsigned long long len);

#endif
