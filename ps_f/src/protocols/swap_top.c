/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:59:21 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/17 12:11:21 by ataguiro         ###   ########.fr       */
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
	while (++i <= stack()->top_a)
		if (stack()->stack_a[i] > a)
			current = stack()->stack_a[i];
	i = -1;
	while (++i <= stack()->top_a)
		if (stack()->stack_a[i] > a && stack()->stack_a[i] < current)
			current = stack()->stack_a[i];
	return (current == b);
}

int			p_swap_top(void)
{
	if (stack()->top_a && need_to_swap(stack()->stack_a[stack()->top_a - 1], \
	stack()->stack_a[stack()->top_a]))
	{
		exec_sa();
		return (0);
	}
	return (1);
}
