/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:33:50 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/19 16:35:11 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_stack_initialize(void)
{
	t_stack	*stack;

	if (!(stack = malloc(sizeof(*stack))))
		return (NULL);
	buffer_init(&stack->buf);
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}

static void	free_elem(t_elem *elem)
{
	t_elem	*curr;

	while ((curr = elem) != NULL)
	{
		elem = elem->next;
		ft_memdel((void**)&curr);
	}
	elem = NULL;
}

void	free_stack(t_stack *stack)
{
	free_elem(stack->a);
	free_elem(stack->b);
	ft_memdel((void**)&stack->buf->str);
	ft_memdel((void**)&stack->buf);
	ft_memdel((void**)&stack);
}
