/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:55:04 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/02 17:11:24 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stack;

//error
void	free_list(char **av, t_stack *stack, int control);

//utils
void	sort(t_stack *stack, int size);
int		sort_three(t_stack *s);

// RULES A
void	sa(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	pa(t_stack *stack);

// RULES B
void	sb(t_stack *stack);
void	rb(t_stack *stack);
void	rrb(t_stack *stack);
void	pb(t_stack *stack);

// RULES DOUBLE
void	rr(t_stack	*s, int print);
void	ss(t_stack	*s, int print);

int		quicksort_a(t_stack *stack, int len, int count);
int		quicksort_b(t_stack *stack, int len, int count);
int		divide(t_stack *stack, int len);

int		sort_small_a(t_stack *s);
int		sort_medium_a(t_stack *s, int len);
int		sort_small_b(t_stack *s, int len);

void	bubble_sort(int *tmp_stack, int size);
void	find_pivot(int *pivot, int *stack_a, int size);
int		is_sorted(int *stack_a, int size, int flag);
int		ft_push(t_stack *stack, int len, int flag);

//utils_funcs
int		ps_atoi(char *str, t_stack *stack, char **av, int control);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif