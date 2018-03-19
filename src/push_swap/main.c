/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:13 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/19 17:07:38 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*static void	ft_selectsort(t_stack **stack)
{
	int		min;
	int		i;
	int		count;
	t_elem	*tmp;

	while ((*stack)->a)
	{
		i = 1;
		min = (*stack)->a->nbr;
		count = 0;
		tmp = (*stack)->a;
		while (tmp)
		{
			if (min >= tmp->nbr)
			{
				min = tmp->nbr;
				count = i;
			}
			i++;
			tmp = tmp->next;
		}
		i = 1;
		while (i++ < count)
			rotate_arg(stack, "ra", 1);
		push_arg(stack, "pb", 1);
	}
	while ((*stack)->b)
		push_arg(stack, "pa", 1);
}*/

static void	ft_quicksort(t_stack **stack, int n, int x)
{
	int		lower_half_len;
	int		i;
	int		median;
//	t_elem	*tmp;
	if (stack_is_sorted((*stack)->a) == 1)
		return ;
///////////	printf("n = %d with index = %d\n", n, x);
	if (n <= 1)
	{
//////////////////		printf("1st return with index = %d\n", x);
		return ;
	}
	lower_half_len = 0;
//	tmp = (*stack)->a;
//	while (tmp->next != NULL)
//		tmp = tmp->next;
	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
///////////////	printf("median = %d with index = %d\n", median, x);
//	getchar();
	i = 1;
	while (i++ <= n) //for 0 to n {    //filter all values above the median into list 2
	{
		if ((*stack)->a->nbr < median)
		{
			push_arg(stack, "pb", 1);//push list 1 top to list 2 //list 2 stores the larger half
			lower_half_len++;
		}
		else
			rotate_arg(stack, "ra", 1);//rotate list 1 forward
//		tmp->a = tmp->a->next;
//		ft_putstr("test\n");
	}
    //reverse the list back to original position
////////////////	printf("REVERSE TO PUT MEDIAN IN FRONT, index = %d\n", x);
	while ((*stack)->a->nbr != median)
		reverse_rotate_arg(stack, "rra", 1);
///////////////	printf("top_half_len = %d with index = %d\n", top_half_len, x);
//	if (top_half_len == 0)
//		return ;
/*	i = 1;
	while (i++ <= (n + 1 - top_half_len))
		reverse_rotate_arg(stack, "rra", 1);//rotate list 1 backward (n - top_half_len) times*/
//	getchar();

    //push larger half onto smaller half
//////////////	printf("PUSH TO A ALL THE SMALLER HALF, index = %d\n", x);
	i = 1;
	while (i++ <= lower_half_len)
		push_arg(stack, "pa", 1);//push list 2 top to list 1 top_half_len times
///	getchar();
	//recursively call this on the larger half
///////////////	printf("RESTART QT ON THE SMALLER HALF, index = %d\n", x);
    ft_quicksort(stack, lower_half_len, x + 1);
///////////////	printf("END OF QT SMALLER HALF, index = %d\n", x);

    //rotate smaller half to front
/////////////	printf("ROTATE BIGGER HALF TO FRONT, index = %d\n", x);
	i = 1;
	while (i++ <= lower_half_len + 1 && !stack_is_sorted((*stack)->a))
		rotate_arg(stack, "ra", 1);//rotate list 1 forward top_half_len times

    //recursively call this on smaller half
//	printf("NNNNNNNN = %d", n);
//////////////	printf("START QT ON THE BIGGER HALF, index = %d\n", x);
    ft_quicksort(stack, n - (lower_half_len + 1), x + 1);
/////////////	printf("END OF QT BIGGER HALF, index = %d\n", x);
    //reverse list back to original position
	i = 1;
	while (i++ <= lower_half_len + 1 && !stack_is_sorted((*stack)->a))
		reverse_rotate_arg(stack, "rra", 1);//rotate list 1 backward top_half_len times
}

int			main(int ac, char **av)
{
	t_stack	*stack;
	int		stack_len;

	stack = ft_stack_initialize();
	ft_fill_stack(&stack, ac, av);
	stack_len = ft_stacklen(stack);
	ft_quicksort(&stack, stack_len, 0);
	write(1, stack->buf->str, stack->buf->len);
//	ft_putstr("A : ");
//	afficherPile1(stack->a);
//	ft_putchar('\n');
	free_stack(stack);
	return (0);
}
