/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:39:35 by gozon             #+#    #+#             */
/*   Updated: 2024/08/30 11:49:04 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_pos(int number, t_stack	*stack)
{
	int		pos;
	t_stack	*element;

	pos = 0;
	if (!stack)
		return (0);
	element = stack;
	while (element->next != stack)
	{
		if (element->previous->number > number && number > element->number)
			return (pos);
		if (element->previous->number < element->number
			&& (element->previous->number > number || number > element->number))
			return (pos);
		element = element->next;
		pos += 1;
	}
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
		ft_printf("number: %i, traget pos: %i size: %i size b: %i\n", element->number, pos_b, push_swap->size, push_swap->size_b);
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
		do_rr(push_swap);
	i = -1;
	while (++i < push_swap->next_move->rra)
		do_rra(push_swap);
	i = -1;
	while (++i < push_swap->next_move->rrb)
		do_rrb(push_swap);
	i = -1;
	while (++i < push_swap->next_move->rrr)
		do_rrr(push_swap);
}

void	stack_a_to_stack_b(t_push_swap *push_swap)
{
	while (push_swap->size - push_swap->size_b > 3)
	{
		push_swap->next_move->total = push_swap->size + 1;
		if (push_swap->stack_b)
		{
			find_cheapest_move(push_swap);
			do_move(push_swap);
		}
		do_pb(push_swap);
		print_stack(push_swap->stack_a);
		print_stack(push_swap->stack_b);
		push_swap->size_b += 1;
	}
}
