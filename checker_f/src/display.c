/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:34:27 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:32:26 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#define SA ".: STACK A :."
#define SB ".: STACK B :."

static void	gear1(int *a, int *i)
{
	int	space;
	int	k;

	k = 0;
	if (*i <= stack()->top_a)
	{
		space = ft_strlen(SA) - ft_intlength(a[*i]);
		ft_putstr("\033[1;93m|\033[0m");
		while (k++ <= (space / 2))
			ft_putchar(' ');
		k = 0;
		ft_printf("\033[1;36m%d\033[0m", a[*i]);
		while (k++ <= (space / 2 + (space % 2)))
			ft_putchar(' ');
		ft_putstr("\033[1;93m|  ");
	}
	else
		ft_printf("\033[1;93m|               |  ");
}

static void	gear2(int *b, int *i)
{
	int	space;
	int	k;

	k = 0;
	if (*i <= stack()->top_b)
	{
		space = ft_strlen(SB) - ft_intlength(b[*i]);
		ft_putstr("|\033[0m");
		while (k++ <= (space / 2))
			ft_putchar(' ');
		k = 0;
		ft_printf("\033[1;31m%d\033[0m", b[*i]);
		while (k++ <= (space / 2 + (space % 2)))
			ft_putchar(' ');
		ft_putstr("\033[1;93m|\033[0m");
	}
	else
		ft_printf("\033[1;93m|               |\033[0m");
}

static void	print_num(int *a, int *b)
{
	int	i;

	i = stack()->top_a > stack()->top_b \
	? stack()->top_a + 1 : stack()->top_b + 1;
	while ((--i <= stack()->top_a && i > -1) || (i <= stack()->top_b && i > -1))
	{
		gear1(a, &i);
		gear2(b, &i);
		ft_putchar('\n');
	}
}

static void	print_stack(int *a, int *b, char *line)
{
	ft_printf("\033[H\033[J\n\n");
	ft_printf("\033[1;31m____ _  _ ____ ____ _  _ ____ ____\n");
	ft_printf("|    |__| |___ |    |_/  |___ |__/\n");
	ft_printf("|___ |  | |___ |___ | \\_ |___ |  \\\n");
	ft_printf("                    by ataguiro\033[0m\n");
	ft_printf(" \033[1;93m_______________    _______________\033[0m\n");
	ft_printf("\033[1;93m|\033[0m \033[1;32m.: STACK A :.\033[0m \033[1;93m|");
	ft_printf("  | \033[1;32m.: STACK B :.\033[0m \033[1;93m|\n");
	ft_printf(" ---------------    ---------------\033[0m\n");
	print_num(a, b);
	ft_printf(" \033[1;93m---------------    ---------------\033[0m\n");
	ft_printf("\n\033[1;32mLast command : \033[1;31m%s\033[0m\n", line);
}

void		display(char *line)
{
	int			*a;
	int			*b;
	static int	i = 0;

	a = stack()->stack_a;
	b = stack()->stack_b;
	print_stack(a, b, line);
	ft_printf("\033[1;95m>> \033[1;91m%d\033[0m \033[1;95m<<\033[0m\n", i);
	++i;
}
