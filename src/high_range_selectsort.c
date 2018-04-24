/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_range_selectsort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:56:42 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/20 16:16:38 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void handle_max_and_rotate2(t_stack **stack, int max,
										int *check, int *rb)
{
	while ((*stack)->b->nbr != max)
	{
		if ((*stack)->b->nbr == find_next_max(*stack, max, *check))
		{
			*check = 1;
			push_arg(stack, "pa", 1);
		}
		else
		{
			rotate_arg(stack, "rb", 1);
			(*rb)++;
		}
	}
	push_arg(stack, "pa", 1);
}

void	high_range_selectsort(t_stack **stack, int size)
{
	int		i;
	int		max;
	int		rb;
	int		check;

	i = 0;
	while (i++ < size)
	{
		if (ft_stacklen((*stack)->b) == 1)
		{
			push_arg(stack, "pa", 1);
			return ;
		}
		max = find_max(*stack, size);
		rb = 0;
		check = 0;
		handle_max_and_rotate2(stack, max, &check, &rb);
		if (check)
		{
			swap_arg(stack, "sa", 1);
			i++;
		}
		while (rb--)
			reverse_rotate_arg(stack, "rrb", 1);
	}
}