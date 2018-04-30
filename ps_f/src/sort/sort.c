/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 23:27:08 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/08 18:36:54 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/*
**	ALGO 1 DESCRIPTION (deprecated ! --> used for bubblesort) :
**
**	try_to_sort will sort the stack_a using the stack_b in ascending order,
**	or die trying.
**
**	Here are above used protocols :
**	"last_case" : if b is sorted and a is reverse sorted,
**	push into stack_a from b until a is sorted, usually this ends the sort.
**	"swap_top" : the name says it all.
**	"rescue" : if 2 consecutive reverse sorted numbers are found in the
**	end part of the stack, reverse shift the stack until get them at the top
**	and perform a swap.
**	"track_it" : track the minimal number of stack_a and do everyting to put
**	it at the top of stack in the fastest way possible.
**	"we_fucked_up" : if stack_a is empty, it's the worst case scenario,
**	stack_b must be full and sorted, so push to a from b until b is empty.
**
**	NB : if one protocol successes, everything other is ignored.
**
**	How it works (pseudo-code) :
**
**	while stack not sorted:
**		try "last_case" protocol
**		try "rescue" protocol
**		try "swap_top" protocol
**		try "track_it" protocol
**		perform "push to b" if minimal number is at the top of a
**		try "we_fucked_up" protocol
**
**	At this case, stak_a must be sorted in ascending order, and stack_b must be
**	empty.
**
**	ALGO 2 DESCRIPTION :
**
**	Quicksort
*/

static void	s_case_1(int *stack, int size)
{
	int	ret;
	int	i;
	int	*cpy;

	i = -1;
	cpy = (int *)malloc(sizeof(int) * (size + 1));
	if (!cpy)
		exit(EXIT_FAILURE);
	while (++i <= size)
		cpy[i] = stack[i];
	if (is_sorted(&cpy[2], size - 2))
	{
		ret = p_rescue();
		if (!ret)
		{
			exec_ra();
			exec_ra();
		}
	}
	free(cpy);
}

static void	s_case_2(int *stack, int size)
{
	int	i;
	int	*cpy;

	i = -1;
	cpy = (int *)malloc(sizeof(int) * (size + 1));
	if (!cpy)
		exit(EXIT_FAILURE);
	while (++i <= size)
		cpy[i] = stack[i];
	if (is_sorted(cpy, size - 2))
		p_swap_top();
	free(cpy);
}

void		try_to_sort(void)
{
	if (stack()->top_a > 4)
	{
		s_case_1(stack()->stack_a, stack()->top_a);
		s_case_2(stack()->stack_a, stack()->top_a);
	}
	if (stack()->top_a <= 4)
		bubblesort();
	else
		quicksort();
}
