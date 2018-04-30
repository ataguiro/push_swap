/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:01:05 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:36:25 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	exec_sa(void)
{
	write(1, "sa\n", 3);
	if (stack()->top_a > 0)
	{
		ft_swap(&(stack()->stack_a[stack()->top_a]), \
		&(stack()->stack_a[stack()->top_a - 1]));
	}
}