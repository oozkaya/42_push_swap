/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:05:22 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/26 17:18:59 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_push_stack(t_elem **elem, int new_nbr)
{
	t_elem	*new;

	if (!(new = malloc(sizeof(*new))))
		return ;
	new->nbr = new_nbr;
	new->next = *elem;
	*elem = new;
}

int		ft_pop_stack(t_elem **elem)
{
	int		popped_nbr;
	t_elem	*popped_elem;

	popped_elem = *elem;
	popped_nbr = 0;
	if (elem != NULL)
	{
		popped_nbr = popped_elem->nbr;
		*elem = popped_elem->next;
		ft_memdel((void**)&popped_elem);
	}
	return (popped_nbr);
}

void	ft_swap_stack(t_elem **elem)
{
	t_elem	*to_swap;
	t_elem	*third;

	if (*elem == NULL || (*elem)->next == NULL)
		return ;
	to_swap = *elem;
	*elem = (*elem)->next;
	third = (*elem)->next;
	(*elem)->next = to_swap;
	to_swap->next = third;
}

void	ft_rotate_stack(t_elem **elem)
{
	t_elem	*to_rotate;
	t_elem	*tmp;

	if (*elem == NULL || (*elem)->next == NULL)
		return ;
	to_rotate = *elem;
	tmp = *elem;
	*elem = (*elem)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_rotate;
	to_rotate->next = NULL;
}

void	ft_reverse_rotate_stack(t_elem **elem)
{
	t_elem	*to_rotate;
	t_elem	*tmp;
	t_elem	*before_last;

	if (*elem == NULL || (*elem)->next == NULL)
		return ;
	tmp = *elem;
	while (tmp->next)
	{
		if (tmp->next->next == NULL)
			before_last = tmp;
		tmp = tmp->next;
	}
	to_rotate = tmp;
	to_rotate->next = *elem;
	*elem = to_rotate;
	before_last->next = NULL;
}
