/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:01:05 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:36:05 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	exec_rr(void)
{
	write(1, "rr\n", 3);
	exec_ra();
	exec_rb();
}
