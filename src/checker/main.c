/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:23 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/01 22:07:56 by oozkaya          ###   ########.fr       */
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
	t_sdl	*sdl;
	int		run;
//	int		max;
	//int		len;

	ft_displayer_init(&sdl, *stack);
//	sdl->len = ft_stacklen((*stack)->a);
	sdl->max = ft_find_max((*stack)->a, sdl->len);
	sdl->min = ft_find_min((*stack)->a, sdl->len);
//	ft_printf("max = %d\n", sdl->max);
//	ft_printf("min = %d\n", sdl->min);
//	sdl->height = HEIGHT / sdl->len;
	//ft_printf("heiiiight1 = %d\n", sdl->height);
//	sdl->height = sdl->height * sdl->len;
	//ft_printf("heiiiight2 = %d\n", sdl->height);
	//getchar();
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
		if (flags->v)
			ft_display(&sdl, *stack);
		free(line);
		moves++;
	}
	if (flags->l)
		ft_putnbr(moves);
	if (flags->v)
	{
		run = 1;
		while (run)
		{
			while (SDL_PollEvent(&sdl->ev) != 0)
				if (sdl->ev.type == SDL_QUIT)
					run = 0;
			SDL_UpdateWindowSurface(sdl->win);
		}
		SDL_Quit();
	}
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
	//if (flags.v)
	//	ft_display();
	free_stack(stack);
	return (0);
}
