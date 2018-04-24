/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_range_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 12:54:37 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/24 17:34:11 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	quicksort_intro(t_stack **stack, int size)
{
	if (!(*stack)->a || (stack_is_sorted((*stack)->a) && !(*stack)->b))
		return (1);
	if (size == 2)
	{
		push_arg(stack, "pb", 1);
		push_arg(stack, "pb", 1);
		return (1);
	}
	return (0);
}

static void	find_pivot2(t_stack **stack)
{
	int		median;

	if ((*stack)->b)
	{
		median = find_median(*stack, ft_stacklen((*stack)->b), 'b');
		if ((*stack)->b->nbr < median)
			rotate_arg(stack, "rb", 1);
	}
}

static int	median_limit_counter(t_stack *stack, int median, int size)
{
	int		i;
	t_elem	*tmp;
	int		count;

	tmp = stack->a;
	i = 1;
	count = 0;
	while (i <= size)
	{
		if (tmp->nbr < median)
			count = i;
		tmp = tmp->next;
		i++;
	}
	return (count);
}

void		low_range_quicksort(t_stack **stack, int size)
{
	int		lower_half_len;
	int		i;
	int		count;
	int		median;

	lower_half_len = 0;
	if (quicksort_intro(stack, size) == 1)
		return ;
	if ((*stack)->a)
		median = find_median(*stack, size, 'a');
	count = median_limit_counter(*stack, median, size);
	i = 0;
	while (i++ < count)
	{
		if ((*stack)->a->nbr < median)
		{
			find_pivot2(stack);
			push_arg(stack, "pb", 1);
			lower_half_len++;
		}
		else
			rotate_arg(stack, "ra", 1);
	}
	if ((*stack)->a)
		low_range_quicksort(stack, size - lower_half_len);
}
