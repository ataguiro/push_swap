/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:22:31 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/08 18:32:57 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/*
**	Protocol "last_case"
*/

static void	equal_them(void)
{
	while (stack()->top_b != -1)
		exec_pa();
}

int			p_last_case(void)
{
	if (is_reverse_sorted(stack()->stack_b, stack()->top_b)
	&& is_sorted(stack()->stack_a, stack()->top_a))
	{
		equal_them();
		return (0);
	}
	return (1);
}
