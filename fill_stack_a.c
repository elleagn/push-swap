/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:01:25 by gozon             #+#    #+#             */
/*   Updated: 2024/08/28 12:13:32 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the number of strings contained in a NULL terminated string array.
int	nmemb(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
		i++;
	return (i);
}

// Checks for errors and fills stack a
int	fill_stack_a(t_push_swap *push_swap, char **splitted)
{
	int		number;
	int		i;
	t_stack	*element;

	push_swap->size = nmemb(splitted);
	i = push_swap->size - 1;
	while (i >= 0)
	{
		number = ft_atoi(splitted[i]);
		if (!number && !is_zero(splitted[i]))
			return (1);
		if (is_in_stack(number, push_swap->stack_a))
			return (1);
		element = new(number);
		if (!element)
			return (1);
		stack_push(&(push_swap->stack_a), element);
		i--;
	}
	return (0);
}
