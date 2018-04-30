/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:59:21 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/17 12:10:51 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/*
**	Do I really need to discribe this ?
*/

static int	need_to_swap(int a, int b)
{
	int	i;
	int	current;

	i = -1;
	current = a;
	while (++i <= stack()->top_b)
		if (stack()->stack_b[i] > a)
			current = stack()->stack_b[i];
	i = -1;
	while (++i <= stack()->top_b)
		if (stack()->stack_b[i] > a && stack()->stack_b[i] < current)
			current = stack()->stack_b[i];
	return (current == b);
}

int			swap_b(void)
{
	if (stack()->top_b > 0 && need_to_swap(stack()->stack_b[stack()->top_b], \
	stack()->stack_b[stack()->top_b - 1]))
	{
		exec_sb();
		return (0);
	}
	return (1);
}
