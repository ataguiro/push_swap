/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 23:23:51 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/06 12:09:01 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	track_b(int n, int pos)
{
	int	i;

	i = 0;
	if (stack()->stack_b[stack()->top_b] != n)
	{
		if (pos >= stack()->middle)
			while (stack()->stack_b[stack()->top_b] != n)
				exec_rb();
		else
			while (stack()->stack_b[stack()->top_b] != n)
				exec_rrb();
		return (0);
	}
	else
		return (1);
}
