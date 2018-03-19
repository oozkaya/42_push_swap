/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:23 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/19 17:27:31 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_instruction_parser(t_stack **stack, const t_op *tab_op)
{
	char	*line;
	int		i;

	while (get_next_line(0, &line) > 0)
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
//	ft_putstr("PILE A :\n");
//	afficherPile(stack->a);
//	ft_putstr("PILE B :\n");
//	afficherPile(stack->b);
	ft_instruction_parser(&stack, tab_op);
	if (stack_is_sorted(stack->a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
//	ft_putstr("PILE A :\n");
//	afficherPile(stack->a);
//	ft_putstr("PILE B :\n");
//	afficherPile(stack->b);
	return (0);
}
