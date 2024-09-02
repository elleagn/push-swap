/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_args_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:58:33 by gozon             #+#    #+#             */
/*   Updated: 2024/08/28 08:39:37 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates the length of the string resulting of the concatenation of all the
// members of a null-terminated string array, separated by a space.
int	total_length(char **array)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		len += ft_strlen(array[i]);
		i++;
		if (array[i])
			len += 1;
	}
	return (len);
}

// Takes a string array as argument and returns a new string, concatenating all
// the strings together.
// Returns the new string or NULL if a memory allocation occurs.
char	*strjoin_all(char **array)
{
	char	*str;
	int		len;
	int		i;

	if (!array)
		return (NULL);
	len = total_length(array);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (array[i])
	{
		ft_strlcat(str, array[i], len + 1);
		ft_strlcat(str, " ", len + 1);
		i++;
	}
	return (str);
}

// Takes a string array, and if the concanated string is a sequence of integers,
// returns an array of the integers.
char	**args_to_array(char **argv)
{
	char	*str;
	char	**array;

	str = strjoin_all(argv);
	if (!str)
		return (NULL);
	if (!is_valid(str))
		return (free(str), NULL);
	array = ft_split(str, ' ');
	free(str);
	return (array);
}

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

void	print_array(char **array)
{
	int	i;

	i = 0;
	ft_printf("Sorted array: ");
	while (array[i])
	{
		if (!array[i + 1])
			ft_printf("%s\n", array[i]);
		else
			ft_printf("%s ", array[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char		**splitted;

	if (argc < 2)
		return (0);
	splitted = args_to_array(&argv[1]);
	if (!splitted)
		return (ft_putstr_fd("Error\n", 2), 1);
	print_array(splitted);
	free_array(splitted);
	return (0);
}
