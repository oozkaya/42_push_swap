/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:28:21 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/19 16:57:02 by oozkaya          ###   ########.fr       */
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

int		ft_stacklen(t_stack *stack)
{
	t_elem	*tmp;
	int		counter;

	counter = 0;
	tmp = stack->a;
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

void	ft_fill_stack(t_stack **stack, int ac, char **av)
{
	char	**tab;
	int		i;

	while (ac > 1)
	{
		tab = ft_strsplit(av[ac - 1], ' ');
		i = ft_tablen(tab) - 1;
		while (i >= 0)
		{
			if (!ft_str_isdigit(tab[i]))
			{
				ft_putstr("Error\n");
				ft_memdel((void**)&tab[i]);
				ft_memdel((void**)&tab);
				free_stack(*stack);
				exit(EXIT_FAILURE);
			}
			ft_push_stack(&(*stack)->a, ft_atoi(tab[i]));
			ft_memdel((void**)&tab[i]);
			i--;
		}
		ft_memdel((void**)&tab);
		ac--;
	}
}