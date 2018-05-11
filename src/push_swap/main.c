/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:13 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/11 15:02:19 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	file_handler(int ac, char **av, int flags, t_stack *stack)
{
	int		fd;

	fd = open(ft_filename(ac, av, flags, stack),
							O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR | S_IRUSR);
	if (fd == -1)
	{
		ft_putstr_fd("Error open()\n", 2);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	write(fd, stack->buf->str, stack->buf->len);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error close()\n", 2);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

int			main(int ac, char **av)
{
	t_stack	*stack;
	int		flags;
	int		stack_len;
	int		start;

	flags = NO_FLAG;
	stack = ft_stack_initialize();
	start = ft_flag_checker(ac, av, &flags, stack);
	fill_stack(&stack, ac, av, start);
	stack_len = ft_stacklen(stack->a);
	if (!stack_is_sorted(stack->a))
		ft_insertion_sort(&stack, stack_len);
	if (flags & FLAG_F)
		file_handler(ac, av, flags, stack);
	else
		write(1, stack->buf->str, stack->buf->len);
	free_stack(stack);
	return (0);
}
