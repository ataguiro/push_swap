/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:56:52 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:26:57 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	shift_down(void)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = (stack()->stack_b)[0];
	while (++i <= stack()->top_b)
		(stack()->stack_b)[i] = (stack()->stack_b)[i + 1];
	(stack()->stack_b)[stack()->top_b] = tmp;
}

void		exec_rrb(void)
{
	if (stack()->top_a > 0)
		shift_down();
}
