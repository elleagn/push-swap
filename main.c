/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:45:23 by gozon             #+#    #+#             */
/*   Updated: 2024/08/13 09:47:18 by gozon            ###   ########.fr       */
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
	char	**splitted;
	t_list	**stack_a;

	if (argc < 2)
		return (0);
	splitted = args_to_array(&argv[1]);
	if (!splitted)
		return (ft_putstr_fd("Error\n", 2), 1);
	stack_a = fill_stack(splitted);
	free_array(splitted);
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2), 1);
	push_swap(stack_a);
	ft_lstclear(stack_a, free);
	return (0);
}
