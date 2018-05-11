/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:23 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/11 15:34:13 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_instruction_parser(t_stack **stack, const t_op *tab_op,
												int *flags, char *filename)
{
	int		moves;

	if (ft_stacklen((*stack)->a) > 1000)
		*flags &= ~FLAG_V;
	if (!(*stack)->a)
	{
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	moves = ft_reader(stack, *flags, tab_op, filename);
	if (*flags & FLAG_C)
		ft_putchar('\n');
	if (stack_is_sorted((*stack)->a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	if (*flags & FLAG_L)
	{
		if (moves <= 1)
			ft_printf("%d move !\n", moves);
		else
			ft_printf("%d moves !\n", moves);
	}
}

int			main(int ac, char **av)
{
	static const t_op	tab_op[] = { { "sa", swap_arg },
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
	t_stack				*stack;
	int					flags;

	flags = NO_FLAG;
	stack = ft_stack_initialize();
	fill_stack(&stack, ac, av, ft_flag_checker(ac, av, &flags, stack));
	ft_instruction_parser(&stack, tab_op, &flags,
										ft_filename(ac, av, flags, stack));
	free_stack(stack);
	return (0);
}
