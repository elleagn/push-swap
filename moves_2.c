/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:04:50 by gozon             #+#    #+#             */
/*   Updated: 2024/09/03 09:57:48 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of b and put it at the top of a.
// Do nothing if a is empty.
void	do_pa(t_push_swap *push_swap)
{
	t_stack	*element;

	if (push_swap->stack_b != NULL)
	{
		element = stack_pop(&(push_swap->stack_b));
		stack_push(&(push_swap->stack_a), element);
		ft_printf("pa\n");
	}
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	do_pb(t_push_swap *push_swap)
{
	t_stack	*element;

	if (push_swap->stack_a != NULL)
	{
		element = stack_pop(&(push_swap->stack_a));
		stack_push(&(push_swap->stack_b), element);
		ft_printf("pb\n");
	}
}

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	do_ra(t_push_swap *push_swap)
{
	if (push_swap->stack_a != NULL)
	{
		push_swap->stack_a = push_swap->stack_a->next;
		ft_printf("ra\n");
	}
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	do_rb(t_push_swap *push_swap)
{
	if (push_swap->stack_b != NULL)
	{
		push_swap->stack_b = push_swap->stack_b->next;
		ft_printf("rb\n");
	}
}

// ra and rb at the same time.
void	do_rr(t_push_swap *push_swap)
{
	if (push_swap->stack_b != NULL && push_swap->stack_a != NULL)
	{
		push_swap->stack_a = push_swap->stack_a->next;
		push_swap->stack_b = push_swap->stack_b->next;
		ft_printf("rr\n");
	}
}
