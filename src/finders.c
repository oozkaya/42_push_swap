/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 21:41:42 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/26 17:09:26 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_index(t_elem *elem, int nbr)
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

int		ft_find_max(t_elem *elem, int len)
{
	int		i;
	int		max;
	t_elem	*tmp;

	tmp = elem;
	max = tmp->nbr;
	i = 0;
	while (tmp && i < len)
	{
		if (max <= tmp->nbr)
			max = tmp->nbr;
		i++;
		tmp = tmp->next;
	}
	return (max);
}

int		ft_find_min(t_elem *elem, int len)
{
	int		i;
	int		min;
	t_elem	*tmp;

	tmp = elem;
	min = tmp->nbr;
	i = 0;
	while (tmp && i < len)
	{
		if (min >= tmp->nbr)
			min = tmp->nbr;
		i++;
		tmp = tmp->next;
	}
	return (min);
}

int		ft_find_next(t_elem *elem, int nbr, int max)
{
	int		next;
	t_elem	*tmp;

	next = max;
	tmp = elem;
	while (tmp)
	{
		if (tmp->nbr > nbr && tmp->nbr < next)
			next = tmp->nbr;
		tmp = tmp->next;
	}
	return (next);
}

int		find_best_rotate(t_elem *elem, int nbr, int len)
{
	int		r;
	int		rr;
	int		index;

	if ((index = ft_find_index(elem, nbr)) == -1)
		return (0);
	r = index;
	rr = len - index;
	return (r <= rr ? 1 : 2);
}
