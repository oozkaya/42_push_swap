/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:02:18 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/11 15:10:38 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(t_stack *stack, char *line)
{
	ft_memdel((void**)&line);
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static void	ft_reader_checker(t_stack **stack, const t_op *tab_op, char *line)
{
	int		i;
	int		done;

	i = 0;
	done = 0;
	while (tab_op[i].op)
	{
		if (ft_strequ(tab_op[i].op, line))
		{
			tab_op[i].arg(stack, line, 0);
			done = 1;
		}
		i++;
	}
	if (!done)
		ft_error(*stack, line);
}

static void	ft_open_close(int *fd, t_stack *stack, char *filename, int choice)
{
	if (choice == 1)
	{
		if ((*fd = open(filename, O_RDONLY)) == -1)
		{
			ft_putstr_fd("Error open()\n", 2);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	else if (choice == 2)
	{
		if (close(*fd) == -1)
		{
			ft_putstr_fd("Error close()\n", 2);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
}

int			ft_reader(t_stack **stack, int flags, const t_op *tab_op,
															char *filename)
{
	int		fd;
	int		moves;
	char	*line;
	t_sdl	*sdl;

	fd = 0;
	if (flags & FLAG_F)
		ft_open_close(&fd, *stack, filename, 1);
	if (flags & FLAG_V)
		ft_displayer_init(&sdl, *stack);
	moves = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_reader_checker(stack, tab_op, line);
		ft_flag_c(flags, line, &moves);
		if ((flags & FLAG_V) && !sdl->quit)
			ft_display(&sdl, *stack);
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	if (flags & FLAG_F)
		ft_open_close(&fd, *stack, filename, 2);
	if (flags & FLAG_V)
		ft_displayer_free(sdl);
	return (moves);
}
