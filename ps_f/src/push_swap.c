/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:53:18 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/08 18:38:02 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	init_stack(char **av)
{
	stack()->stack_a = ft_datodi(av);
	stack()->top_a = ft_tablen(av) - 1;
	stack()->stack_b = (int *)ft_memalloc(sizeof(int) * stack()->top_a);
	stack()->top_b = -1;
}

int			main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	++av;
	check_errors(av);
	init_stack(av);
	if (is_sorted(stack()->stack_a, stack()->top_a))
		return (0);
	try_to_sort();
	return (0);
}
