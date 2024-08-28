/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:01:25 by gozon             #+#    #+#             */
/*   Updated: 2024/08/28 08:07:14 by gozon            ###   ########.fr       */
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

int	sort_and_check_duplicates(t_push_swap *push_swap)
{
	int	i;

	i = 0;
	quick_sort(push_swap->sorted, push_swap->size);
	while (i < push_swap->size - 1)
	{
		if (push_swap->sorted[i] == push_swap->sorted[i + 1])
			return (1);
		i++;
	}
	return (0);
}

// Checks for errors and fills stack a
int	fill_stack_a(t_push_swap *push_swap, char **splitted)
{
	int		number;
	int		i;
	t_stack	*element;

	push_swap->size = nmemb(splitted);
	push_swap->sorted = malloc(push_swap->size * sizeof(int));
	if (!push_swap->sorted)
		return (1);
	i = 0;
	while (splitted[i])
	{
		number = ft_atoi(splitted[i]);
		if (!number && !is_zero(splitted[i]))
			return (1);
		push_swap->sorted[i] = number;
		element = new(number);
		if (!element)
			return (1);
		stack_push(&(push_swap->stack_a), element);
		i++;
	}
	if (sort_and_check_duplicates(push_swap))
		return (1);
	return (0);
}
