/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:01:05 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:35:42 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	exec_pa(void)
{
	write(1, "pa\n", 3);
	if (stack()->top_b >= 0)
	{
		++(stack()->top_a);
		stack()->stack_a[stack()->top_a] = stack()->stack_b[stack()->top_b];
		--(stack()->top_b);
	}
}
