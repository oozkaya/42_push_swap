/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:13 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/07 21:03:04 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stack	*stack;
	int		flags;
	int		stack_len;
	int		start;
	int		fd;

	flags = NO_FLAG;
	stack = ft_stack_initialize();
	start = ft_flag_checker(ac, av, &flags, stack);
	fill_stack(&stack, ac, av, start);
	stack_len = ft_stacklen(stack->a);
	if (!stack_is_sorted(stack->a))
		ft_insertion_sort(&stack, stack_len);
	if (flags & FLAG_F)
	{
		fd = open(ft_filename(ac, av, flags, stack), 
					O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR | S_IRUSR);
		write(fd, stack->buf->str, stack->buf->len);
		close(fd);
	}
	else
		write(1, stack->buf->str, stack->buf->len);
	free_stack(stack);
	return (0);
}
