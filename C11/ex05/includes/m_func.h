/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_func.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:11:57 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/07 14:24:33 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_FUNC_H
# define M_FUNC_H

int		validate_operator(char **av);
int		set_operator(char **av);
void	print_error(int op);
void	set_args(int *left, int *right, int *op, char **av);

#endif
