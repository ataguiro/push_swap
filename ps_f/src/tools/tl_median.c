/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:29:45 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/08 18:24:37 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdio.h>
#include <stdbool.h>

static int	sort(int *stack, int size)
{
	int	min;
	int	i;
	int	j;
	int	level;

	i = -1;
	level = ((1.0 / 62.0) * size + 5.0 / 2.3) + 0.5;
	while (++i <= size)
	{
		min = i;
		j = i;
		while (++j <= size)
			if (stack[j] < stack[min])
				min = j;
		if (min != i)
			ft_swap(&stack[i], &stack[min]);
	}
	return (stack[size / level]);
}

int			tl_median(int *stack, int size)
{
	int	*cpy;
	int	i;
	int	median;

	i = -1;
	cpy = (int *)malloc(sizeof(int) * (size + 1));
	if (!cpy)
		exit(EXIT_FAILURE);
	while (++i <= size)
		cpy[i] = stack[i];
	median = sort(cpy, size);
	free(cpy);
	return (median);
}
