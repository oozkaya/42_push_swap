/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:13 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/24 16:07:53 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include <stdio.h>

static int	find_next_int(t_stack *stack, int min, int size)//, int *check)
{
	t_elem	*tmp;
	int		next;
	int		i;

//	if (*check == 1)
//		return (min - 1);
	//ft_putstr("OK\n");
	next = min + 1;
	i = 0;
	while (i++ < size)
	{
		tmp = stack->a;
		//	ft_printf("tmp = %d\n", tmp->nbr);
		//	getchar();
		while (tmp)
		{
			if (tmp->nbr == next)
				return (next);
			tmp = tmp->next;
		}
		next++;
	}
	return (min);
}

static int	find_min(t_stack *stack, int size)
{
	int		i;
	int		min;
	t_elem	*tmp;

	tmp = stack->a;
	min = tmp->nbr;
	i = 0;
	while (tmp && i < size)
	{
		if (min >= tmp->nbr)
			min = tmp->nbr;
		i++;
		tmp = tmp->next;
	}
	return (min);
}
static int	find_best_rotate(t_stack *stack, int min)
{
	t_stack	*tmp;
	int		ra;
	int		rra;
	int		i;

	i = 0;
	tmp = stack;
	ra = 0;
	while (tmp->a->nbr != min && i++ != ft_stacklen(stack->a))
	{
		rotate_arg(&tmp, "ra", 0);
		ra++;
	}
	i = 0;
	while (i++ < ra)
		reverse_rotate_arg(&tmp, "rra", 0);
	i = 0;
	tmp = stack;
	rra = 0;
	while (tmp->a->nbr != min && i++ != ft_stacklen(stack->a))
	{
		reverse_rotate_arg(&tmp, "rra", 0);
		rra++;
	}
	i = 0;
	while (i++ < rra)
		rotate_arg(&tmp, "ra", 0);
	if (ra <= rra)
		return (1);
	return (2);
}

static void my_sort(t_stack **stack)
{
	int		i;
	int		min;
	int		count;
	int		ra;
	int		pa;

//	while ((*stack)->a)
//		push_arg(stack, "pb", 1);
//	push_arg(stack, "pa", 1);
//	push_arg(stack, "pa", 1);
	while ((*stack)->b)
	{
		min = find_min(*stack, ft_stacklen((*stack)->a));
		//ft_putstr("OK\n");
		int next = find_next_int(*stack, (*stack)->b->nbr, ft_stacklen((*stack)->b));
//		ft_printf("next = %d\n", next);
		//getchar();
		count = 0;
		if ((*stack)->b->nbr == next)
		{
			while ((*stack)->a->nbr != min)
			{
				rotate_arg(stack, "ra", 1);
				ra++;
				count++;
			}
			push_arg(stack, "pa", 1);
			pa++;
			count++;
		}
		else
		{
			i = 0;
			while ((*stack)->a->nbr != next)
			{
				rotate_arg(stack, "ra", 1);
				ra++;
				count++;
			}
			push_arg(stack, "pa", 1);
			pa++;
			count++;
		}
//		ft_printf("count = %d\n", count);
		//else
			//rotate_arg(stack, "rb", 1);
		/*else if (find_best_rotate(*stack, find_next_int(*stack, (*stack)->b->nbr, 0)) == 1)
			rotate_arg(stack, "ra", 1);
		else
			reverse_rotate_arg(stack, "rra", 1);*/
	}
	min = find_min(*stack, ft_stacklen((*stack)->a));
	while ((*stack)->a->nbr != min)
		rotate_arg(stack, "ra", 1);
}

static void	my_sort2(t_stack **stack)
{
	while ((*stack)->b)
	{

	}
}

static void	ft_quicksort_for_b(t_stack **stack, int n)
{
	int		lower_half_len;
	int		i;
	int		j;
	int		k;
	int		l;
	int		median;
	int		rb;
//	int		tab[n];
	t_elem	*tmp;
//	if (stack_is_sorted((*stack)->a) == 1 || stack_is_sorted2((*stack)->a, n) == 1)
//		return i;
	if (n == 1)
	{
///		ft_putstr("first pa\n");
		push_arg(stack, "pa", 1);
		return ;
	}
///	ft_printf("n de b = %d\n", n);
	if (!(*stack)->b)
		return ;
	if (n <= 10)
	{
///		ft_putstr("select sorted\n");
		return (high_range_selectsort(stack, n));
	}
//	ft_bzero(tab, n);
	lower_half_len = 0;
	median = find_median(*stack, n, 'b');//	
///	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
///	ft_printf("median de b = %d\n", median);
	tmp = (*stack)->b;
	i = 0;
	j = 1;
	l = 0;
	while (j <= n)
	{
		if (tmp->nbr > median)
		{
			//tab[i] = tmp->nbr;
			//i++;
			l = j;
		}
		tmp = tmp->next;
		j++;
	}
	i = 0;
//	k = 0;
//	ft_putstr("OK\n");
	rb = 0;
	while (i < n) //////while (i < l)//for 0 to n {    //filter all values above the median into list 2
	{
/*		if (n == 1)
		{
			if ((*stack)->b->nbr < (*stack)->b->next->nbr)
			{
				swap_arg(stack, "sb", 1);
				push_arg(stack, "pa", 1);
			}
			else
				push_arg(stack, "pa", 1);
			getchar();
			return ; 
		}*/

/*		if (n == 2)
		{
			push_arg(stack, "pa", 1);
			push_arg(stack, "pa", 1);
			lower_half_len = 2;
			break ; 
		}*/
		if ((*stack)->b->nbr > median)//////if ((*stack)->a->nbr == tab[k])
		{
			push_arg(stack, "pa", 1);//push list 1 top to list 2 //list 2 stores the larger half

			lower_half_len++;
///			ft_printf("loweereeer in while of B = %d\n", lower_half_len);
			//k++;
		}
		else
		{
			rotate_arg(stack, "rb", 1);//rotate list 1 forward
			rb++;
		}
		i++;
	/////////////	if (stack_is_sorted((*stack)->a) && !(*stack)->b)
	///////////		return ;
//	ft_printf("tab[%d] = %d\n", k , tab[k]);
	}
	////getchar();
/*	while (rb--)
	{
		reverse_rotate_arg(stack, "rrb", 1);
	}*/
///	ft_putstr("Rotate for median\n");
	int	rrb = 0;
	while ((*stack)->b->nbr != median)
	{
		reverse_rotate_arg(stack, "rrb", 1);
		rrb++;
	}
///	ft_printf("LHL of B = %d\n", lower_half_len);
	i = 0;
	while (i++ < lower_half_len)
		push_arg(stack, "pb", 1);
///	ft_printf("DEBUT QT B1\n");
	ft_quicksort_for_b(stack, lower_half_len);
///	ft_printf("FIN QT B1\n");
///	ft_putstr("push the median\n");
	push_arg(stack, "pa", 1);
	i = 0;
	while (rrb + i++ < rb)
		reverse_rotate_arg(stack, "rrb", 1);
	//getchar();
/*	ft_putstr("Put in front (B)\n");
	i = 1;
	while (i++ <= lower_half_len) //&& !stack_is_sorted((*stack)->a))
		rotate_arg(stack, "rb", 1);*/
///	ft_printf("DEBUT QT B2\n");
	ft_quicksort_for_b(stack, n - (lower_half_len + 1));
///	ft_printf("FIN QT B2\n");
	//getchar();
/*	ft_putstr("Reverse put (B)\n");
	i = 1;
	while (i++ <= lower_half_len) //&& !stack_is_sorted((*stack)->a))
		reverse_rotate_arg(stack, "rrb", 1);*/
	//getchar();
}

static void	ft_quicksort_tab2(t_stack **stack, int n, int x)
{
	int		lower_half_len;
	int		i;
	int		j;
	int		k;
	int		l;
	int		median;
//	int		tab[n];
	t_elem	*tmp;
//	if (stack_is_sorted((*stack)->a) == 1 || stack_is_sorted2((*stack)->a, n) == 1)
//		return ;
	lower_half_len = 0;
///	ft_printf("n de a = %d with index = %d\n", n, x );
	if (n == 1)
	{
		push_arg(stack, "pb", 1);
		lower_half_len = 1;
	}
//	if (n < 1)
//		return ;
//	if (!(*stack)->a)
//		return ;
//	ft_bzero(tab, n);
///	median = 0;
	if ((*stack)->a)
		median = find_median(*stack, n, 'a');//	
//	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
///	ft_printf("median de a = %d\n", median);
/*	tmp = (*stack)->a;
	i = 0;
	j = 1;
	l = 0;
	while (j <= n)
	{
		if (tmp->nbr < median)
		{
			tab[i] = tmp->nbr;
			i++;
			l = j;
		}
		tmp = tmp->next;
		j++;
	}*/
	i = 0;
//	k = 0;
//	ft_putstr("OK\n");
	int median2 = 0;
	while (i < n && n != 1 && (*stack)->a) //////while (i <= l)//for 0 to n {    //filter all values above the median into list 2
	{
/*		if (n == 2)
		{
			push_arg(stack, "pb", 1);
			push_arg(stack, "pb", 1);
			lower_half_len = 2;
			break ; 
		}*/
		if ((*stack)->a->nbr < median)//////if ((*stack)->a->nbr == tab[k])
		{
			/*if (x == 0 && (*stack)->b)
			{
				median2 = find_pivot(*stack, ft_stacklen((*stack)->b), 'b');
				//ft_printf("median2 = %d\n", median2);
				if ((*stack)->b->nbr < median2)
					rotate_arg(stack, "rb", 1);
			}*/
			push_arg(stack, "pb", 1);//push list 1 top to list 2 //list 2 stores the larger half
//			if	( ft_stacklen((*stack)->b) >= 2 && (*stack)->b->nbr < (*stack)->b->next->nbr)
//				swap_arg(stack, "sb", 1);
			lower_half_len++;
		//	ft_putstr("OK\n");
			//k++;
		}
		else //if (find_best_rotate(*stack, median) == 1)
			rotate_arg(stack, "ra", 1);//rotate list 1 forward
	//	else if (find_best_rotate(*stack, min) == 2)
	//		reverse_rotate_arg(stack, "rra", 1);
		i++;
	/////////////	if (stack_is_sorted((*stack)->a) && !(*stack)->b)
	///////////		return ;
//	ft_printf("tab[%d] = %d\n", k , tab[k]);
	}

///	ft_printf("resut -> lhl =%d with index = %d\n", lower_half_len, x);
//	ft_putstr("OK\n");
	if ((*stack)->a)
    	ft_quicksort_tab2(stack, ft_stacklen((*stack)->a), x + 1);
//	ft_putstr("OK2\n");
//	while (lower_half_len--)
//		push_arg(stack, "pa", 1);
///	ft_printf("n 2eme de a = %d\n", n);
///	ft_printf("lhl = %d et n - lhl = %d\n", lower_half_len, n - lower_half_len);
/*	ft_putstr("DEBUT QT FOR B1\n");
	ft_quicksort_for_b(stack, n - lower_half_len);
	ft_putstr("FIN QT FOR B1\n");
	ft_putstr("DEBUT QT FOR B2\n");
	ft_quicksort_for_b(stack, lower_half_len);
	ft_putstr("FIN AT FOR B2\n");*/
	ft_quicksort_for_b(stack, lower_half_len);
}

int			main(int ac, char **av)
{
	t_stack	*stack;
	t_flags	flags;
	int		stack_len;
	int		start;
	int		fd;

	stack = ft_stack_initialize();
	start = ft_flag_checker(ac, av, &flags);
	ft_fill_stack(&stack, ac, av, start);
	stack_len = ft_stacklen(stack->a);
	insertion_sort(&stack);
///	stack->a_is_empty = 0;
/*	ft_putstr("A : ");
	afficherPile1(stack->a);
	ft_putchar('\n');*/
//	ft_printf("best = %d\n", find_best_rotate(stack, 1));
//	ft_quicksort(&stack, stack_len, 0);
//	ft_quicksort_tab(&stack, stack_len, 0);
	///if (stack_len <= 10)
	///	ft_selectsort3(&stack, stack_len);
/*	if (stack_len >= 300)
	{
		low_range_quicksort(&stack, stack_len);
		push_arg(&stack, "pa", 1);
		my_sort(&stack);
		//my_sort(&stack);
		//ft_quicksort_tab2(&stack, stack_len, 0);
	}*/
//	else if (stack_len >= 150)
//	{
//		ft_quicksort_tab3(&stack, stack_len, 0);
//		ft_quicksort_tab3_for_b(&stack, stack_len, 0);
//		ft_quicksort_tab3(&stack, stack_len, 0);
//		new_selectsort3(&stack, stack_len);
//	}
/*	else
	{
		low_range_quicksort(&stack, stack_len);
		low_range_selectsort(&stack, stack_len);
	}*/
///////	ft_quicksort_tab3(&stack, stack_len, 0);
//	ft_insertsort(&stack, stack_len);
//	ft_selectsort(&stack, stack_len);
//	ft_selectsort2(&stack, stack_len);
//	ft_selectsort3(&stack, stack_len);
//	find_pivot(stack, 4);
	if (flags.f)
	{
		fd = open("file.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR | S_IRUSR);
		write(fd, stack->buf->str, stack->buf->len);
		close(fd);
	}
	else
		write(1, stack->buf->str, stack->buf->len);
//	push_arg(&stack, "pb", 1);
/*	ft_putstr("A : ");
	afficherPile1(stack->a);
	ft_putchar('\n');
	ft_putstr("B : ");
	afficherPile1(stack->b);
	ft_putchar('\n');*/
//	ft_printf("flags->v = %d\n", flags.v);
//ft_printf("flags->f = %d\n", flags.f);
//	ft_printf("test = %s %sred%s\n", "TEST", RED, EOC);
	free_stack(stack);
	return (0);
}
