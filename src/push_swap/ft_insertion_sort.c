/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:58:18 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/03 17:19:14 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_moves2top(t_elem *elem, int nbr)
{
	int		r;
	int		rr;
	int		index;

	if ((index = ft_find_index(elem, nbr)) == -1)
		return (0);
	r = index;
	rr = ft_stacklen(elem) - index;
	return (r < rr ? r : rr);
}

static int	ft_moves2next(t_elem *elem, int nbr, int max)
{
	int		moves;
	int		next;

	next = ft_find_next(elem, nbr, max);
	moves = ft_moves2top(elem, next);
	return (moves);
}

static int	ft_find_bestmove(t_stack *stack, int max)
{
	int		count;
	int		bestval;
	int		bestmove;
	t_elem	*tmp;

	tmp = stack->b;
	bestval = tmp->nbr;
	bestmove = 0;
	while (tmp)
	{
		count = ft_moves2top(stack->b, tmp->nbr)
				+ 1
				+ ft_moves2next(stack->a, tmp->nbr, max);
		if ((count < bestmove) || !bestmove)
		{
			bestmove = count;
			bestval = tmp->nbr;
		}
		tmp = tmp->next;
	}
	return (bestval);
}

static void	handle_rotations(t_stack **stack, int next, int bestmove)
{
	int		len;

	len = ft_stacklen((*stack)->a);
	while ((*stack)->a->nbr != next)
	{
		if (find_best_rotate((*stack)->a, next, len) == 1)
			rotate_arg(stack, "ra", 1);
		else
			reverse_rotate_arg(stack, "rra", 1);
	}
	len = ft_stacklen((*stack)->b);
	while ((*stack)->b->nbr != bestmove)
	{
		if (find_best_rotate((*stack)->b, bestmove, len) == 1)
			rotate_arg(stack, "rb", 1);
		else
			reverse_rotate_arg(stack, "rrb", 1);
	}
	push_arg(stack, "pa", 1);
}

void		ft_insertion_sort(t_stack **stack, int size)
{
	int		len;
	int		min;
	int		max;
	int		next;
	int		bestmove;

	if (low_part_sort(stack, size))
		return ;
	ft_quicksort_a2b(stack, size);
	while ((*stack)->b)
	{
		max = ft_find_max((*stack)->a, ft_stacklen((*stack)->a));
		bestmove = ft_find_bestmove(*stack, max);
		next = ft_find_next((*stack)->a, bestmove, max);
		handle_rotations(stack, next, bestmove);
	}
	len = ft_stacklen((*stack)->a);
	min = ft_find_min((*stack)->a, len);
	while ((*stack)->a->nbr != min)
	{
		if (find_best_rotate((*stack)->a, min, len) == 1)
			rotate_arg(stack, "ra", 1);
		else
			reverse_rotate_arg(stack, "rra", 1);
	}
}
