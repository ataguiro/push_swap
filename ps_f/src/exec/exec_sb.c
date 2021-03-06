/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:01:05 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:36:30 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	exec_sb(void)
{
	write(1, "sb\n", 3);
	if (stack()->top_b > 0)
	{
		ft_swap(&(stack()->stack_b[stack()->top_b]), \
		&(stack()->stack_b[stack()->top_b - 1]));
	}
}
