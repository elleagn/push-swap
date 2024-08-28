/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:07:40 by gozon             #+#    #+#             */
/*   Updated: 2024/08/27 10:01:22 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cleans up the stacks and structs of push_swap
void	cleanup(t_push_swap *push_swap)
{
	stack_clear(&(push_swap->stack_a));
	stack_clear(&(push_swap->stack_b));
	free(push_swap->sorted);
	push_swap->sorted = NULL;
}

// Inits the push_swap struct
t_push_swap	*init(void)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(push_swap));
	push_swap->size = -1;
	ft_bzero(push_swap->bounds, 3 * sizeof(int));
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->sorted = NULL;
	return (push_swap);
}
