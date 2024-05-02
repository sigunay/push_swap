/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:54:45 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/02 15:03:44 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack, int size)
{
	if (size == 2)
		sa(stack);
	else if (size == 3)
		sort_three(stack);
	else
		divide(stack, size);
}

int	ft_push(t_stack *stack, int len, int flag)
{
	if (flag == 0)
		pb(stack);
	else
		pa(stack);
	len--;
	return (len);
}

int	sort_small_a(t_stack *s)
{
	if (s->stack_a[0] > s->stack_a[1])
	{
		if (s->stack_b[0] < s->stack_b[1])
			ss(s, 0);
		else
			sa(s);
	}
	return (1);
}

int	sort_medium_a(t_stack *s, int len)
{
	while (len != 3 || !(s->stack_a[0] < s->stack_a[1]
			&& s->stack_a[1] < s->stack_a[2]))
	{
		if (len == 3 && s->stack_a[0] > s->stack_a[1])
		{
			if ((s->stack_a[0] > s->stack_a[1])
				&& (s->stack_b[0] < s->stack_b[1]))
				ss(s, 0);
			else
				sa(s);
		}
		else if (len == 3 && !(s->stack_a[2] > s->stack_a[0]
				&& s->stack_a[2] > s->stack_a[1]))
			len = ft_push(s, len, 0);
		else if (s->stack_a[0] > s->stack_a[1])
			sa(s);
		else if (len++)
			pa(s);
	}
	return (1);
}

int	sort_small_b(t_stack *s, int len)
{
	if (len == 2)
	{
		if (s->stack_b[0] < s->stack_b[1])
			sb(s);
		pa(s);
		pa(s);
	}
	else if (len == 3)
	{
		while (len || !(s->stack_a[0] < s->stack_a[1]
				&& s->stack_a[1] < s->stack_a[2]))
		{
			if (len == 1 && s->stack_a[0] > s->stack_a[1])
				sa(s);
			else if (len == 1 || (len >= 2 && s->stack_b[0] > s->stack_b[1])
				|| (len == 3 && s->stack_b[0] > s->stack_b[2]))
				len = ft_push(s, len, 1);
			else
				sb(s);
		}
	}
	return (1);
}
