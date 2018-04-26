/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:13 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/26 13:49:55 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stack	*stack;
	t_flags	flags;
	int		stack_len;
	int		start;
	int		fd;

	stack = ft_stack_initialize();
	start = ft_flag_checker(ac, av, &flags);
	fill_stack(&stack, ac, av, start);
	stack_len = ft_stacklen(stack->a);
	ft_quicksort_a2b(&stack, stack_len);
	ft_insertion_sort(&stack);
	if (flags.f)
	{
		fd = open("file.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR | S_IRUSR);
		write(fd, stack->buf->str, stack->buf->len);
		close(fd);
	}
	else
		write(1, stack->buf->str, stack->buf->len);
	free_stack(stack);
	return (0);
}
