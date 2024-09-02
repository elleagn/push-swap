/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:39:35 by gozon             #+#    #+#             */
/*   Updated: 2024/08/29 13:10:22 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_pos(int number, t_stack	*stack)
{
	int		pos;
	t_stack	*element;

	pos = 0;
	if (!stack)
		return (stack);
	element = stack;
	while (element->next != stack && element->number > number)
	{
		element = element->next;
		pos += 1;
	}
	if (element->next == stack)
		return (0);
	return (pos);
}

void	find_cheapest_move(t_push_swap	*push_swap)
{
	t_stack	*element;
	int		pos_a;
	int		pos_b;

	element = push_swap->stack_a;
	pos_a = 0;
	while (pos_a < push_swap->size - push_swap->size_b
		&& push_swap->next_move->total > 1)
	{
		pos_b = target_pos(element->number, push_swap->stack_b);
		cheapest_move_by_element(pos_a, pos_b, push_swap);
		element = element->next;
		pos_a++;
	}
}

void	do_move(t_push_swap	*push_swap)
{
	int	i;

	i = -1;
	while (++i < push_swap->next_move->ra)
		do_ra(push_swap);
	i = -1;
	while (++i < push_swap->next_move->rb)
		do_rb(push_swap);
	i = -1;
	while (++i < push_swap->next_move->rr)
		do_ra(push_swap);
	i = -1;
	while (++i < push_swap->next_move->rra)
		do_ra(push_swap);
	i = -1;
	while (++i < push_swap->next_move->rrb)
		do_ra(push_swap);
	i = -1;
	while (++i < push_swap->next_move->rrr)
		do_ra(push_swap);
}

void	stack_a_to_stack_b(t_push_swap *push_swap)
{
	while (push_swap->size - push_swap->size_b > 3)
	{
		push_swap->next_move->total = push_swap->size;
		find_cheapest_move(push_swap);
		do_move(push_swap);
		do_pa(push_swap);
		push_swap->size_b += 1;
	}
}
