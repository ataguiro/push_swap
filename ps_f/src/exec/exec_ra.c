/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:56:52 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:35:55 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	shift_up(void)
{
	int	i;
	int	tmp;

	i = stack()->top_a + 1;
	tmp = (stack()->stack_a)[i - 1];
	while (--i > 0)
		(stack()->stack_a)[i] = (stack()->stack_a)[i - 1];
	(stack()->stack_a)[0] = tmp;
}

void		exec_ra(void)
{
	write(1, "ra\n", 3);
	if (stack()->top_a > 0)
		shift_up();
}
