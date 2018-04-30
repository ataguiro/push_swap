/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:56:52 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:36:02 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	shift_up(void)
{
	int	i;
	int	tmp;

	i = stack()->top_b + 1;
	tmp = (stack()->stack_b)[i - 1];
	while (--i > 0)
		(stack()->stack_b)[i] = (stack()->stack_b)[i - 1];
	(stack()->stack_b)[0] = tmp;
}

void		exec_rb(void)
{
	write(1, "rb\n", 3);
	if (stack()->top_b > 0)
		shift_up();
}
