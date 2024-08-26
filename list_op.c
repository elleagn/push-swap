/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:39:47 by gozon             #+#    #+#             */
/*   Updated: 2024/08/26 13:59:40 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates a new stack, with the given integer as a value for the element.
t_stack	*new(int number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = number;
	new->next = new;
	new->previous = new;
}

// Adds an element to the stack.
t_stack	*stack_add(t_stack *stack, t_stack *element)
{
	t_stack	*last;

	last = stack->previous;
	last->next = element;
	element->previous = last;
	element->next = stack;
	stack->previous = element;
	return (element);
}

// Clears the stack and sets the pointer to NULL.
void	stack_clear(t_stack **stack)
{
	t_stack	*element;

	element = (*stack)->next;
	while (element != *stack)
	{
		element = element->next;
		free(element->previous);
	}
	free(element);
	*stack = NULL;
}
