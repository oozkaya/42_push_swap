/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:13 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/19 11:49:33 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_str_isdigit(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
#include <stdio.h>

/*static void		my_sort(t_stack **stack)
{
	int		pivot;

	pivot = (*stack)->a->nbr;
	if ((*stack)->a->nbr > (stack)->a->next->nbr)
		swap_arg(stack, "sa", 1);
	
}*/

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

/*static void	ft_quicksort(t_stack **stack, int n)
{
	int		top_half_len;
	int		i;
	int		median;
//	t_elem	*tmp;

	if (n <= 1)
		return ;
	top_half_len = 0;
//	tmp = (*stack)->a;
//	while (tmp->next != NULL)
//		tmp = tmp->next;
	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
	printf("median = %d\n", median);
//	getchar();
	i = 1;
	while (i++ <= n) //for 0 to n {    //filter all values above the median into list 2
	{
		if ((*stack)->a->nbr > median)
		{
			push_arg(stack, "pb", 1);//push list 1 top to list 2 //list 2 stores the larger half
			top_half_len++;
		}
//		tmp->a = tmp->a->next;
		reverse_rotate_arg(stack, "rra", 1);//rotate list 1 forward
//		ft_putstr("test\n");
	}
    //reverse the list back to original position
	i = 1;
	while (i++ <= (n - top_half_len))
		rotate_arg(stack, "ra", 1);//rotate list 1 backward (n - top_half_len) times
//	getchar();

    //push larger half onto smaller half
//	ft_putstr("push larger hafl onto smaller half\n");
	i = 1;
	while (i++ <= top_half_len)
		push_arg(stack, "pa", 1);//push list 2 top to list 1 top_half_len times

	//recursively call this on the larger half
    ft_quicksort(stack, top_half_len);

    //rotate smaller half to front
	i = 1;
	while (i++ <= top_half_len)
		reverse_rotate_arg(stack, "rra", 1);//rotate list 1 forward top_half_len times

    //recursively call this on smaller half
//	printf("NNNNNNNN = %d", n);
    ft_quicksort(stack, n - top_half_len);

    //reverse list back to original position
	i = 1;
	while (i++ <= top_half_len)
		rotate_arg(stack, "ra", 1);//rotate list 1 backward top_half_len times
}*/

static void	ft_quicksort(t_stack **stack, int n, int x)
{
	int		top_half_len;
	int		i;
	int		median;
//	t_elem	*tmp;
///////	printf("n = %d with index = %d\n", n, x);
	if (n <= 1)
	{
//////		printf("1st return with index = %d\n", x);
		return ;
	}
	top_half_len = 0;
//	tmp = (*stack)->a;
//	while (tmp->next != NULL)
//		tmp = tmp->next;
	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
/////////	printf("median = %d with index = %d\n", median, x);
//	getchar();
	i = 1;
	while (i++ <= n) //for 0 to n {    //filter all values above the median into list 2
	{
		if ((*stack)->a->nbr < median)
		{
			push_arg(stack, "pb", 1);//push list 1 top to list 2 //list 2 stores the larger half
			top_half_len++;
		}
		else
			rotate_arg(stack, "ra", 1);//rotate list 1 forward
//		tmp->a = tmp->a->next;
//		ft_putstr("test\n");
	}
    //reverse the list back to original position
///////	printf("REVERSE TO PUT MEDIAN IN FRONT, index = %d\n", x);
	while ((*stack)->a->nbr != median)
		reverse_rotate_arg(stack, "rra", 1);
///////	printf("top_half_len = %d with index = %d\n", top_half_len, x);
//	if (top_half_len == 0)
//		return ;
/*	i = 1;
	while (i++ <= (n + 1 - top_half_len))
		reverse_rotate_arg(stack, "rra", 1);//rotate list 1 backward (n - top_half_len) times*/
//	getchar();

    //push larger half onto smaller half
//////	printf("PUSH TO A ALL THE SMALLER HALF, index = %d\n", x);
	i = 1;
	while (i++ <= top_half_len)
		push_arg(stack, "pa", 1);//push list 2 top to list 1 top_half_len times
///	getchar();
	//recursively call this on the larger half
/////	printf("RESTART QT ON THE SMALLER HALF, index = %d\n", x);
    ft_quicksort(stack, top_half_len, x + 1);
/////	printf("END OF QT SMALLER HALF, index = %d\n", x);

    //rotate smaller half to front
/////	printf("ROTATE BIGGER HALF TO FRONT, index = %d\n", x);
	i = 1;
	while (i++ <= top_half_len + 1)
		rotate_arg(stack, "ra", 1);//rotate list 1 forward top_half_len times

    //recursively call this on smaller half
//	printf("NNNNNNNN = %d", n);
///////	printf("START QT ON THE BIGGER HALF, index = %d\n", x);
    ft_quicksort(stack, n - (top_half_len + 1), x + 1);
/////////	printf("END OF QT BIGGER HALF, index = %d\n", x);
    //reverse list back to original position
	i = 1;
	while (i++ <= top_half_len + 1)
		reverse_rotate_arg(stack, "rra", 1);//rotate list 1 backward top_half_len times
}

static int		ft_stack_len(t_stack *stack)
{
	t_elem	*tmp;
	int		counter;

	counter = 0;
	tmp = stack->a;
	while (tmp)
	{
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}

static int		ft_tablen(char **tab)
{
	int		i;
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			main(int ac, char **av)
{
	t_stack	*stack;
//	t_elem	*tmp;
	int		stack_len;
	char	**tab;
	int		i;
//	ft_putstr("OK1\n");
	stack = ft_stack_initialize();
//	ft_putstr("OK3\n");
//	buffer_init(&stack->buf);
//	ft_putstr("index = ");
//	ft_putnbr(stack->buf->index);
//	ft_putchar('\n');
//	ft_putstr("OK\n");
	while (ac > 1)
	{
		tab = ft_strsplit(av[ac - 1], ' ');
		i = ft_tablen(tab) - 1;
		while (i >= 0)
		{
			if (!ft_str_isdigit(tab[i]))
			{
				ft_putstr("Error\n");
				exit (EXIT_FAILURE);
			}
			ft_push_stack(&stack->a, ft_atoi(tab[i]));
			ft_memdel((void**)&tab[i]);
			i--;
		}
		ft_memdel((void**)&tab);
		ac--;
	}
/*	tmp = stack->a;
	while (tmp->next)
		tmp = tmp->next;*/
//	ft_putstr("OK2\n");
	stack_len = ft_stack_len(stack);
//	printf("stack len = %d\n", stack_len);
//	getchar();
/*	ft_putstr("PILE A :\n");
	afficherPile(stack->a);
	ft_putstr("PILE B :\n");
	afficherPile(stack->b);*/
////	ft_selectsort(&stack);
	ft_quicksort(&stack, stack_len, 0);
/*	ft_putstr("PILE A :\n");
	afficherPile(stack->a);
	ft_putstr("PILE B :\n");
	afficherPile(stack->b);*/
	write(1, stack->buf->str, stack->buf->len);
	ft_putstr("A : ");
	afficherPile1(stack->a);
	ft_putchar('\n');
	free_all(stack);
//	while (1);
	/*	printf("\nEtat de la pile :\n");
	afficherPile(&maPile->a);

	ft_rotate_stacks(&maPile->a);
	printf("Apres le rotate :\n");
	afficherPile(&maPile->a);

	ft_reverse_rotate_stacks(&maPile->a);
	printf("Apres le rotate reverse :\n");
	afficherPile(&maPile->a);
	printf("Je depile %d\n", ft_pop_stack(&maPile->a));
	printf("Je depile %d\n", ft_pop_stack(&maPile->a));

	printf("\nEtat de la pile :\n");
	afficherPile(&maPile->a);

	ft_swap_stacks(&maPile->a);
	//printf("maPile first = %d", maPile->a->nbr);

	printf("\nApres le swap :\n");
	afficherPile(&maPile->a);*/

	return (0);
}