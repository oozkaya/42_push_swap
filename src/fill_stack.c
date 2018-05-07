/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:48:09 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/07 17:10:35 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_int_max_min(char *str)
{
	intmax_t	nbr;

	if (ft_str_isdigit(str))
	{
		nbr = ft_atoi(str);
		if (nbr > INT_MAXI || nbr < INT_MINI)
			return (0);
	}
	return (1);
}

static void		ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static void		ft_check_duplicates(t_stack *stack)
{
	int		count;
	t_elem	*tmp;
	t_elem	*tmp2;

	tmp = stack->a;
	while (tmp)
	{
		tmp2 = stack->a;
		count = 0;
		while (tmp2)
		{
			if (tmp2->nbr == tmp->nbr)
				count++;
			if (count > 1)
			{
				free_stack(stack);
				ft_error();
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void			fill_stack(t_stack **stack, int ac, char **av, int start)
{
	char	**tab;
	int		i;

	while (ac > start)
	{
		tab = ft_strsplit(av[ac - 1], ' ');
		i = ft_tablen(tab) - 1;
		while (i >= 0)
		{
			if (!ft_str_isdigit(tab[i]) || !ft_int_max_min(tab[i]))
			{
				ft_memdel((void**)&tab[i]);
				ft_memdel((void**)&tab);
				free_stack(*stack);
				ft_error();
			}
			ft_push_stack(&(*stack)->a, ft_atoi(tab[i]));
			ft_memdel((void**)&tab[i]);
			i--;
		}
		ft_memdel((void**)&tab);
		ac--;
	}
	ft_check_duplicates(*stack);
	refresh_index(&(*stack)->a);
}
