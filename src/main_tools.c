/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:28:21 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/11 15:00:53 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_is_sorted(t_elem *elem)
{
	t_elem	*tmp;

	tmp = elem;
	while (tmp->next)
	{
		if (tmp->nbr >= tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		stack_is_reverse_sorted(t_elem *elem)
{
	t_elem	*tmp;

	tmp = elem;
	while (tmp->next)
	{
		if (tmp->nbr <= tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_stacklen(t_elem *elem)
{
	t_elem	*tmp;
	int		counter;

	counter = 0;
	tmp = elem;
	while (tmp)
	{
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}

int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	refresh_index(t_elem **elem)
{
	int		index;
	t_elem	*tmp;

	index = 0;
	tmp = *elem;
	while (tmp)
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}
