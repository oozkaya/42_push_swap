/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:52:43 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/26 18:07:24 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_integer_table(int *tab, int size)
{
	int		i;
	int		j;
	int		x;

	j = 0;
	while (j <= size - 1)
	{
		i = 0;
		while (i <= size - 1)
		{
			x = tab[i];
			if (tab[i] > tab[i + 1] && i + 1 < size)
			{
				tab[i] = tab[i + 1];
				tab[i + 1] = x;
				i++;
			}
			else
				i++;
		}
		j++;
	}
}

static void	ft_bubblesort(t_stack *stack, int *tab, int size, char c)
{
	int		i;
	t_elem	*tmp;

	if (c == 'b')
		tmp = stack->b;
	else
		tmp = stack->a;
	i = 0;
	while (tmp && i < size)
	{
		tab[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	ft_sort_integer_table(tab, size);
}

int			find_median(t_stack *stack, int size, char c)
{
	int		tab[size];
	int		median;

	ft_bubblesort(stack, tab, size, c);
	median = tab[size / 2];
	return (median);
}
