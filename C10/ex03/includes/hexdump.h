/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:24:40 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/13 07:18:33 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H

# include <sys/errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_hexdump
{
	int					result;
	int					c_flag;
	int					i;
	int					fd;
	int					empty_flag;
	unsigned int		bytes;
	unsigned int		current_bytes;
	unsigned long long	total_bytes;
	char				buffer[16];
	char				buffc[2];
	char				buffer_before[16];
}				t_hexdump;

void		print_error(char *exec_name, char *path);
int			hexdump(char **av, int ac);
void		ft_hexdump(char *exec_name, char *path, int fd, int c_flag);
void		ft_putstr(int fd, char *str);
void		set_flag(t_hexdump *vars, char **av, int ac);
int			hexdump_stdin(char **av, int ac);
void		*ft_print_memory(void *addr, unsigned int size, \
								unsigned long long i);
void		print_memory(void *addr, char *current_addr, int size);
void		write_hex(unsigned long long num, int str_last_index);
void		str_number_hex(unsigned long long num, int str[16], int index);
void		write_char_safe(char *c);
void		*ft_print_memory_nc(void *addr, unsigned int size, \
							unsigned long long i);
void		print_memory_nc(void *addr, char *current_addr, \
							unsigned int size);
long long	ft_strncmp(char *s1, char *s2, unsigned long long n);
char		*ft_strncpy(char *dest, char *src, unsigned long long n);
void		read_until_eof(t_hexdump *vars);
void		print_by_flag(t_hexdump *vars, int print_case);
void		initialize_hexdump(t_hexdump *vars);
void		bad_file_des(char **av, int ac);

#endif