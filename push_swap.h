/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:58:46 by gozon             #+#    #+#             */
/*   Updated: 2024/08/29 14:36:07 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_move;

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	int		size_b;
	t_move	*next_move;
}	t_push_swap;

// Argument verification

char		**args_to_array(char **argv);
int			is_valid(char *str);
int			is_zero(char *str);

// Stack operations

void		stack_clear(t_stack **stack);
t_stack		*stack_pop(t_stack	**stack);
void		stack_push(t_stack **stack, t_stack *element);
t_stack		*new(int number);
int			is_in_stack(int number, t_stack *stack);

// Push_swap moves

void		do_pa(t_push_swap *push_swap);
void		do_pb(t_push_swap *push_swap);
void		do_ra(t_push_swap *push_swap);
void		do_rb(t_push_swap *push_swap);
void		do_rr(t_push_swap *push_swap);
void		do_rra(t_push_swap *push_swap);
void		do_rrb(t_push_swap *push_swap);
void		do_rrr(t_push_swap *push_swap);
void		do_move(t_push_swap *push_swap);

// Init and cleanup functions

void		cleanup(t_push_swap *push_swap);
t_push_swap	*init(void);
int			fill_stack_a(t_push_swap *push_swap, char **splitted);

// Basic maths

int			ft_min(int n1, int n2);
int			ft_abs(int n);

// Cheapest move calculation

void		cheapest_move_by_element(int pos_a, int pos_b,
				t_push_swap *push_swap);

// Stack sorting
void		stack_a_to_stack_b(t_push_swap *push_swap);

// debug

void		print_stack(t_stack	*stack);

#endif
