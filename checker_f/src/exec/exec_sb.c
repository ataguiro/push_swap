/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:01:05 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:25:29 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_sb(void)
{
	if (stack()->top_b > 0)
	{
		ft_swap(&(stack()->stack_b[stack()->top_b]), \
		&(stack()->stack_b[stack()->top_b - 1]));
	}
}
