/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:07:40 by gozon             #+#    #+#             */
/*   Updated: 2024/08/28 12:17:35 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cleans up the stacks and structs of push_swap
void	cleanup(t_push_swap *push_swap)
{
	stack_clear(&(push_swap->stack_a));
	stack_clear(&(push_swap->stack_b));
	free(push_swap);
}

// Inits the push_swap struct
t_push_swap	*init(void)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	push_swap->size = -1;
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	return (push_swap);
}
