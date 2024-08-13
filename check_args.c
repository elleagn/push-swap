/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:13:37 by gozon             #+#    #+#             */
/*   Updated: 2024/08/13 08:29:14 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function used to check if a chracter is used as an integer sign.
// Returns 1 if str[i] is a + or - character preceded by a space and followed by
// a digit, 0 otherwise.
int	is_sign(char *str, int i)
{
	if (!str[i] || (str[i] != '+' && str[i] != '-'))
		return (0);
	if (!i == 0 && !str[i - 1] == ' ')
		return (0);
	if (!ft_isdigit(str[i + 1]))
		return (0);
	return (1);
}

// Checks if a string is representing a sequence of integers separated by
// spaces.
// Returns 1 if the string satisfies this definition and 0 otherwise.
// Does not check for integer overflow.
int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || ft_isdigit(str[i]) || is_sign(str, i))
		i++;
	if (str[i])
		return (0);
	return (1);
}
