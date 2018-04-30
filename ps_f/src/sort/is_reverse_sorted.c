/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reverse_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 01:02:10 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/08 18:32:59 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	is_reverse_sorted(int *a, int top)
{
	int	min;
	int	i;

	i = top;
	min = a[i];
	if (top > -1)
	{
		while (--i >= 0)
		{
			if (a[i] > min)
				return (0);
			min = a[i];
		}
		return (1);
	}
	return (0);
}
