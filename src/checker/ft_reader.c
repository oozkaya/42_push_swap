/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:02:18 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/07 21:13:55 by oozkaya          ###   ########.fr       */
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

//static int	ft_flag_c(char *line)

int			ft_reader(t_stack **stack, int flags, const t_op *tab_op,
															char *filename)
{
	int		fd;
	int		moves;
	char	*line;
	t_sdl	*sdl;

	if (flags & FLAG_V)
		ft_displayer_init(&sdl, *stack);
	fd = 0;
	if (flags & FLAG_F)
		fd = open(filename, O_RDONLY);
	moves = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_reader_checker(stack, tab_op, line);
		if ((flags & FLAG_V) && !sdl->quit)
			ft_display(&sdl, *stack);
		ft_memdel((void**)&line);
		moves++;
	}
	ft_memdel((void**)&line);
	if (flags & FLAG_F)
		close(fd);
	if (flags & FLAG_V)
		ft_displayer_free(sdl);
	return (moves);
}
