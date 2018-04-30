/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:56:52 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:26:22 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	shift_down(void)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = (stack()->stack_a)[0];
	while (++i <= stack()->top_a)
		(stack()->stack_a)[i] = (stack()->stack_a)[i + 1];
	(stack()->stack_a)[stack()->top_a] = tmp;
}

void		exec_rra(void)
{
	if (stack()->top_a > 0)
		shift_down();
}
