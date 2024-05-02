/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:55:18 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/02 15:52:28 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sb(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	write(1, "sb\n", 3);
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->stack_b[0];
	while (i < stack->size_b)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[i - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->size_b - 1;
	tmp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[i] = tmp;
	write(1, "rrb\n", 4);
}

void	pb(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size_a)
	{
		stack->size_b++;
		i = stack->size_b;
		while (--i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
		}
		stack->stack_b[0] = stack->stack_a[0];
		i = -1;
		stack->size_a--;
		while (++i < stack->size_a)
			stack->stack_a[i] = stack->stack_a[i + 1];
	}
	write(1, "pb\n", 3);
}
