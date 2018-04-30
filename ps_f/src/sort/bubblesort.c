/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:21:42 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/08 18:34:53 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	get_depends(int *a)
{
	int	i;

	i = stack()->top_a;
	stack()->min[0] = a[i];
	stack()->bmin[0] = a[i];
	stack()->middle = (i / 2) + (i % 2);
	stack()->min[1] = i;
	stack()->bmin[1] = i;
	while (--i >= 0)
	{
		if (a[i] < stack()->min[0])
		{
			stack()->min[0] = a[i];
			stack()->min[1] = i;
		}
	}
	i = stack()->top_a;
	while (--i >= 0)
	{
		if (a[i] < stack()->bmin[0] && a[i] != stack()->min[0])
		{
			stack()->bmin[0] = a[i];
			stack()->bmin[1] = i;
		}
	}
}

void		bubblesort(void)
{
	int	ret;

	ret = 1;
	while (stack()->top_a > 2)
	{
		get_depends(stack()->stack_a);
		p_track_it(stack()->min[0], stack()->min[1]);
		exec_pb();
	}
	while (!is_sorted(stack()->stack_a, stack()->top_a))
	{
		get_depends(stack()->stack_a);
		ret = 1;
		ret ? ret = p_rescue() : 0;
		ret ? ret = p_swap_top() : 0;
		ret ? ret = p_track_it(stack()->min[0], stack()->min[1]) : 0;
		ret && stack()->stack_a[stack()->top_a] == stack()->min[0] ? \
			exec_pb() : 0;
	}
	if (stack()->top_b > -1 \
	&& stack()->stack_b[0] > stack()->stack_b[stack()->top_b])
		exec_sb();
	while (stack()->top_b > -1)
		exec_pa();
}
