/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:58:46 by gozon             #+#    #+#             */
/*   Updated: 2024/08/27 08:33:40 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted;
	int		bounds[5];
	int		size;
}	t_push_swap;

// Argument verification

char	**args_to_array(char **argv);
int		is_valid(char *str);

// Stack operations

void	stack_clear(t_stack **stack);
t_stack	*stack_pop(t_stack	**stack);
void	stack_push(t_stack **stack, t_stack *element);
t_stack	*new(int number);

#endif
