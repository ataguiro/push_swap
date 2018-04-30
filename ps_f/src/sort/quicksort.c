/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:39:00 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/08 18:33:17 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdio.h>

static void	get_max(int *a)
{
	int	i;

	i = stack()->top_b + 1;
	stack()->max[1] = 0;
	stack()->bmax[1] = 0;
	stack()->max[0] = a[0];
	stack()->bmax[0] = a[0];
	while (--i >= 0)
	{
		if (a[i] > stack()->max[0])
		{
			stack()->max[0] = a[i];
			stack()->max[1] = i;
		}
	}
	i = stack()->top_b + 1;
	while (--i >= 0)
	{
		if (a[i] > stack()->bmax[0] && a[i] != stack()->max[0])
		{
			stack()->bmax[0] = a[i];
			stack()->bmax[1] = i;
		}
	}
}

static void	partition(void)
{
	int	i;
	int	med;

	if (is_sorted(stack()->stack_a, stack()->top_a) || stack()->top_a <= 0)
		return ;
	i = stack()->top_a + 1;
	med = tl_median(stack()->stack_a, stack()->top_a);
	while (--i >= 0)
	{
		stack()->middle = (stack()->top_a / 2) + (stack()->top_a % 2);
		if (stack()->stack_a[i] <= med)
		{
			p_track_it(stack()->stack_a[i], i);
			exec_pb();
			i = stack()->top_a + 1;
		}
	}
	partition();
}

static void	sort(void)
{
	while (stack()->top_b > -1)
	{
		stack()->middle = (stack()->top_b / 2) + (stack()->top_b % 2);
		get_max(stack()->stack_b);
		swap_b();
		track_b(stack()->max[0], stack()->max[1]);
		exec_pa();
	}
}

void		quicksort(void)
{
	partition();
	sort();
}
