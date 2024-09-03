/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_return_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:17:32 by gozon             #+#    #+#             */
/*   Updated: 2024/09/03 09:03:11 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_return_pos(int number, t_stack	*stack)
{
	int		pos;
	t_stack	*element;

	pos = 0;
	if (!stack)
		return (0);
	element = stack;
	while (element->next != stack)
	{
		if (element->previous->number < number && number < element->number)
			return (pos);
		if (element->previous->number > element->number
			&& (element->previous->number < number || number < element->number))
			return (pos);
		element = element->next;
		pos += 1;
	}
	return (pos);
}

void	find_cheapest_return_move(t_push_swap	*push_swap)
{
	t_stack	*element;
	int		pos_a;
	int		pos_b;

	element = push_swap->stack_b;
	pos_b = 0;
	push_swap->next_move->total = push_swap->size + 1;
	while (pos_b < push_swap->size_b
		&& push_swap->next_move->total > 1)
	{
		pos_a = target_return_pos(element->number, push_swap->stack_a);
//		ft_printf("number: %i, traget pos: %i size: %i size b: %i\n", element->number, pos_b, push_swap->size, push_swap->size_b);
		cheapest_move_by_element(pos_a, pos_b, push_swap);
		element = element->next;
		pos_b++;
	}
}
