/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move_element.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:38:06 by gozon             #+#    #+#             */
/*   Updated: 2024/09/02 08:37:10 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_rr(int pos_a, int pos_b, t_push_swap *push_swap)
{
	t_move	*move;

//	ft_printf("case rr\n");
	move = push_swap->next_move;
	if (pos_a > pos_b)
	{
		move->ra = ft_abs(pos_a - pos_b);
		move->rb = 0;
	}
	else
	{
		move->rb = ft_abs(pos_a - pos_b);
		move->ra = 0;
	}
	move->rr = ft_min(pos_a, pos_b);
	move->rra = 0;
	move->rrb = 0;
	move->rrr = 0;
	move->total = ft_min(pos_a, pos_b) + ft_abs(pos_a - pos_b);
}

void	update_rrr(int pos_a, int pos_b, t_push_swap *push_swap)
{
	t_move	*move;
	int		size_a;
	int		size_b;

//	ft_printf("case rrr\n");
	move = push_swap->next_move;
	size_a = push_swap->size - push_swap->size_b;
	size_b = push_swap->size_b;
	move->ra = 0;
	move->rb = 0;
	move->rr = 0;
	if (size_a - pos_a > size_b - pos_b)
	{
		move->rra = ft_abs((size_a - pos_a) - (size_b - pos_b));
		move->rrb = 0;
	}
	else
	{
		move->rrb = ft_abs((size_a - pos_a) - (size_b - pos_b));
		move->rra = 0;
	}
	move->rrr = ft_min(size_a - pos_a, size_b - pos_b);
	move->total = ft_min(size_a - pos_a, size_b - pos_b)
		+ ft_abs((size_a - pos_a) - (size_b - pos_b));
}

void	update_r_rr(int pos_a, int pos_b, t_push_swap *push_swap)
{
//	ft_printf("case r rr\n");
	if (pos_a > push_swap->size - push_swap->size_b - pos_a)
	{
		push_swap->next_move->ra = 0;
		push_swap->next_move->rra = push_swap->size - push_swap->size_b - pos_a;
	}
	else
	{
		push_swap->next_move->ra = pos_a;
		push_swap->next_move->rra = 0;
	}
	if (pos_b > push_swap->size_b - pos_b)
	{
		push_swap->next_move->rb = 0;
		push_swap->next_move->rrb = push_swap->size_b - pos_b;
	}
	else
	{
		push_swap->next_move->rb = pos_b;
		push_swap->next_move->rrb = 0;
	}
	push_swap->next_move->rr = 0;
	push_swap->next_move->rrr = 0;
	push_swap->next_move->total
		= ft_min(pos_a, push_swap->size - push_swap->size_b - pos_a)
		+ ft_min(pos_b, push_swap->size_b - pos_b);
}

void	cheapest_move_by_element(int pos_a, int pos_b, t_push_swap *push_swap)
{
	int	total;
	int	size_a;
	int	size_b;

	total = push_swap->next_move->total;
	size_a = push_swap->size - push_swap->size_b;
	size_b = push_swap->size_b;
	if (total > ft_min(pos_a, pos_b) + ft_abs(pos_a - pos_b))
	{
		total = ft_min(pos_a, pos_b) + ft_abs(pos_a - pos_b);
		update_rr(pos_a, pos_b, push_swap);
	}
	if (total > ft_min(size_a - pos_a, size_b - pos_b)
		+ ft_abs((size_a - pos_a) - (size_b - pos_b)))
	{
		total = ft_min(size_a - pos_a, size_b - pos_b)
			+ ft_abs((size_a - pos_a) - (size_b - pos_b));
		update_rrr(pos_a, pos_b, push_swap);
	}
	if (total > ft_min(pos_a, size_a - pos_a) + ft_min(pos_b, size_b - pos_b))
	{
		total = ft_min(pos_a, size_a - pos_a) + ft_min(pos_b, size_b - pos_b);
		update_r_rr(pos_a, pos_b, push_swap);
	}
}
