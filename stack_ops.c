/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:39:47 by gozon             #+#    #+#             */
/*   Updated: 2024/08/28 11:53:56 by gozon            ###   ########.fr       */
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
	return (new);
}

// Pushes an element to the stack.
void	stack_push(t_stack **stack, t_stack *element)
{
	t_stack	*last;

	if (*stack)
	{
		last = (*stack)->previous;
		last->next = element;
		element->previous = last;
		element->next = *stack;
		(*stack)->previous = element;
	}
	(*stack) = element;
}

// Pops an element from the stack, and returnsit.
t_stack	*stack_pop(t_stack	**stack)
{
	t_stack	*element;

	if (*stack == NULL)
		return (NULL);
	element = *stack;
	if (element->next == element)
	{
		*stack = NULL;
		return (element);
	}
	(*stack)->previous->next = element->next;
	(*stack)->next->previous = element->previous;
	element->next = element;
	element->previous = element;
	return (element);
}

// Clears the stack and sets the pointer to NULL.
void	stack_clear(t_stack **stack)
{
	t_stack	*element;

	if (*stack == NULL)
		return ;
	element = (*stack)->next;
	while (element != *stack)
	{
		element = element->next;
		free(element->previous);
	}
	free(element);
	*stack = NULL;
}

// Checks if a number is in the pile.
int	is_in_stack(int number, t_stack *stack)
{
	t_stack	*element;

	if (!stack)
		return (0);
	if (stack->number == number)
		return (1);
	element = stack->next;
	while (element != stack)
	{
		if (stack->number == number)
			return (1);
		element = element->next;
	}
	return (0);
}
