/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:45:23 by gozon             #+#    #+#             */
/*   Updated: 2024/09/05 13:37:51 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Takes a null-terminated string array as argument, and frees each of his
// components before freeing the array itself.
void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free(array);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*element;

	if (!stack)
		return (1);
	element = stack;
	while (element->next != stack)
	{
		if (element->number > element->next->number)
			return (0);
		element = element->next;
	}
	return (1);
}

// Takes as an argument the stack a formatted as a list of integers. The first
// argument should be at the top of the stack.
// Displays a list of instructions to sort the stack a using a second stack b,
// the smallest number being at the top.
// If no parameters are specified, the program does not display anything and
// gives the prompt back.
// In case of error, it displays "Error" followed by a ’\n’ on the standard
// error.
int	main(int argc, char **argv)
{
	char		**splitted;
	t_push_swap	*push_swap;
	int			error;

	if (argc < 2)
		return (0);
	splitted = args_to_array(&argv[1]);
	if (!splitted)
		return (ft_putstr_fd("Error\n", 2), 1);
	push_swap = init();
	error = fill_stack_a(push_swap, splitted);
	free_array(splitted);
	if (error)
		return (cleanup(push_swap), ft_putstr_fd("Error\n", 2), 1);
	if (push_swap->size > 1 && !is_sorted(push_swap->stack_a))
		sort(push_swap);
	cleanup(push_swap);
	return (0);
}
