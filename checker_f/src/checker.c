/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:27:02 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/17 14:11:46 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	actually_check(int *a)
{
	int	min;
	int	i;

	i = stack()->top_a;
	if (stack()->top_b > -1)
	{
		write(2, "KO\n", 3);
		return ;
	}
	min = a[i];
	while (--i >= 0)
	{
		if (a[i] < min)
		{
			write(2, "KO\n", 3);
			return ;
		}
		min = a[i];
	}
	write(2, "OK\n", 3);
}

static int	is_instruction(char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb")
	|| !ft_strcmp(line, "ss") || !ft_strcmp(line, "pa")
	|| !ft_strcmp(line, "pb") || !ft_strcmp(line, "ra")
	|| !ft_strcmp(line, "rb") || !ft_strcmp(line, "rr")
	|| !ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb")
	|| !ft_strcmp(line, "rrr"))
		return (1);
	return (0);
}

static void	init_stack(char **av)
{
	stack()->stack_a = ft_datodi(av);
	stack()->top_a = ft_tablen(av) - 1;
	stack()->stack_b = (int *)ft_memalloc(sizeof(int) * stack()->top_a);
	stack()->top_b = -1;
}

static void	exec_stack(int flag, int speed)
{
	char	line[4096];

	while (ft_readline(line, 0) > 0)
	{
		if (!is_instruction(line))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		!(ft_strcmp(line, "sa")) ? exec_sa() : 0;
		!(ft_strcmp(line, "sb")) ? exec_sb() : 0;
		!(ft_strcmp(line, "ss")) ? exec_ss() : 0;
		!(ft_strcmp(line, "pa")) ? exec_pa() : 0;
		!(ft_strcmp(line, "pb")) ? exec_pb() : 0;
		!(ft_strcmp(line, "ra")) ? exec_ra() : 0;
		!(ft_strcmp(line, "rb")) ? exec_rb() : 0;
		!(ft_strcmp(line, "rr")) ? exec_rr() : 0;
		!(ft_strcmp(line, "rra")) ? exec_rra() : 0;
		!(ft_strcmp(line, "rrb")) ? exec_rrb() : 0;
		!(ft_strcmp(line, "rrr")) ? exec_rrr() : 0;
		flag ? display(line) : 0;
		flag ? usleep(speed) : 0;
	}
	actually_check(stack()->stack_a);
}

int			main(int ac, char **av)
{
	int	flag;
	int	speed;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (!ft_strcmp("-h", av[1]))
	{
		ft_printf("Usage: ./checker args [-G[sleeptimems]]\n");
		ft_printf("Exemple : ./checker 1 4 5 2 -G70000\n");
		exit(EXIT_SUCCESS);
	}
	flag = 0;
	speed = 0;
	flag = av[ac - 1] && !ft_strncmp(av[ac - 1], "-G", 2);
	flag ? speed = ft_atoi(&(av[ac - 1])[2]) : 0;
	flag ? av[ac - 1] = 0 : 0;
	!speed ? speed = 70000 : 0;
	++av;
	check_errors(av);
	init_stack(av);
	flag ? display("") : 0;
	flag ? usleep(speed) : 0;
	exec_stack(flag, speed);
	return (0);
}
