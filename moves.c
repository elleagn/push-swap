/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:47:50 by gozon             #+#    #+#             */
/*   Updated: 2024/09/03 09:58:00 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1.
// The last element becomes the first one.
void	do_rra(t_push_swap *push_swap)
{
	if (push_swap->stack_a != NULL)
	{
		push_swap->stack_a = push_swap->stack_a->previous;
		ft_printf("rra\n");
	}
}

// Shift up all elements of stack b by 1.
// The last element becomes the first one.
void	do_rrb(t_push_swap *push_swap)
{
	if (push_swap->stack_b != NULL)
	{
		push_swap->stack_b = push_swap->stack_b->previous;
		ft_printf("rrb\n");
	}
}

// Swap the first 2 elements at the top of stack a.
// Only made to work with stacks of size 3.
void	do_sa(t_push_swap *push_swap)
{
	t_stack	*top;
	t_stack	*middle;
	t_stack	*bottom;

	top = push_swap->stack_a;
	middle = push_swap->stack_a->next;
	bottom = push_swap->stack_a->previous;
	top->next = bottom;
	top->previous = middle;
	middle->next = top;
	middle->previous = bottom;
	bottom->next = middle;
	bottom->previous = top;
	push_swap->stack_a = middle;
	ft_printf("sa\n");
}

// rra and rrb at the same time.
void	do_rrr(t_push_swap *push_swap)
{
	if (push_swap->stack_b != NULL && push_swap->stack_a != NULL)
	{
		push_swap->stack_a = push_swap->stack_a->previous;
		push_swap->stack_b = push_swap->stack_b->previous;
		ft_printf("rrr\n");
	}
}
