/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:02:38 by gozon             #+#    #+#             */
/*   Updated: 2024/08/26 11:18:07 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// For a given array, returns the median of the first, last and middle element.
// Pivot is chosen that way to avoid the worst case scenario of a quasi sorted
// array.
int	choose_pivot(int *array, int size)
{
	int	first;
	int	middle;
	int	last;

	first = array[0];
	last = array[size - 1];
	middle = array[size / 2];
	if ((first < middle && first > last) || (first > middle && first < last))
		return (first);
	if ((middle < first && middle > last) || (middle > first && middle < last))
		return (middle);
	return (last);
}

// Swap the values of the integers in position i and k of an integer array.
void	swap(int *array, int i, int k)
{
	int	tmp;

	tmp = array[i];
	array[i] = array[k];
	array[k] = tmp;
}

// Given an array of integers and a pivot, puts every element smaller than the
// pivot, before the pivot, and every element bigger than the pivot after the
// pivot.
int	part_array(int *array, int size, int pivot)
{
	int	i;
	int	k;

	i = 0;
	k = size - 1;
	while (i != k)
	{
		while (array[i] < pivot)
			i++;
		while (array[k] > pivot)
			k--;
		if (k != i)
			swap(array, i, k);
	}
	return (i);
}

// Sorts an array using quicksort.
void	quick_sort(int *array, int size)
{
	int	pivot;
	int	pivot_index;

	if (size == 2)
	{
		if (array[0] > array[1])
			swap(array, 0, 1);
	}
	else if (size > 2)
	{
		pivot = choose_pivot(array, size);
		pivot_index = part_array(array, size, pivot);
		if (pivot_index > 1)
			quick_sort(array, pivot_index);
		if (pivot_index < size - 2)
			quick_sort(&array[pivot_index + 1], size - pivot_index - 1);
	}
}
