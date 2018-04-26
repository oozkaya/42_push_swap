/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:49:15 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/26 17:17:36 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_arg(t_stack **stack, char *arg, int print)
{
	if (ft_strequ("sa", arg))
	{
		ft_swap_stack(&(*stack)->a);
		if (print == 1)
			add_buffer(&(*stack)->buf, "sa\n", 3);
	}
	else if (ft_strequ("sb", arg))
	{
		ft_swap_stack(&(*stack)->b);
		if (print == 1)
			add_buffer(&(*stack)->buf, "sb\n", 3);
	}
	else if (ft_strequ("ss", arg))
	{
		ft_swap_stack(&(*stack)->a);
		ft_swap_stack(&(*stack)->b);
		if (print == 1)
			add_buffer(&(*stack)->buf, "ss\n", 3);
	}
	refresh_index(&(*stack)->a);
	refresh_index(&(*stack)->b);
}

void	push_arg(t_stack **stack, char *arg, int print)
{
	int		popped_nbr;

	if (ft_strequ("pa", arg))
	{
		if ((*stack)->b == NULL)
			return ;
		popped_nbr = ft_pop_stack(&(*stack)->b);
		ft_push_stack(&(*stack)->a, popped_nbr);
		if (print == 1)
			add_buffer(&(*stack)->buf, "pa\n", 3);
	}
	else if (ft_strequ("pb", arg))
	{
		if ((*stack)->a == NULL)
			return ;
		popped_nbr = ft_pop_stack(&(*stack)->a);
		ft_push_stack(&(*stack)->b, popped_nbr);
		if (print == 1)
			add_buffer(&(*stack)->buf, "pb\n", 3);
	}
	refresh_index(&(*stack)->a);
	refresh_index(&(*stack)->b);
}

void	rotate_arg(t_stack **stack, char *arg, int print)
{
	if (ft_strequ("ra", arg))
	{
		ft_rotate_stack(&(*stack)->a);
		if (print == 1)
			add_buffer(&(*stack)->buf, "ra\n", 3);
	}
	else if (ft_strequ("rb", arg))
	{
		ft_rotate_stack(&(*stack)->b);
		if (print == 1)
			add_buffer(&(*stack)->buf, "rb\n", 3);
	}
	else if (ft_strequ("rr", arg))
	{
		ft_rotate_stack(&(*stack)->a);
		ft_rotate_stack(&(*stack)->b);
		if (print == 1)
			add_buffer(&(*stack)->buf, "rr\n", 3);
	}
	refresh_index(&(*stack)->a);
	refresh_index(&(*stack)->b);
}

void	reverse_rotate_arg(t_stack **stack, char *arg, int print)
{
	if (ft_strequ("rra", arg))
	{
		ft_reverse_rotate_stack(&(*stack)->a);
		if (print == 1)
			add_buffer(&(*stack)->buf, "rra\n", 4);
	}
	else if (ft_strequ("rrb", arg))
	{
		ft_reverse_rotate_stack(&(*stack)->b);
		if (print == 1)
			add_buffer(&(*stack)->buf, "rrb\n", 4);
	}
	else if (ft_strequ("rrr", arg))
	{
		ft_reverse_rotate_stack(&(*stack)->a);
		ft_reverse_rotate_stack(&(*stack)->b);
		if (print == 1)
			add_buffer(&(*stack)->buf, "rrr\n", 4);
	}
	refresh_index(&(*stack)->a);
	refresh_index(&(*stack)->b);
}
