/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 14:49:43 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:36:59 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/*
**	If 2 consecutive reverse sorted numbers are found in the
**	end part of the stack, reverse shift the stack until get them at the top
**	and perform a swap.
*/

static int	need_to_swap(int a, int b)
{
	int	i;
	int	current;

	i = -1;
	while (++i <= stack()->top_a)
		if (stack()->stack_a[i] > a)
			current = stack()->stack_a[i];
	i = -1;
	while (++i <= stack()->top_a)
		if (stack()->stack_a[i] > a && stack()->stack_a[i] < current)
			current = stack()->stack_a[i];
	return (current == b);
}

int			p_rescue(void)
{
	if (stack()->top_a > 2
	&& need_to_swap(stack()->stack_a[0], stack()->stack_a[1]))
	{
		exec_rra();
		exec_rra();
		exec_sa();
		return (0);
	}
	if (stack()->top_a == 2
	&& need_to_swap(stack()->stack_a[0], stack()->stack_a[1]))
	{
		exec_ra();
		exec_sa();
		return (0);
	}
	return (1);
}
