/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:58:18 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/24 17:44:23 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	calculator(t_stack **stack)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = (*stack)->b;
	while (i < ft_stacklen((*stack)->b))
	{

		i++;
	}
}*/
#include <stdio.h>

static int	ft_find_index(t_elem *elem, int nbr)
{
	t_elem	*tmp;

	tmp = elem;
	while (tmp)
	{
		if (tmp->nbr == nbr)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

static int	ft_find_max(t_elem *elem)
{
	int		i;
	int		max;
	t_elem	*tmp;

	tmp = elem;
	max = tmp->nbr;
	i = 0;
	while (tmp && i < ft_stacklen(elem))
	{
		if (max <= tmp->nbr)
			max = tmp->nbr;
		i++;
		tmp = tmp->next;
	}
	return (max);
}
static int	ft_find_min(t_elem *elem)
{
	int		i;
	int		min;
	t_elem	*tmp;

	tmp = elem;
	min = tmp->nbr;
	i = 0;
	while (tmp && i < ft_stacklen(elem))
	{
		if (min >= tmp->nbr)
			min = tmp->nbr;
		i++;
		tmp = tmp->next;
	}
	return (min);
}
static int	ft_moves2top(t_elem *elem, int nbr)
{
	int		r;
	int		rr;


	if (ft_find_index(elem, nbr) == -1)
		return (0);
	r = ft_find_index(elem, nbr);
	rr = ft_stacklen(elem) - ft_find_index(elem, nbr);
	//ft_printf("r = %det rr = %d\n", r ,rr);
	return (r < rr ? r : rr);
}


static int	ft_find_next(t_elem *elem, int nbr, int size)
{
//	int		i;
	int		max;
	int		next;
	t_elem	*tmp;

	next = nbr + 1;
//	i = 0;
//	ft_printf("size = %d\n", size);
	max = ft_find_max(elem);
	while (next != max && nbr < max)
	{
	//	ft_printf("i = %d\n", i);
		tmp = elem;
		while (tmp)
		{
		//ft_printf("nbr = %d et tmp->nbr = %d et next = %d\n", nbr, tmp->nbr, next);
		//getchar();
		//ft_putstr("OKKKKKK\n");
		//ft_printf("len = %d\n", ft_stacklen(tmp));
			if (tmp->nbr == next)
				return (next);
			tmp = tmp->next;
		}
		next++;
		//i++;
	}
	if (next == max)
	{
		//ft_putstr("found!!\n");
		return (next);
	}
	return (nbr);
}

static int	ft_moves2next(t_elem *elem, int nbr)
{
	int		moves;
	int		next;

	next = ft_find_next(elem, nbr, ft_stacklen(elem));
	/*if (nbr == next)
	{
		ft_printf("already the max nbr (%d)\n", nbr);
		next = ft_find_min(elem);
	}*/
	moves = ft_moves2top(elem, next);
	return (moves);
}

static int			ft_find_bestmove(t_stack *stack)
{
	int		bestval;
	int		bestmove;
	int		count;
	t_elem	*tmp;

//	if (!*w)
//		return (0);
	tmp = stack->b;
	bestval = tmp->nbr;
	bestmove = 0;
	//ft_putstr("OK2\n");
	while (tmp)
	{
		count = ft_moves2top(stack->b, tmp->nbr) + 1 + ft_moves2next(stack->a, tmp->nbr);
		//ft_printf("count = %d\n", count);
		if ((count < bestmove) || !bestmove)
		{
			//ft_putstr("OK3\n");
			bestmove = count;
			bestval = tmp->nbr;
		}
		tmp = tmp->next;
		//ft_putstr("OK5\n");
	}
	//ft_putstr("OK4\n");
	return (bestval);
}
static int	find_best_rotate(t_elem *elem, int nbr)
{
	/*int		i;
	int		rb;
	t_stack	*tmp;

	i = 0;
	rb = 0;
	tmp = stack;
	while (tmp->b->nbr != max && i++ != ft_stacklen(stack->b))
	{
		rotate_arg(&tmp, "rb", 0);
		rb++;
	}
	i = 0;
	while (i++ < rb)
		reverse_rotate_arg(&tmp, "rrb", 0);
	if (rb <= ft_stacklen(stack->b) / 2)
		return (1);
	return (2);*/
	int		r;
	int		rr;


	if (ft_find_index(elem, nbr) == -1)
		return (0);
	r = ft_find_index(elem, nbr);
	rr = ft_stacklen(elem) - ft_find_index(elem, nbr);
	//ft_printf("nbr = %d et r = %det rr = %d\n", nbr, r ,rr);
	return (r <= rr ? 1 : 2);
}

static int	find_best_rotate_a(t_stack *stack, int max)
{
	int		i;
	int		ra;
	t_stack	*tmp;

	i = 0;
	ra = 0;
	tmp = stack;
	while (tmp->a->nbr != max && i++ != ft_stacklen(stack->a))
	{
		rotate_arg(&tmp, "ra", 0);
		ra++;
	}
	i = 0;
	while (i++ < ra)
		reverse_rotate_arg(&tmp, "rra", 0);
	if (ra <= ft_stacklen(stack->a) / 2)
		return (1);
	return (2);
}
void	insertion_sort(t_stack **stack)
{
	int		bestmove;
	int		next;

/*	while ((*stack)->a)
		push_arg(stack, "pb", 1);*/
	low_range_quicksort(stack, ft_stacklen((*stack)->a));
	push_arg(stack, "pa", 1);
	push_arg(stack, "pa", 1);
	while ((*stack)->b)
	{
		//ft_putstr("OK\n");
		/*if ((bestmove = ft_find_bestmove(*stack)) == ft_find_max((*stack)->b))
			next = ft_find_min((*stack)->a);
		else*/
		bestmove = ft_find_bestmove(*stack);
		next = ft_find_next((*stack)->a, bestmove, ft_stacklen((*stack)->a));
		//ft_printf("next in A of bestmove (%d) = %d\n", bestmove, next);
		int done = 0;
		while (!done)
		{
			//getchar();
			if ((*stack)->a->nbr == next)
				done = 1;
			else if (find_best_rotate((*stack)->a, next) == 1)
				rotate_arg(stack, "ra", 1);
			else
				reverse_rotate_arg(stack, "rra", 1);
		}
		done = 0;
		while (!done)
		{
			if ((*stack)->b->nbr == bestmove)
			{
				push_arg(stack, "pa", 1);
				done = 1;
			}
			else if (find_best_rotate((*stack)->b, bestmove) == 1)
				rotate_arg(stack, "rb", 1);
			else
				reverse_rotate_arg(stack, "rrb", 1);
		}
	/*	while ((*stack)->a->r && (*stack)->b->r)
		{

		}*/
	}
	int min = ft_find_min((*stack)->a);
	while ((*stack)->a->nbr != min)
	{
		if (find_best_rotate((*stack)->a, min) == 1)
			rotate_arg(stack, "ra", 1);
		else
			reverse_rotate_arg(stack, "rra", 1);
	}
	//rotate_arg(stack, "ra", 1);
}