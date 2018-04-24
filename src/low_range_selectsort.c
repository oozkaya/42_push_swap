/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_range_selectsort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:37:15 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/20 16:12:12 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_best_rotate_b(t_stack *stack, int max)
{
	int		i;
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
	return (2);
}

static void	handle_max_and_rotate(t_stack **stack, int max, int *check)
{
	if ((*stack)->b->nbr == find_next_max(*stack, max, *check))
	{
		push_arg(stack, "pa", 1);
		*check = 1;
	}
	else if (find_best_rotate_b(*stack, max) == 1)
		rotate_arg(stack, "rb", 1);
	else if (find_best_rotate_b(*stack, max) == 2)
		reverse_rotate_arg(stack, "rrb", 1);
}

void		low_range_selectsort(t_stack **stack, int size)
{
	int		i;
	int		max;
	int		check;

	i = 0;
	while ((*stack)->b && i++ < size)
	{
		if (ft_stacklen((*stack)->b) == 1)
		{
			push_arg(stack, "pa", 1);
			return ;
		}
		max = find_max(*stack, size);
		check = 0;
		while ((*stack)->b->nbr != max)
			handle_max_and_rotate(stack, max, &check);
		push_arg(stack, "pa", 1);
		if (check)
		{
			swap_arg(stack, "sa", 1);
			i++;
		}
	}
}
