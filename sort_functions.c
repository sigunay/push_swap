/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:55:39 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/02 17:09:12 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack *s)
{
	if (s->stack_a[0] < s->stack_a[1]
		&& s->stack_a[0] > s->stack_a[2] && s->stack_a[1] > s->stack_a[2])
		rra(s);
	if (s->stack_a[0] > s->stack_a[1]
		&& s->stack_a[1] < s->stack_a[2] && s->stack_a[0] < s->stack_a[2])
		sa(s);
	if
	(s->stack_a[0] > s->stack_a[1]
		&& s->stack_a[0] > s->stack_a[2] && s->stack_a[1] < s->stack_a[2])
		ra(s);
	if (s->stack_a[0] > s->stack_a[1]
		&& s->stack_a[0] > s->stack_a[2] && s->stack_a[1] > s->stack_a[2])
	{
		sa(s);
		rra(s);
	}
	if (s->stack_a[0] < s->stack_a[1]
		&& s->stack_a[0] < s->stack_a[2] && s->stack_a[1] > s->stack_a[2])
	{
		sa(s);
		ra(s);
	}
	return (1);
}

void	bubble_sort(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	find_pivot(int *pivot, int *stack_a, int size)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return ;
	i = 0;
	while (i < size)
	{
		tmp[i] = stack_a[i];
		i++;
	}
	bubble_sort(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
}

int	is_sorted(int *stack_a, int size, int flag)
{
	int	i;

	i = 0;
	while ((flag == 0) && (++i < size))
	{
		if (stack_a[i - 1] > stack_a[i])
			return (0);
	}
	while ((flag == 1) && (++i < size))
	{
		if (stack_a[i - 1] < stack_a[i])
			return (0);
	}
	return (1);
}
