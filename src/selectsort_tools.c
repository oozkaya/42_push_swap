/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectsort_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:59:41 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/20 16:13:03 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max(t_stack *stack, int size)
{
	int		i;
	int		max;
	t_elem	*tmp;

	tmp = stack->b;
	max = tmp->nbr;
	i = 0;
	while (tmp && i < size)
	{
		if (max <= tmp->nbr)
			max = tmp->nbr;
		i++;
		tmp = tmp->next;
	}
	return (max);
}

int		find_next_max(t_stack *stack, int max, int check)
{
	t_elem	*tmp;
	int		next;

	if (check == 1)
		return (max + 1);
	next = max - 1;
	while (1)
	{
		tmp = stack->b;
		while (tmp)
		{
			if (tmp->nbr == next)
				return (next);
			tmp = tmp->next;
		}
		next--;
	}
	return (next);
}
