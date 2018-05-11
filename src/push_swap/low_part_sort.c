/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_part_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:30:42 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/11 15:01:03 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_beforelast_last(t_stack **stack, int *before, int *last)
{
	t_elem	*tmp;
	int		found;

	found = 0;
	tmp = (*stack)->a;
	while (tmp)
	{
		if (!found && tmp->next->next == NULL)
		{
			*before = tmp->nbr;
			found = 1;
		}
		if (tmp->next == NULL)
			*last = tmp->nbr;
		tmp = tmp->next;
	}
	tmp = (*stack)->a;
	while (tmp->nbr != *before)
	{
		if (tmp->nbr >= tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_swap_or_not(t_stack **stack)
{
	int		before;
	int		last;

	if ((*stack)->a->nbr > (*stack)->a->next->nbr)
	{
		swap_arg(stack, "sa", 0);
		if (stack_is_sorted((*stack)->a))
			add_buffer(&(*stack)->buf, "sa\n", 3);
		else
			swap_arg(stack, "sa", 0);
	}
	if (!ft_beforelast_last(stack, &before, &last))
		return ;
	if (before > last)
	{
		while ((*stack)->a->nbr != before)
			reverse_rotate_arg(stack, "rra", 1);
		swap_arg(stack, "sa", 1);
		rotate_arg(stack, "ra", 1);
		rotate_arg(stack, "ra", 1);
	}
}

static void	ft_sort_3(t_stack **stack, int size)
{
	int		min;
	int		max;

	min = ft_find_min((*stack)->a, size);
	max = ft_find_max((*stack)->a, size);
	if ((*stack)->a->next->nbr == max)
	{
		reverse_rotate_arg(stack, "rra", 1);
		if (!stack_is_sorted((*stack)->a))
			swap_arg(stack, "sa", 1);
	}
	else if ((*stack)->a->nbr == max)
	{
		if ((*stack)->a->next->nbr == min)
			rotate_arg(stack, "ra", 1);
		else
		{
			swap_arg(stack, "sa", 1);
			reverse_rotate_arg(stack, "rra", 1);
		}
	}
	else
		swap_arg(stack, "sa", 1);
}

static void	ft_sort_5(t_stack **stack)
{
	int		min;
	int		len;

	while ((len = ft_stacklen((*stack)->a)) > 2)
	{
		min = ft_find_min((*stack)->a, len);
		if ((*stack)->a->nbr == min)
			push_arg(stack, "pb", 1);
		if (find_best_rotate((*stack)->a, min, len) == 1)
			rotate_arg(stack, "ra", 1);
		else if (find_best_rotate((*stack)->a, min, len) == 2)
			reverse_rotate_arg(stack, "rra", 1);
	}
	if ((*stack)->a->nbr > (*stack)->a->next->nbr)
		swap_arg(stack, "sa", 1);
	while ((*stack)->b)
		push_arg(stack, "pa", 1);
}

int			low_part_sort(t_stack **stack, int size)
{
	if (size == 5)
	{
		ft_sort_5(stack);
		return (1);
	}
	if (size <= 3)
	{
		ft_sort_3(stack, size);
		return (1);
	}
	ft_swap_or_not(stack);
	if (size > 10)
		return (0);
	if (!stack_is_reverse_sorted((*stack)->a))
		return (0);
	while (ft_stacklen((*stack)->a) > 2)
	{
		reverse_rotate_arg(stack, "rra", 1);
		push_arg(stack, "pb", 1);
	}
	swap_arg(stack, "sa", 1);
	while ((*stack)->b)
		push_arg(stack, "pa", 1);
	return (1);
}
