/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:47:50 by gozon             #+#    #+#             */
/*   Updated: 2024/08/27 08:56:00 by gozon            ###   ########.fr       */
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
