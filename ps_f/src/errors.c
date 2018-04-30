/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:11:11 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/06 17:15:28 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	catch_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	check_digits(char **av)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (av[++i])
	{
		if (av[i][j] == '-' || av[i][j] == '+')
			++j;
		if (!av[i][j])
			catch_error();
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				catch_error();
		j = 0;
	}
}

static int	is_in_tab(int nb, char **av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (nb == ft_atoi(av[i]))
			return (1);
	}
	return (0);
}

static void	check_dup(char **av)
{
	int	i;
	int	nb;

	i = -1;
	while (av[++i])
	{
		if (i > 0 && is_in_tab(nb, &av[i]))
			catch_error();
		nb = ft_atoi(av[i]);
	}
}

void		check_errors(char **av)
{
	int				i;
	long long int	nb;

	i = -1;
	check_digits(av);
	check_dup(av);
	while (av[++i])
	{
		nb = ft_atoi(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
			catch_error();
	}
}
