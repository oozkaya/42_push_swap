/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:23 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/26 20:21:25 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_instruction_parser(t_stack **stack, const t_op *tab_op,
									t_flags *flags)
{
	char	*line;
	int		i;
	int		fd;
	int		moves;

	fd = 0;
	if (flags->f)
		fd = open("file.txt", O_RDONLY);
	moves = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (tab_op[i].op)
		{
			if (ft_strequ(tab_op[i].op, line))
				tab_op[i].arg(stack, line, 0);
			i++;
		}
		free(line);
		moves++;
	}
	if (flags->l)
		ft_putnbr(moves);
	if (flags->f)
		close(fd);
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
	t_flags				flags;

	stack = ft_stack_initialize();
	fill_stack(&stack, ac, av, ft_flag_checker(ac, av, &flags));
	ft_instruction_parser(&stack, tab_op, &flags);
	if (stack_is_sorted(stack->a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	if (flags.v)
		ft_display();
	free_stack(stack);
	return (0);
}
