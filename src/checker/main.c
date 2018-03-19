/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:23 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/12 13:04:42 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_str_isdigit(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_fill_stack(t_stack **stack, int ac, char **av)
{
	while (ac > 1)
	{
		if (!ft_str_isdigit(av[ac - 1]))
		{
			ft_putstr("Error\n");
			exit(EXIT_FAILURE);
		}
		ft_push_stack(&(*stack)->a, ft_atoi(av[ac - 1]));
		ac--;
	}
}

static void	ft_instruction_parser(t_stack **stack, const t_op *tab_op)
{
	char	*line;
	int		i;

	while (get_next_line(1, &line) > 0)
	{
		i = 0;
		while (tab_op[i].op)
		{
			if (ft_strequ(tab_op[i].op, line))
				tab_op[i].arg(stack, line, 0);
			i++;
		}
		free(line);
	}
}

int			main(int ac, char **av)
{
	static const t_op tab_op[] = { { "sa", swap_arg },
		{ "sb", swap_arg },
		{ "ss", swap_arg },
		{ "pa", push_arg },
		{ "pb", push_arg },
		{ "ra", rotate_arg },
		{ "rb", rotate_arg },
		{ "rr", rotate_arg },
		{ "rra", reverse_rotate_arg },
		{ "rrb", reverse_rotate_arg },
		{ "rrr", reverse_rotate_arg },
		{ NULL, NULL}
	};
	t_stack	*stack;

	stack = ft_stack_initialize();
	ft_fill_stack(&stack, ac, av);
	ft_putstr("PILE A :\n");
	afficherPile(stack->a);
	ft_putstr("PILE B :\n");
	afficherPile(stack->b);
	ft_instruction_parser(&stack, tab_op);
	ft_putstr("PILE A :\n");
	afficherPile(stack->a);
	ft_putstr("PILE B :\n");
	afficherPile(stack->b);
	return (0);
}


/*int			main(int ac, char **av)
{
	int		i;
	char	*line;


	i = 1;
	while (i <= ac && ft_str_isdigit(av[i]))
	{
		ft_putstr("chiffre = ");
		ft_putnbr(ft_atoi(av[i]));
		ft_putchar('\n');
		get_next_line(1, &line);
		ft_putstr("line = ");
		ft_putstr(line);
		ft_putchar('\n');
		i++;
	}
	return (0);
}*/
