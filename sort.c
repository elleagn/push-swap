/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:21:44 by gozon             #+#    #+#             */
/*   Updated: 2024/09/03 09:08:46 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_push_swap *push_swap)
{
	int	top;
	int	middle;
	int	bottom;

	top = push_swap->stack_a->number;
	middle = push_swap->stack_a->next->number;
	bottom = push_swap->stack_a->previous->number;
	if ((top < bottom && bottom < middle) || (middle < top && top < bottom)
		|| (bottom < middle && middle < top))
		do_sa(push_swap);
}

void	smaller_to_top(t_push_swap *push_swap)
{
	int		pos;
	t_stack	*element;

	pos = 0;
	element = push_swap->stack_a;
	while (element->number > element->previous->number)
	{
		pos++;
		element = element->next;
	}
	if (pos < push_swap->size - pos)
	{
		while (pos--)
			do_ra(push_swap);
	}
	else
	{
		while (pos++ < push_swap->size)
			do_rra(push_swap);
	}
}

void	sort(t_push_swap *push_swap)
{
	t_stack	*top_a;
	int		top_b;

	if (push_swap->size >= 3)
	{
		stack_a_to_stack_b(push_swap);
		sort_three(push_swap);
		while (push_swap->stack_b)
		{
			top_a = push_swap->stack_a;
			top_b = push_swap->stack_b->number;
			if (!((top_a->previous->number < top_b && top_b < top_a->number)
					|| (top_a->previous->number > top_a->number
						&& (top_a->number > top_b
							|| top_b > top_a->previous->number))))
			{
				find_cheapest_return_move(push_swap);
				do_move(push_swap);
			}
			do_pa(push_swap);
			push_swap->size_b -= 1;
		}
	}
	smaller_to_top(push_swap);
}
