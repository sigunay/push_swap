/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:54:52 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/02 17:05:01 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_is_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

static int	ps_atoi_check(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static void	digit_check(char *str, t_stack *stack, char **av, int control)
{
	int	i;
	int	j;

	j = 0;
	while (str[j] == '0' && str[j + 1] == '0')
		j++;
	i = 0;
	while (str[j])
	{
		i++;
		j++;
	}
	if (i > 11)
		free_list(av, stack, control);
}

int	ps_atoi(char *str, t_stack *stack, char **av, int control)
{
	unsigned int		i;
	int					sign;
	unsigned long		num;

	num = 0;
	sign = 1;
	i = ps_atoi_check(str, &sign);
	if (!(ft_is_num(str)))
		free_list(av, stack, control);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			free_list(av, stack, control);
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if (i > 11)
		digit_check(str, stack, av, control);
	if ((num > 2147483648 && sign == -1) || (num > 2147483647 && sign == 1))
		free_list(av, stack, control);
	return (num * sign);
}
