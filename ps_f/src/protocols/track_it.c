/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:54:46 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:37:07 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/*
**	Tracks the selected number of stack_a and do everyting to put
**	it at the top of stack in the fastest way possible.
*/

int	p_track_it(int n, int pos)
{
	int	i;

	i = 0;
	if (stack()->stack_a[stack()->top_a] != n)
	{
		if (pos >= stack()->middle)
			while (stack()->stack_a[stack()->top_a] != n)
				exec_ra();
		else
			while (stack()->stack_a[stack()->top_a] != n)
				exec_rra();
		return (0);
	}
	else
		return (1);
}
