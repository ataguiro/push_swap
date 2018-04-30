/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:53:29 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/07 15:35:15 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

typedef struct	s_stack
{
	int			*stack_b;
	int			*stack_a;
	int			top_a;
	int			top_b;
	int			min[2];
	int			bmin[2];
	int			max[2];
	int			bmax[2];
	int			middle;
}				t_stack;

/*
**	Errors
*/

void			check_errors(char **av);

/*
**	Singleton stack
*/

t_stack			*stack(void);

/*
**	Sort the stack, or die trying
**	+ protocols
*/

void			try_to_sort(void);
void			quicksort(void);
void			bubblesort(void);

/*
**	Protocols... Deprecated
*/

int				p_last_case(void);
int				p_swap_top(void);
int				p_rescue(void);
int				p_track_it(int n, int pos);
int				p_we_fucked_up(void);

/*
**	Tools-like functions
*/

int				is_sorted(int *a, int top);
int				is_reverse_sorted(int *a, int top);
int				track_b(int n, int pos);
int				swap_b(void);
int				tl_median(int *stack, int size);

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
