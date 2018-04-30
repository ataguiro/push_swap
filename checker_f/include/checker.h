/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:27:13 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/17 12:12:35 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

typedef struct	s_stack
{
	int			*stack_b;
	int			*stack_a;
	int			top_a;
	int			top_b;
}				t_stack;

void			display(char *line);

/*
**	Check errors
*/

void			check_errors(char **av);

/*
**	Singleton stack
*/

t_stack			*stack(void);

/*
**	Exec commands
*/

void			exec_sa(void);
void			exec_sb(void);
void			exec_ss(void);
void			exec_pa(void);
void			exec_pb(void);
void			exec_ra(void);
void			exec_rb(void);
void			exec_rr(void);
void			exec_rra(void);
void			exec_rrb(void);
void			exec_rrr(void);

#endif
