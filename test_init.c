/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:45:23 by gozon             #+#    #+#             */
/*   Updated: 2024/09/02 14:12:44 by gozon            ###   ########.fr       */
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

void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	ft_printf("Sorted array: ");
	while (i < size)
	{
		if (i == size - 1)
			ft_printf("%i\n", array[i]);
		else
			ft_printf("%i ", array[i]);
		i++;
	}
}

void	print_stack(t_stack	*stack)
{
	t_stack	*element;

	ft_printf("Stack: %i ", stack->number);
	element = stack->next;
	while (element != stack)
	{
		ft_printf("%i ", element->number);
		element = element->next;
	}
	ft_printf("\n");
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
	if (push_swap->size > 1)
		sort(push_swap);
//	print_stack(push_swap->stack_a);
	cleanup(push_swap);
	return (0);
}
