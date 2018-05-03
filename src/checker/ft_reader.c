/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:02:18 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/03 19:50:38 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}*/

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
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
}

int			ft_reader(t_stack **stack, t_flags *flags, const t_op *tab_op)
{
	int		fd;
	int		moves;
	char	*line;
	t_sdl	*sdl;

	if (flags->v)
		ft_displayer_init(&sdl, *stack);
	fd = 0;
	if (flags->f)
		fd = open("file.txt", O_RDONLY);
	moves = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_reader_checker(stack, tab_op, line);
		if (flags->v && !sdl->quit)
			ft_display(&sdl, *stack);
		free(line);
		moves++;
	}
	if (flags->f)
		close(fd);
	if (flags->v)
		ft_displayer_free(sdl);
	return (moves);
}