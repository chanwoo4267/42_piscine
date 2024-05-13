/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:50:27 by chanwopa          #+#    #+#             */
/*   Updated: 2022/09/07 13:56:19 by chanwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	operate_plus(int a, int b)
{
	return (a + b);
}

int	operate_minus(int a, int b)
{
	return (a - b);
}

int	operate_mul(int a, int b)
{
	return (a * b);
}

int	operate_div(int a, int b)
{
	return (a / b);
}

int	operate_mod(int a, int b)
{
	return (a % b);
}
