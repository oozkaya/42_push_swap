/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:12:13 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/19 20:48:53 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void bottom_up_mergesort(t_stack **stack)
{
	int		n;
	int 	i;

	n = 2;
	i = 0;
	while (i++ < n)
	{
		
	}
}

static void ft_insertsort(t_stack **stack, int n)
{
	int		i;
	int		j;

	i = 1;
	while (i < n)
	{
		j = i;
		while (j > 0)
		{
			if ((*stack)->a->nbr > (*stack)->a->next->nbr)
				swap_arg(stack, "sa", 1);
			rotate_arg(stack, "ra", 1);
			j--;
		}
		i++;
	}
}

static int	find_next_int(t_stack *stack, int min, int *check)
{
	t_elem	*tmp;
	int		next;

	if (*check == 1)
		return (min - 1);
	next = min + 1;
	while (1)
	{
		tmp = stack->a;
		while (tmp)
		{
			if (tmp->nbr == next)
				return (next);
			tmp = tmp->next;
		}
		next++;
	}
	return (next);
}

static int	find_next_int2(t_stack *stack, int max, int *check)
{
	t_elem	*tmp;
	int		next;

	if (*check == 1)
		return (max + 1);
	next = max - 1;
	while (1)
	{
		tmp = stack->b;
	//	ft_putstr("test\n");
		while (tmp)
		{
			if (tmp->nbr == next)
				return (next);
	//		ft_printf("tmp->nbr = %d et next = %d\n", tmp->nbr, next);
	//		getchar();
			tmp = tmp->next;
		}
		next--;
	}
	return (next);
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
//	ft_printf("tmp->a->nbr = %d, min = %d\n", tmp->a->nbr, min);
	while (tmp->a->nbr != min && i++ != ft_stacklen(stack->a))
	{
		rotate_arg(&tmp, "ra", 0);
		ra++;
	}
	i = 0;
	while (i++ < ra)
		reverse_rotate_arg(&tmp, "rra", 0);
//	ft_printf("ra = %d\n", ra);
	i = 0;
	tmp = stack;
	rra = 0;
//	ft_printf("2eme) tmp->a->nbr = %d, min = %d\n", tmp->a->nbr, min);
	while (tmp->a->nbr != min && i++ != ft_stacklen(stack->a))
	{
		reverse_rotate_arg(&tmp, "rra", 0);
		rra++;
	}
	i = 0;
	while (i++ < rra)
		rotate_arg(&tmp, "ra", 0);
//	ft_printf("rra = %d\n", rra);
	if (ra <= rra)
		return (1);
	return (2);
}

static void ft_selectsort2(t_stack **stack, int n)
{
	int		min;
//	int		i;
	int		j;
	int		ra;
	int		pushed;
	t_elem	*tmp;

	pushed = 0;
	while (n - pushed != 0)
	{
		ft_printf("n = %d, pushed = %d, n - pushed = %d\n", n , pushed, n - pushed);
		//i = 1;
		ra = 0;
		while (n - pushed - ra != 0)//while (i <= n - pushed)
		{
			ft_printf("n = %d, pushed = %d, ra = %d, n - pushed - ra = %d\n", n , pushed, ra, n - pushed - ra);
			min = (*stack)->a->nbr;
			tmp = (*stack)->a;
			j = 1;
			while (n - pushed - ra != 0 && tmp)//while (j++ <= n - pushed && tmp)
			{
				//ft_printf("tmp->nbr = %d\n", tmp->nbr);
				if (min >= tmp->nbr)
					min = tmp->nbr;
				tmp = tmp->next;
			}
			ft_putstr("OK\n");
			if ((*stack)->a->nbr == min)
			{
				push_arg(stack, "pb", 1);
				pushed++;
				//i++;
			}
			while ((*stack)->a->nbr != min)
			{
				rotate_arg(stack, "ra", 1);
				ra++;
				ft_printf("ra = %d\n", ra);
				//i++;
			}
			push_arg(stack, "pb", 1);
			pushed++;
			//i++;
		}
		ft_putstr("OK1\n");
		while (ra--)
			reverse_rotate_arg(stack, "rra", 1);
		ft_putstr("OK2\n");
	}
	ft_putstr("OK3\n");
	while ((*stack)->b)
		push_arg(stack, "pa", 1);
}

static void	ft_selectsort(t_stack **stack, int n)
{
	int		min;
	int		i;
	int		j;
//	int		i;
//	int		count;
	t_elem	*tmp;
////	int		rotate;
//	i = 1;
	while (!stack_is_sorted((*stack)->a) || !(*stack)->b)
	{
		//ft_putstr("start\n");
//		ft_printf("i = %d for n = %d\n", i, n);
		//i = 1;
		if ((*stack)->a->nbr > (*stack)->a->next->nbr)
			swap_arg(stack, "sa", 1);
///		if (n > 2 && stack_is_sorted2((*stack)->a, n - 2))
///			reverse_rotate_arg(stack, "rra", 1);
//		if (stack_is_sorted((*stack)->a) && !(*stack)->b)
//			return ;
		//ft_putstr("okokok\n");
		min = (*stack)->a->nbr;
		//count = 0;
		tmp = (*stack)->a;
		j = 1;
		while (tmp && j <= n)
		{
			if (min >= tmp->nbr)
		//	{
				min = tmp->nbr;
			//	count = i;
//			}
//			i++;
			j++;
			tmp = tmp->next;
		}
		//ft_putstr("kkkkk\n");
		//ft_putstr("OK\n");
		//i = 1;
////		rotate = find_best_rotate((*stack), min);
		int check = 0;
		//int	done = 0;
//		ft_printf("min = %d\n", min);
		while ((*stack)->a->nbr != min)//while (i++ < count)
		{
			//ft_putstr("OK2\n");
	//		ft_printf("next_min = %d\n", find_next_int(*stack, min));
//			else
//			{
			/*if ((*stack)->a->nbr > (*stack)->a->next->nbr)
			{
				swap_arg(stack, "sa", 1);
				//done = 1;
			}*/
			if ((*stack)->a->nbr == find_next_int(*stack, min, &check))
			{
				//ft_putstr("OK3\n");
				check = 1;
				push_arg(stack, "pb", 1);
			//	ft_putstr("first pb\n");
			}
			else if (find_best_rotate(*stack, min) == 1)
			//if ((*stack)->a->nbr > (*stack)->a->next->nbr)
			//	swap_arg(stack, "sa", 1);
			//else
			//if (!done)
////			if (rotate == 1)
			//else
				rotate_arg(stack, "ra", 1);
			else if (find_best_rotate(*stack, min) == 2)
				reverse_rotate_arg(stack, "rra", 1);
////			else
////				reverse_rotate_arg(stack, "rra", 1);
				//ft_putstr(" ra done\n");
//			}
		//	if (stack_is_sorted((*stack)->a))
		//		break ;
		}
		//if (!stack_is_sorted((*stack)->a))
//		if ((*stack)->a->nbr > (*stack)->a->next->nbr)
//			swap_arg(stack, "sa", 1);
		//ft_putstr("OK4\n");
	//	if (!stack_is_sorted((*stack)->a))
		push_arg(stack, "pb", 1);
		/*ft_putstr("2nd pb\n");
		if ((*stack)->a->nbr > (*stack)->a->next->nbr)
			swap_arg(stack, "sa", 1);*/
		if (check)
			swap_arg(stack, "sb", 1);
		//ft_putstr("end\n");
	}
	//ft_putstr("OK5\n");
	while ((*stack)->b)
		push_arg(stack, "pa", 1);
}

static void ft_selectsort3(t_stack **stack, int n)
{
	int		block;
	int		min;
	int		i;
	int		j;
	int		ra;
	t_elem	*tmp;

	block = n * 1;
	while ((*stack)->a)
	{
		j = 0;
		while (j < block && (*stack)->a)
		{
			min = (*stack)->a->nbr;
			tmp = (*stack)->a;
			i = 1;
			while (tmp && i <= block - j)
			{
				if (min >= tmp->nbr)
					min = tmp->nbr;
				i++;
				tmp = tmp->next;
			}
			ra = 0;
			while ((*stack)->a->nbr != min)
			{
				rotate_arg(stack, "ra", 1);
				ra++;
			}
			push_arg(stack, "pb", 1);
			while (ra--)
				reverse_rotate_arg(stack, "rra", 1);
			j++;
		}
	}
	while ((*stack)->b)
	{
		min = (*stack)->b->nbr;
		tmp = (*stack)->b;
		i = 1;
		while (tmp && i <= n)
		{
			if (min <= tmp->nbr)
				min = tmp->nbr;
			i++;
			tmp = tmp->next;
		}
		while ((*stack)->b->nbr != min)
			rotate_arg(stack, "rb", 1);
		push_arg(stack, "pa", 1);
	}
}
#include <stdio.h>
void	ft_sort_integer_table(int *tab, int size)
{
	int		i;
	int		x;
	int		j;
	int		test;

	j = 0;
	while (j <= size - 1)
	{
		i = 0;
		while (i <= size - 1)
		{
		/*	ft_printf("sortttt-> tab[%d] = %d et tab[%d] = %d\n", i , tab[i], i + 1, tab[i + 1]);
			test = 0;
			while (test <= size - 1)
			{
				ft_printf("tab[%d] = %d, ", test, tab[test]);
				ft_putchar('\n');
				test++;
			}
			getchar();*/
			x = tab[i];
			if (tab[i] > tab[i + 1] && i + 1 < size)
			{
				tab[i] = tab[i + 1];
				tab[i + 1] = x;
				i++;
			}
			else
				i++;
		}
		j++;
	}
}
static void ft_bubblesort(t_stack *stack, int *tab, int n, char c)
{
	t_elem	*tmp;
	int		i;

//	ft_putstr("OK1\n");
	if (c == 'b')
		tmp = stack->b;
	else
		tmp = stack->a;
	i = 0;
	while (tmp && i < n)
	{
		tab[i] = tmp->nbr;
//		ft_printf("tab[%d] = %d\n", i, tab[i]);
		tmp = tmp->next;
		i++;
	}
//	ft_putstr("OK\n");
/*	i = 0;
	while (i < n)
	{
		ft_printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}*/
	ft_sort_integer_table(tab, n);
/*	i = 0;
	while (i < n)
	{
		ft_printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}*/
//	ft_printf("tab[0] = %d et tab[1] = %d et tab[2] = %d\n", tab[0], tab[1], tab[2]);
}

static int find_pivot(t_stack *stack, int n, char c)
{
	t_elem	*tmp;
//	int		i;
	int		tab[n];
	int		pivot;
//	tab = malloc(sizeof(int) * n);
	
		tmp = stack->a;
/*	i = 0;
	while (i < n)
	{

	}*/
	ft_bubblesort(stack, tab, n, c);
/*	i = 0;
	while (i < n)
	{
		ft_printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}*/
	pivot = tab[n / 2];
//	ft_printf("pivot = %d, n / 2 = %d\n", tab[n / 2], n / 2);
	return (pivot);
	//ft_printf("pivot = %d\n", pivot);
//	ft_printf("tab[0] = %d et tab[1] = %d et tab[2] = %d\n", tab[0], tab[1], tab[2]);
//	ft_memdel((void**)&tab);
}

static void	ft_quicksort(t_stack **stack, int n, int x)
{
	int		lower_half_len;
	int		i;
//////	int		j;
//////	int		k;
//////	int		l;
	int		median;
	//int		test;
//////	int		tab[n + 1];
//////	t_elem	*tmp;
//////	ft_bzero(tab, n);
	if (stack_is_sorted((*stack)->a) == 1 || stack_is_sorted2((*stack)->a, n) == 1)
		return ;
///	printf("n = %d with index = %d\n", n, x);
	if (n <= 1)
	{
///		printf("1st return with index = %d\n", x);
		return ;
	}
	lower_half_len = 0;
//	tmp = (*stack)->a;
//	while (tmp->next != NULL)
//		tmp = tmp->next;
//	median = find_pivot(*stack, n);//	
	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
///	printf("median = %d with index = %d\n", median, x);
//	getchar();
//////	tmp = (*stack)->a;
////// i = 0;
//////	j = 0;
//	ft_printf("first tmp = %d\n", tmp->nbr);
//while (tmp)
//	{
//		if (tmp->nbr < median)
//		{
//			tab[i] = tmp->nbr;
//			ft_printf("tmp->nbr = %d, tab[%d] = %d\n", tmp->nbr, i, tab[i]);
//			i++;
//			l = j;
//		}
//		tmp = tmp->next;
//		j++;
//	}
//	ft_printf("j = %d\n", j);
	i = 1;///// i = 0;
//////	k = 0;
//	ft_printf("first stack = %d\n", (*stack)->a->nbr);
	//int test = 0;
	while (i++ <= n) //////while (i <= l)//for 0 to n {    //filter all values above the median into list 2
	{
//		ft_printf("a->nbr = %d,  k tab[%d] = %d\n", (*stack)->a->nbr, k, tab[k]);
		if ((*stack)->a->nbr < median)//////if ((*stack)->a->nbr == tab[k])
		{
			push_arg(stack, "pb", 1);//push list 1 top to list 2 //list 2 stores the larger half
			lower_half_len++;
//////			k++;
		}
		else
		{
			rotate_arg(stack, "ra", 1);//rotate list 1 forward
//			if (!(*stack)->b)
//				rotate_arg(stack, "ra", 1);//rotate list 1 forward
		//	test++;
		}
//////		i++;
//		tmp->a = tmp->a->next;
//		ft_putstr("test\n");
	}
	//getchar();
    //reverse the list back to original position
///	printf("REVERSE TO PUT MEDIAN IN FRONT, index = %d\n", x);
	//i = 1;
	//while (i++ <= test)//
	while ((*stack)->a->nbr != median)
		reverse_rotate_arg(stack, "rra", 1);
//	push_arg(stack, "pb", 1);
///	printf("lower_half_len = %d with index = %d\n", lower_half_len, x);
//	if (top_half_len == 0)
//		return ;
//	i = 1;
//	while (i++ <= (n + 1 - top_half_len))
//		reverse_rotate_arg(stack, "rra", 1);//rotate list 1 backward (n - top_half_len) times
//	getchar();

    //push larger half onto smaller half
///	printf("PUSH TO A ALL THE SMALLER HALF, index = %d\n", x);
	i = 1;
	while (i++ <= lower_half_len)
		push_arg(stack, "pa", 1);//push list 2 top to list 1 top_half_len times
///	getchar();
	//recursively call this on the larger half
///	printf("RESTART QT ON THE SMALLER HALF, index = %d\n", x);
	ft_quicksort(stack, lower_half_len, x + 1);
///	printf("END OF QT SMALLER HALF, index = %d\n", x);

    //rotate smaller half to front
///	printf("ROTATE BIGGER HALF TO FRONT, index = %d\n", x);
	i = 1;
	while (i++ <= lower_half_len + 1 && !stack_is_sorted((*stack)->a))
		rotate_arg(stack, "ra", 1);//rotate list 1 forward top_half_len times

    //recursively call this on smaller half
//	printf("NNNNNNNN = %d", n);
///	printf("START QT ON THE BIGGER HALF, index = %d\n", x);
    ft_quicksort(stack, n - (lower_half_len + 1), x + 1);
///	printf("END OF QT BIGGER HALF, index = %d\n", x);
    //reverse list back to original position
	i = 1;
	while (i++ <= lower_half_len + 1 && !stack_is_sorted((*stack)->a))
		reverse_rotate_arg(stack, "rra", 1);//rotate list 1 backward top_half_len times
}
static int	stack_max(t_stack *stack, int n)
{
	t_elem	*tmp;
	int		max;
	int		i;

	tmp = stack->a;
	max = tmp->nbr;
	i = 0;
	while (tmp && i++ < n)
	{
		if (max <= tmp->nbr)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}
static void	ft_quicksort_tab(t_stack **stack, int n, int x)
{
	int		lower_half_len;
	int		i;
	int		j;
	int		k;
	int		l;
	int		median;
	int		tab[n];
	t_elem	*tmp;
	if (stack_is_sorted((*stack)->a) == 1 || stack_is_sorted2((*stack)->a, n) == 1)
		return ;
///	printf("n = %d with index = %d\n", n, x);
/////////////	if (n <= 1)
////////////	{
///		printf("1st return with index = %d\n", x);
////////////		return ;
////////////	}
//	if (n <= 101)
//		return (ft_selectsort(stack, n));
	ft_bzero(tab, n);
	lower_half_len = 0;
//	tmp = (*stack)->a;
//	while (tmp->next != NULL)
//		tmp = tmp->next;
//	median = find_pivot(*stack, n);//	
//	if ((*stack)->a->nbr == stack_max(*stack, n))
//		rotate_arg(stack, "ra", 1);
	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
//	printf("median = %d with index = %d\n", median, x);
//	getchar();

	tmp = (*stack)->a;
	i = 0;
	j = 1;
	l = 0;
//	ft_printf("j = %d\n", j);
	while (j <= n)
	{
		if (tmp->nbr < median)
		{
			tab[i] = tmp->nbr;
////			ft_printf("tmp->nbr = %d, tab[%d] = %d\n", tmp->nbr, i, tab[i]);
			i++;
			l = j;
		}
		tmp = tmp->next;
		j++;
	}
///		ft_putstr("OK\n");
///	ft_printf("j2 = %d\n", j);
	i = 0;///// i = 0;
	k = 0;
//	ft_printf("first stack = %d\n", (*stack)->a->nbr);
///	ft_printf("l = %d\n", l);
	while (i <= l && l != 0) //////while (i <= l)//for 0 to n {    //filter all values above the median into list 2
	{
///		getchar();
///		ft_printf("a->nbr = %d,  k tab[%d] = %d\n", (*stack)->a->nbr, k, tab[k]);
		if ((*stack)->a->nbr == tab[k])//////if ((*stack)->a->nbr == tab[k])
		{
			push_arg(stack, "pb", 1);//push list 1 top to list 2 //list 2 stores the larger half
		/*	ft_printf("b->nbr = %d\n", (*stack)->b->nbr);
			if ((*stack)->b->next)
				ft_printf("b->next->nbr = %d\n", (*stack)->b->next->nbr);
			else if ((*stack)->b->next == NULL)
				ft_printf("b is NULL\n");*/
			if ((*stack)->b->next && (*stack)->b->nbr < (*stack)->b->next->nbr)
				swap_arg(stack, "sb", 1);
			lower_half_len++;
			k++;
		}
		else
			rotate_arg(stack, "ra", 1);//rotate list 1 forward
		i++;
//		tmp->a = tmp->a->next;
//		ft_putstr("test\n");
		if (stack_is_sorted((*stack)->a) && !(*stack)->b)
			return ;
	}
	//getchar();
    //reverse the list back to original position
////	printf("REVERSE TO PUT MEDIAN IN FRONT, index = %d\n", x);
	while ((*stack)->a->nbr != median)
		reverse_rotate_arg(stack, "rra", 1);
////	printf("lower_half_len = %d with index = %d\n", lower_half_len, x);
//	if (top_half_len == 0)
//		return ;
//	i = 1;
//	while (i++ <= (n + 1 - top_half_len))
//		reverse_rotate_arg(stack, "rra", 1);//rotate list 1 backward (n - top_half_len) times
//	getchar();

    //push larger half onto smaller half
////	printf("PUSH TO A ALL THE SMALLER HALF, index = %d\n", x);
	i = 1;
	while (i++ <= lower_half_len)
	{
		push_arg(stack, "pa", 1);//push list 2 top to list 1 top_half_len times
		if ((*stack)->a->nbr > (*stack)->a->next->nbr)
			swap_arg(stack, "sa", 1);
	}
//	getchar();
	//recursively call this on the larger half
////	ft_printf("lower_half_len = %d\n", lower_half_len);
////	printf("RESTART QT ON THE SMALLER HALF, index = %d\n", x);
    ft_quicksort_tab(stack, lower_half_len, x + 1);
////	printf("END OF QT SMALLER HALF, index = %d\n", x);

    //rotate smaller half to front
////	printf("ROTATE BIGGER HALF TO FRONT, index = %d\n", x);
	i = 1;
	while (i++ <= lower_half_len + 1 && !stack_is_sorted((*stack)->a))
		rotate_arg(stack, "ra", 1);//rotate list 1 forward top_half_len times

    //recursively call this on smaller half
//	printf("NNNNNNNN = %d", n);
////	printf("START QT ON THE BIGGER HALF, index = %d\n", x);
    ft_quicksort_tab(stack, n - (lower_half_len + 1), x + 1);
////	printf("END OF QT BIGGER HALF, index = %d\n", x);
    //reverse list back to original position
	i = 1;
	while (i++ <= lower_half_len + 1 && !stack_is_sorted((*stack)->a))
		reverse_rotate_arg(stack, "rra", 1);//rotate list 1 backward top_half_len times
}

static int	find_best_rotate2(t_stack *stack, int max)
{
	t_stack	*tmp;
	int		rb;
	int		rrb;
	int		i;

	i = 0;
	tmp = stack;
	rb = 0;
//	ft_printf("tmp->a->nbr = %d, min = %d\n", tmp->a->nbr, min);
	while (tmp->b->nbr != max && i++ != ft_stacklen(stack->b))
	{
		rotate_arg(&tmp, "rb", 0);
		rb++;
	}
	i = 0;
	while (i++ < rb)
		reverse_rotate_arg(&tmp, "rrb", 0);
//	ft_printf("ra = %d\n", ra);
	i = 0;
	tmp = stack;
	rrb = 0;
//	ft_printf("2eme) tmp->a->nbr = %d, min = %d\n", tmp->a->nbr, min);
	while (tmp->b->nbr != max && i++ != ft_stacklen(stack->b))
	{
		reverse_rotate_arg(&tmp, "rrb", 0);
		rrb++;
	}
	i = 0;
	while (i++ < rrb)
		rotate_arg(&tmp, "rb", 0);
//	ft_printf("rra = %d\n", rra);
	if (rb <= rrb)
		return (1);
	return (2);
}

static void new_selectsort3(t_stack **stack, int n)
{
	int		i;
	int		j;
	int		max;
	t_elem	*tmp;
	int		rb;
	int		rrb;
	int		check;
	int		pa;

//	if (stack_is_sorted((*stack)->a) && !(*stack)->b)
//		return ;
	i = 0;
/*	if (stack_is_sorted2((*stack)->b, n))
	{
		ft_putstr("OK\n");
		while (i++ < n && (*stack)->b)
			push_arg(stack, "pa", 1);
	}*/
	pa = 0;
	j = 0;
	//ft_putstr("done2\n");
	while (j++ < n)
	{
//		ft_putstr("OK\n");
///		ft_putstr("start of loop\n");
///		ft_printf("n = %d\n", n);
		if (ft_stacklen((*stack)->b) == 1)
		{
			push_arg(stack, "pa", 1);
			return ;
		}
		tmp = (*stack)->b;
		max = tmp->nbr;
		//ft_printf("tmp->nbr = %d\n", tmp->nbr);
		i = 0;
		while (tmp && i < n)
		{
			if (max <= tmp->nbr)
				max = tmp->nbr;
			i++;
			tmp = tmp->next;
		}
		rrb = 0;
		rb = 0;
		check = 0;
	//	int check2 = 0;
	//	check2 = find_next_int2(*stack, max, &check) - 1;
///		ft_printf("max = %d\n", max);
		while ((*stack)->b->nbr != max)
		{
				//ft_printf("next next = %d\n", find_next_int2(*stack, find_next_int2(*stack, max, &check), &check2));
			/*if ((*stack)->b->nbr == find_next_int2(*stack, find_next_int2(*stack, max, &check), &check2))
			{
				check2 = 1;
				//push_arg(stack, "pa", 1);
			}*/
				//ft_printf("next = %d\n", find_next_int2(*stack, max, &check));
			if ((*stack)->b->nbr == find_next_int2(*stack, max, &check))
			{
				check = 1;
			//	ft_putstr("done\n");
///				ft_putstr("next int detected\n");
				push_arg(stack, "pa", 1);
				//pa++;
			}
			else if (find_best_rotate2(*stack, max) == 1)
			{
///				ft_putstr("1st rb\n");
				rotate_arg(stack, "rb", 1);
				//rb++;
			}
			else if (find_best_rotate2(*stack, max) == 2)
			{
				reverse_rotate_arg(stack, "rrb", 1);
				//rrb++;
			}
		}
//		ft_putstr("2nd pa\n");
///		ft_printf("max = %d\n", max);
///		ft_printf("n = %d, pa = %d\n", n, pa);
	//	if (pa != n)
	//	{
		//ft_putstr("done2\n");
			push_arg(stack, "pa", 1);
			//pa++;
	//``	}
//		ft_printf("check = %d\n", check);
		if (check)
		{
///			ft_putstr("sa for next int\n");
			swap_arg(stack, "sa", 1);
			j++;
		}
//		ft_printf("J = %d AND n = %d\n", j, n);
	}
///	ft_putstr("end of selectsort\n");
}
static void new_selectsort2(t_stack **stack, int n)
{
	int		i;
	int		j;
	int		max;
	t_elem	*tmp;
	int		rb;
	int		rrb;
	int		check;
	int		pa;

	i = 0;
/*	if (stack_is_sorted2((*stack)->b, n))
	{
		ft_putstr("OK\n");
		while (i++ < n && (*stack)->b)
			push_arg(stack, "pa", 1);
	}*/
	pa = 0;
	j = 0;
	//ft_putstr("done2\n");
	while (j++ < n)
	{
//		ft_putstr("OK\n");
///		ft_putstr("start of loop\n");
///		ft_printf("n = %d\n", n);
		if (ft_stacklen((*stack)->b) == 1)
		{
			push_arg(stack, "pa", 1);
			return ;
		}
		tmp = (*stack)->b;
		max = tmp->nbr;
		//ft_printf("tmp->nbr = %d\n", tmp->nbr);
		i = 0;
		while (tmp && i < n)
		{
			if (max <= tmp->nbr)
				max = tmp->nbr;
			i++;
			tmp = tmp->next;
		}
		rrb = 0;
		rb = 0;
		check = 0;
	//	int check2 = 0;
	//	check2 = find_next_int2(*stack, max, &check) - 1;
///		ft_printf("max = %d\n", max);
		while ((*stack)->b->nbr != max)
		{
				//ft_printf("next next = %d\n", find_next_int2(*stack, find_next_int2(*stack, max, &check), &check2));
			/*if ((*stack)->b->nbr == find_next_int2(*stack, find_next_int2(*stack, max, &check), &check2))
			{
				check2 = 1;
				//push_arg(stack, "pa", 1);
			}*/
				//ft_printf("next = %d\n", find_next_int2(*stack, max, &check));
			if ((*stack)->b->nbr == find_next_int2(*stack, max, &check))
			{
				check = 1;
			//	ft_putstr("done\n");
///				ft_putstr("next int detected\n");
				push_arg(stack, "pa", 1);
				//pa++;
			}
			else //if (find_best_rotate2(*stack, max) == 1)
			{
///				ft_putstr("1st rb\n");
				rotate_arg(stack, "rb", 1);
				rb++;
			}
			/*else if (find_best_rotate2(*stack, max) == 2)
			{
				reverse_rotate_arg(stack, "rrb", 1);
				rrb++;
			}*/
		}
//		ft_putstr("2nd pa\n");
///		ft_printf("max = %d\n", max);
///		ft_printf("n = %d, pa = %d\n", n, pa);
	//	if (pa != n)
	//	{
		//ft_putstr("done2\n");
			push_arg(stack, "pa", 1);
			//pa++;
	//``	}
//		ft_printf("check = %d\n", check);
		if (check)
		{
///			ft_putstr("sa for next int\n");
			swap_arg(stack, "sa", 1);
			j++;
		}
//		ft_printf("J = %d AND n = %d\n", j, n);
		if (j == n)
			break ;
		//ft_printf("b nbr before %d\n", (*stack)->b->nbr);
		int z = -1;
		while (z++ < rb)
			reverse_rotate_arg(stack, "rrb", 0);
		tmp = (*stack)->b;
		max = tmp->nbr;
		i = 0;
		while (tmp && i < n)
		{
			if (max <= tmp->nbr)
				max = tmp->nbr;
			i++;
			tmp = tmp->next;
		}
		while (z--)
			rotate_arg(stack, "rb", 0);
		//ft_printf("b nbr after %d\n", (*stack)->b->nbr);
//		ft_printf("rb = %d\n", rb);
		i = 0;
		check = 0;
		int rrb = 0;
		while ((*stack)->b->nbr != max && i < rb)
		{
			/*if ((*stack)->b->nbr == check2)
			{
				//ft_putstr("pushed the next next int\n");
				push_arg(stack, "pa", 1);
				//rb--;
			}*/
			if ((*stack)->b->nbr == find_next_int2(*stack, max, &check) && j + 2 <= n)
			{
				check = 1;
			//	ft_putstr("done\n");
///				ft_putstr("next 2nd int detected\n");
				push_arg(stack, "pa", 1);
				rrb--;
				//pa++;
			}
			else
			{
///				ft_putstr("reverse inside 2nd max search\n");
				reverse_rotate_arg(stack, "rrb", 1);		
				rrb++;
			}
			i++;
		}
		int check2 = 0;
		if ((*stack)->b->nbr == max)
		{
///			ft_putstr("push 2nd max\n");
			push_arg(stack, "pa", 1);
			j++;
			check2 = 1;
		}
		if (check && check2)
		{
///			ft_putstr("2nd sa \n");
			swap_arg(stack, "sa", 1);
		}
///		ft_printf("rrb = %d et rb = %d\n", rrb, rb);	
		while (rrb++ != rb)
		{
			reverse_rotate_arg(stack, "rrb", 1);
///			getchar();
		}
///		getchar();
///		ft_putstr("end of loop\n");
////		while (rrb--)
////			rotate_arg(stack, "rb", 1);
//		ft_putstr("OK2\n");
//		ft_printf("j = %d");
	}
///	ft_putstr("end of selectsort\n");
}

static void new_selectsort(t_stack **stack, int n)
{
	int		i;
	int		j;
	int		max;
	t_elem	*tmp;
	int		rb;
	int		rrb;
	int		check;
	int		pa;

	i = 0;
/*	if (stack_is_sorted2((*stack)->b, n))
	{
		ft_putstr("OK\n");
		while (i++ < n && (*stack)->b)
			push_arg(stack, "pa", 1);
	}*/
	pa = 0;
	j = 0;
	//ft_putstr("done2\n");
	while (j++ < n)
	{
//		ft_putstr("OK\n");
///		ft_putstr("start of loop\n");
///		ft_printf("n = %d\n", n);
		if (ft_stacklen((*stack)->b) == 1)
		{
			push_arg(stack, "pa", 1);
			return ;
		}
		tmp = (*stack)->b;
		max = tmp->nbr;
		//ft_printf("tmp->nbr = %d\n", tmp->nbr);
		i = 0;
		while (tmp && i < n)
		{
			if (max <= tmp->nbr)
				max = tmp->nbr;
			i++;
			tmp = tmp->next;
		}
		rrb = 0;
		rb = 0;
		check = 0;
	//	int check2 = 0;
	//	check2 = find_next_int2(*stack, max, &check) - 1;
///		ft_printf("max = %d\n", max);
		while ((*stack)->b->nbr != max)
		{
				//ft_printf("next next = %d\n", find_next_int2(*stack, find_next_int2(*stack, max, &check), &check2));
			/*if ((*stack)->b->nbr == find_next_int2(*stack, find_next_int2(*stack, max, &check), &check2))
			{
				check2 = 1;
				//push_arg(stack, "pa", 1);
			}*/
				//ft_printf("next = %d\n", find_next_int2(*stack, max, &check));
			if ((*stack)->b->nbr == find_next_int2(*stack, max, &check))
			{
				check = 1;
			//	ft_putstr("done\n");
///				ft_putstr("next int detected\n");
				push_arg(stack, "pa", 1);
				//pa++;
			}
			else //if (find_best_rotate2(*stack, max) == 1)
			{
///				ft_putstr("1st rb\n");
				rotate_arg(stack, "rb", 1);
				rb++;
			}
			/*else if (find_best_rotate2(*stack, max) == 2)
			{
				reverse_rotate_arg(stack, "rrb", 1);
				rrb++;
			}*/
		}
//		ft_putstr("2nd pa\n");
///		ft_printf("max = %d\n", max);
///		ft_printf("n = %d, pa = %d\n", n, pa);
	//	if (pa != n)
	//	{
		//ft_putstr("done2\n");
			push_arg(stack, "pa", 1);
			//pa++;
	//``	}
//		ft_printf("check = %d\n", check);
		if (check)
		{
///			ft_putstr("sa for next int\n");
			swap_arg(stack, "sa", 1);
			j++;
		}
//		ft_printf("J = %d AND n = %d\n", j, n);
		//ft_printf("b nbr before %d\n", (*stack)->b->nbr);
		while (rb--)
		{
			reverse_rotate_arg(stack, "rrb", 1);
///			getchar();
		}
///		getchar();
///		ft_putstr("end of loop\n");
////		while (rrb--)
////			rotate_arg(stack, "rb", 1);
//		ft_putstr("OK2\n");
//		ft_printf("j = %d");
	}
///	ft_putstr("end of selectsort\n");
}

static void new_selectsort_for_a(t_stack **stack, int n)
{
	int		i;
	int		j;
	int		min;
	t_elem	*tmp;
	int		ra;
	int		rra;
	int		check;
	int		pa;

	i = 0;
/*	if (stack_is_sorted2((*stack)->b, n))
	{
		ft_putstr("OK\n");
		while (i++ < n && (*stack)->b)
			push_arg(stack, "pa", 1);
	}*/
	pa = 0;
	j = 0;
	//ft_putstr("done2\n");
	while (j++ < n)
	{
//		ft_putstr("OK\n");
///		ft_putstr("start of loop\n");
///		ft_printf("n = %d\n", n);
/*		if (ft_stacklen((*stack)->a) == 1)
		{
			push_arg(stack, "pb", 1);
			return ;
		}*/
		tmp = (*stack)->a;
		min = tmp->nbr;
		//ft_printf("tmp->nbr = %d\n", tmp->nbr);
		i = 0;
		while (tmp && i < n)
		{
			if (min >= tmp->nbr)
				min = tmp->nbr;
			i++;
			tmp = tmp->next;
		}
		rra = 0;
		ra = 0;
		check = 0;
	//	int check2 = 0;
	//	check2 = find_next_int2(*stack, max, &check) - 1;
///		ft_printf("max = %d\n", max);
		while ((*stack)->a->nbr != min)
		{
				//ft_printf("next next = %d\n", find_next_int2(*stack, find_next_int2(*stack, max, &check), &check2));
			/*if ((*stack)->b->nbr == find_next_int2(*stack, find_next_int2(*stack, max, &check), &check2))
			{
				check2 = 1;
				//push_arg(stack, "pa", 1);
			}*/
				//ft_printf("next = %d\n", find_next_int2(*stack, max, &check));
			if ((*stack)->a->nbr == find_next_int(*stack, min, &check))
			{
				check = 1;
			//	ft_putstr("done\n");
///				ft_putstr("next int detected\n");
				push_arg(stack, "pb", 1);
				//pa++;
			}
			else //if (find_best_rotate2(*stack, max) == 1)
			{
///				ft_putstr("1st rb\n");
				rotate_arg(stack, "ra", 1);
				ra++;
			}
			/*else if (find_best_rotate2(*stack, max) == 2)
			{
				reverse_rotate_arg(stack, "rrb", 1);
				rrb++;
			}*/
		}
//		ft_putstr("2nd pa\n");
///		ft_printf("max = %d\n", max);
///		ft_printf("n = %d, pa = %d\n", n, pa);
	//	if (pa != n)
	//	{
		//ft_putstr("done2\n");
			push_arg(stack, "pb", 1);
			//pa++;
	//``	}
//		ft_printf("check = %d\n", check);
		if (check)
		{
///			ft_putstr("sa for next int\n");
			swap_arg(stack, "sb", 1);
			j++;
		}
//		ft_printf("J = %d AND n = %d\n", j, n);
		//ft_printf("b nbr before %d\n", (*stack)->b->nbr);
		while (ra--)
		{
			reverse_rotate_arg(stack, "rra", 1);
///			getchar();
		}
///		getchar();
///		ft_putstr("end of loop\n");
////		while (rrb--)
////			rotate_arg(stack, "rb", 1);
//		ft_putstr("OK2\n");
//		ft_printf("j = %d");
	}
///	ft_putstr("end of selectsort\n");
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
		return (new_selectsort(stack, n));
	}
//	ft_bzero(tab, n);
	lower_half_len = 0;
	median = find_pivot(*stack, n, 'b');//	
//	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
///	ft_printf("median de b = %d\n", median);
/*	tmp = (*stack)->b;
	i = 0;
	j = 1;
	l = 0;
	while (j <= n)
	{
		if (tmp->nbr > median)
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
		median = find_pivot(*stack, n, 'a');//	
//	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
///	ft_printf("median de a = %d\n", median);
/*	tmp = (*stack)->a;
	i = 0;
	j = 1;
	l = 0;
	while (j <= n)
	{
		if (tmp->nbr > median)
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
void	ft_quicksort_for_b2(t_stack **stack, int n);
void	ft_quicksort_tab3(t_stack **stack, int n, int x);
static void	ft_quicksort_for_a(t_stack **stack, int n)
{
	int		lower_half_len;
	int		i;
	int		j;
	int		k;
	int		l;
	int		median;
	int		ra;
//	int		tab[n];
	t_elem	*tmp;
//	if (stack_is_sorted((*stack)->a) == 1 || stack_is_sorted2((*stack)->a, n) == 1)
//		return i;
	lower_half_len = 0;
	ft_printf("n de a = %d\n", n);
	if (n <= 3 && !stack_is_sorted2((*stack)->a, n))
	{
		ft_putstr("first 4 pa\n");
		i = 0;
		while (i++ < n)
			push_arg(stack, "pb", 1);
		lower_half_len = n;
	}
	//ft_printf("sorted = %d\n", stack_is_sorted2((*stack)->a, n));
//	if (stack_is_sorted2((*stack)->a, n) == 1)
//		return ;
/*	if (n <= 10)
	{
//		ft_putstr("select sorted\n");
		return (new_selectsort(stack, n));
	}*/
//	ft_bzero(tab, n);
	median = find_pivot(*stack, n, 'a');//	
//	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
	ft_printf("median de a = %d\n", median);
/*	tmp = (*stack)->a;
	i = 0;
	j = 1;
	l = 0;
	while (j <= n)
	{
		if (tmp->nbr > median)
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
	ra = 0;
	while (i < n && n > 3) //////while (i <= l)//for 0 to n {    //filter all values above the median into list 2
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
		if ((*stack)->a->nbr < median)//////if ((*stack)->a->nbr == tab[k])
		{
			push_arg(stack, "pb", 1);//push list 1 top to list 2 //list 2 stores the larger half

			lower_half_len++;
///			ft_printf("loweereeer in while of B = %d\n", lower_half_len);
			//k++;
		}
		else
		{
			rotate_arg(stack, "ra", 1);//rotate list 1 forward
			ra++;
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
////////	ft_putstr("Rotate for median\n");
	int	rra = 0;
	while ((*stack)->a->nbr != median && !(stack_is_sorted2((*stack)->a, n)))
	{
		reverse_rotate_arg(stack, "rra", 1);
		rra++;
	}
	ft_printf("Start of QT B2 with LHL = %d!\n", lower_half_len);
	ft_quicksort_for_b2(stack, lower_half_len);
	ft_putstr("End of QT B2!\n");
///	ft_printf("LHL of B = %d\n", lower_half_len);
	/*i = 0;
	while (i++ < lower_half_len)
		push_arg(stack, "pb", 1);
///	ft_printf("DEBUT QT B1\n");
	ft_quicksort_for_b2(stack, lower_half_len);
///	ft_printf("FIN QT B1\n");*/
///	ft_putstr("push the median\n");
///////	push_arg(stack, "pb", 1);
	i = 0;
	while (rra + i++ < ra)
		reverse_rotate_arg(stack, "rra", 1);
	ft_printf("Start of QT B2 NEXT with LHL = %d!\n", lower_half_len);
	ft_quicksort_for_b2(stack, n - (lower_half_len + 1));
	ft_putstr("End of QT B2 NEXT!\n");
	/*getchar();
	ft_putstr("Put in front (B)\n");
	i = 1;
	while (i++ <= lower_half_len) //&& !stack_is_sorted((*stack)->a))
		rotate_arg(stack, "rb", 1);
///	ft_printf("DEBUT QT B2\n");
	ft_quicksort_for_b2(stack, n - (lower_half_len + 1));
///	ft_printf("FIN QT B2\n");
	//getchar();
	ft_putstr("Reverse put (B)\n");
	i = 1;
	while (i++ <= lower_half_len) //&& !stack_is_sorted((*stack)->a))
		reverse_rotate_arg(stack, "rrb", 1);
	//getchar();*/
}
void	ft_quicksort_for_b2(t_stack **stack, int n)
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
	ft_printf("n de b2 = %d\n", n);
	if (n == 1)
	{
///		ft_putstr("first pa\n");
		push_arg(stack, "pa", 1);
		return ;
	}
	if (!(*stack)->b)
		return ;
	if (n <= 10)
	{
		ft_putstr("select sorted\n");
		return (new_selectsort(stack, n));
	}
//	ft_bzero(tab, n);
	lower_half_len = 0;
	median = find_pivot(*stack, n, 'b');//	
//	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
	ft_printf("median de b2 = %d\n", median);
/*	tmp = (*stack)->b;
	i = 0;
	j = 1;
	l = 0;
	while (j <= n)
	{
		if (tmp->nbr > median)
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
	rb = 0;
	while (i < n) //////while (i <= l)//for 0 to n {    //filter all values above the median into list 2
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
/////////	int	rrb = 0;
/////////	while ((*stack)->b->nbr != median)
////////	{
/////////		reverse_rotate_arg(stack, "rrb", 1);
///////		rrb++;
////////	}
	while (rb--)
		reverse_rotate_arg(stack, "rrb", 1);
///	ft_putstr("Start QT A\n");
	ft_quicksort_tab3(stack, lower_half_len , 0);
///	ft_putstr("End QT A\n");
///	ft_putstr("Start QT2 BBBBBBB\n");
	ft_quicksort_for_b2(stack, n - lower_half_len);
///	ft_putstr("End QT2 BBBBBBB\n");
/*///	ft_printf("LHL of B = %d\n", lower_half_len);
	i = 0;
	while (i++ < lower_half_len)
		push_arg(stack, "pb", 1);
///	ft_printf("DEBUT QT B1\n");
	ft_quicksort_for_b2(stack, lower_half_len);
///	ft_printf("FIN QT B1\n");
	ft_putstr("push the median\n");
	push_arg(stack, "pa", 1);
	
	i = 0;
	while (rrb + i++ < rb)
		reverse_rotate_arg(stack, "rrb", 1);
	ft_putstr("Start QT A NEXT\n");
	ft_quicksort_for_b2(stack, n - (lower_half_len + 1));
	ft_putstr("End QT A NEXT\n");
	getchar();
	ft_putstr("Put in front (B)\n");
	i = 1;
	while (i++ <= lower_half_len) //&& !stack_is_sorted((*stack)->a))
		rotate_arg(stack, "rb", 1);
///	ft_printf("DEBUT QT B2\n");
	ft_quicksort_for_b2(stack, n - (lower_half_len + 1));
///	ft_printf("FIN QT B2\n");
	//getchar();
	ft_putstr("Reverse put (B)\n");
	i = 1;
	while (i++ <= lower_half_len) //&& !stack_is_sorted((*stack)->a))
		reverse_rotate_arg(stack, "rrb", 1);*/
}

void	ft_quicksort_tab3_for_b(t_stack **stack, int n, int x)
{
	int		lower_half_len;
	int		i;
	int		j;
	int		k;
	int		l;
	int		median;
	int		tab[n];
	t_elem	*tmp;
//	if (stack_is_sorted((*stack)->a) == 1 || stack_is_sorted2((*stack)->a, n) == 1)
//		return ;
	lower_half_len = 0;
///	ft_printf("n de a = %d with index = %d\n", n, x );
///	ft_printf("n = %d\n", n);
//	if ((!(*stack)->a && stack_is_sorted((*stack)->b)) || !(*stack)->b || n <= 0)
//		return ;
	if (stack_is_sorted((*stack)->a))
		return ;
	if (n == 2)
	{
		push_arg(stack, "pa", 1);
		push_arg(stack, "pa", 1);
		return ;
	}
//	if (n < 1)
//		return ;
//	if (!(*stack)->a)
//		return ;
//	ft_bzero(tab, n);
///	median = 0;
	if ((*stack)->b)
		median = find_pivot(*stack, n, 'b');//	
//	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
///	ft_printf("median de a = %d\n", median);
	tmp = (*stack)->b;
	i = 0;
	j = 1;
	l = 0;
	while (j <= n)
	{
		if (tmp->nbr > median)
		{
			tab[i] = tmp->nbr;
			i++;
			l = j;
		}
		tmp = tmp->next;
		j++;
	}
	i = i;
	k = 0;
//	ft_putstr("OK\n");
	int	rb = 0;
	int median2 = 0;
///	ft_putstr("OK2\n");
///	getchar();
	while (i <= l)//while (i < n && n != 1 && (*stack)->b) //////while (i <= l)//for 0 to n {    //filter all values above the median into list 2
	{
/*		if (n == 2)
		{
			push_arg(stack, "pb", 1);
			push_arg(stack, "pb", 1);
			lower_half_len = 2;
			break ; 
		}*/
		if ((*stack)->b->nbr == tab[k])//if ((*stack)->b->nbr > median)//////if ((*stack)->a->nbr == tab[k])
		{
			if (x == 0 && (*stack)->a)
			{
				median2 = find_pivot(*stack, ft_stacklen((*stack)->a), 'a');
				//ft_printf("median2 = %d\n", median2);
				if ((*stack)->b->nbr > median2)
					rotate_arg(stack, "ra", 1);
			}
			push_arg(stack, "pa", 1);//push list 1 top to list 2 //list 2 stores the larger half
			lower_half_len++;
			k++;
		}
		else //if (find_best_rotate(*stack, median) == 1)
		{
			rotate_arg(stack, "rb", 1);//rotate list 1 forward
			rb++;
		}
	//	else if (find_best_rotate(*stack, min) == 2)
	//		reverse_rotate_arg(stack, "rra", 1);
		i++;
	/////////////	if (stack_is_sorted((*stack)->a) && !(*stack)->b)
	///////////		return ;
//	ft_printf("tab[%d] = %d\n", k , tab[k]);
	}
///////////	int rra = 0;
/////////	while ((*stack)->a && (*stack)->a->nbr != median)
/////////	{
/////////		reverse_rotate_arg(stack, "rra", 1);
///////		rra++;
///////	}
	//ft_putstr("OK\n");
///	ft_printf("is_empty = %d\n", (*stack)->a_is_empty);
	/*while (ra-- && 
		reverse_rotate_arg(stack, "rra", 1);*/
/*	ft_putstr("PUSH the median of A\n");
	push_arg(stack, "pb", 1);
	while (rra-- && !stack_is_sorted((*stack)->a))
		rotate_arg(stack, "ra", 1);*/
///	ft_printf("resut -> lhl =%d with index = %d\n", lower_half_len, x);
//	ft_putstr("OK\n");
	if ((*stack)->b)
	{
///		ft_putstr("START 2 A\n");
    	ft_quicksort_tab3_for_b(stack, n - (lower_half_len), x + 1);
///		ft_putstr("END 2 A\n");
	}
//	ft_putstr("OK2\n");
//	while (lower_half_len--)
//		push_arg(stack, "pa", 1);
///	ft_printf("n 2eme de a = %d\n", n);
///	ft_printf("lhl = %d et n - lhl = %d\n", lower_half_len, n - lower_half_len);
/*	ft_putstr("DEBUT QT FOR B1\n");
	ft_quicksort_for_b(stack, n - lower_half_len);
	ft_putstr("FIN QT FOR B1\n");
	ft_quicksort_for_b(stack, lower_half_len);
	ft_putstr("FIN AT FOR B2\n");*/
///	ft_putstr("MAIN DEBUT QT B2\n");
	///////////////////////////ft_quicksort_for_b2(stack, lower_half_len);
///	ft_putstr("MAIN FIN QT B2\n");
///	ft_putstr("end of B\n");
}
void	ft_quicksort_tab33(t_stack **stack, int n, int x)
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
	ft_printf("n = %d\n", n);
	if ((!(*stack)->b && stack_is_sorted((*stack)->a)) || !(*stack)->a || n <= 0)
		return ;
	/*if (n == 2)
	{
		push_arg(stack, "pb", 1);
		push_arg(stack, "pb", 1);
		return ;
	}*/
	if (n == 1)
	{
		push_arg(stack, "pb", 1);
		(*stack)->a_is_empty = 1;
		lower_half_len = 1;
	}
//	if (n < 1)
//		return ;
//	if (!(*stack)->a)
//		return ;
//	ft_bzero(tab, n);
///	median = 0;
	if ((*stack)->a)
		median = find_pivot(*stack, n, 'a');//	
//	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
	ft_printf("median de a = %d\n", median);
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
	int	ra = 0;
	int median2 = 0;
///	ft_putstr("OK\n");
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
			lower_half_len++;
			//k++;
		}
		else //if (find_best_rotate(*stack, median) == 1)
		{
			rotate_arg(stack, "ra", 1);//rotate list 1 forward
			ra++;
		}
	//	else if (find_best_rotate(*stack, min) == 2)
	//		reverse_rotate_arg(stack, "rra", 1);
		i++;
	/////////////	if (stack_is_sorted((*stack)->a) && !(*stack)->b)
	///////////		return ;
//	ft_printf("tab[%d] = %d\n", k , tab[k]);
	}
///////////	int rra = 0;
/////////	while ((*stack)->a && (*stack)->a->nbr != median)
/////////	{
/////////		reverse_rotate_arg(stack, "rra", 1);
///////		rra++;
///////	}
	//ft_putstr("OK\n");
	ft_printf("is_empty = %d\n", (*stack)->a_is_empty);
	while (ra-- && (*stack)->a_is_empty == 1)
		reverse_rotate_arg(stack, "rra", 1);
/*	ft_putstr("PUSH the median of A\n");
	push_arg(stack, "pb", 1);
	while (rra-- && !stack_is_sorted((*stack)->a))
		rotate_arg(stack, "ra", 1);*/
///	ft_printf("resut -> lhl =%d with index = %d\n", lower_half_len, x);
//	ft_putstr("OK\n");

	if ((*stack)->a)
	{
///		ft_putstr("START 2 A\n");
    	ft_quicksort_tab33(stack, n - (lower_half_len), x + 1);
///		ft_putstr("END 2 A\n");
	}
//	ft_putstr("OK2\n");
//	while (lower_half_len--)
//		push_arg(stack, "pa", 1);
///	ft_printf("n 2eme de a = %d\n", n);
///	ft_printf("lhl = %d et n - lhl = %d\n", lower_half_len, n - lower_half_len);
/*	ft_putstr("DEBUT QT FOR B1\n");
	ft_quicksort_for_b(stack, n - lower_half_len);
	ft_putstr("FIN QT FOR B1\n");
	ft_quicksort_for_b(stack, lower_half_len);
	ft_putstr("FIN AT FOR B2\n");*/
	ft_putstr("MAIN DEBUT QT B2\n");
	ft_quicksort_for_b2(stack, lower_half_len);
	ft_putstr("MAIN FIN QT B2\n");
///	ft_putstr("end A\n");
}

void	ft_quicksort_tab3(t_stack **stack, int n, int x)
{
	int		lower_half_len;
	int		i;
	int		j;
	int		k;
	int		l;
	int		median;
	int		tab[n];
	t_elem	*tmp;
//	if (stack_is_sorted((*stack)->a) == 1 || stack_is_sorted2((*stack)->a, n) == 1)
//		return ;
	lower_half_len = 0;
///	ft_printf("n de a = %d with index = %d\n", n, x );
///	ft_printf("n = %d\n", n);
//	if ((!(*stack)->b && stack_is_sorted((*stack)->a)) || !(*stack)->a || n <= 0)
//		return ;
	if (!(*stack)->a || stack_is_sorted((*stack)->a))
		return ;
	if (n == 2)
	{
		push_arg(stack, "pb", 1);
		push_arg(stack, "pb", 1);
		return ;
	}
	if (n == 1)
	{
		push_arg(stack, "pb", 1);
		(*stack)->a_is_empty = 1;
		lower_half_len = 1;
	}
//	if (n < 1)
//		return ;
//	if (!(*stack)->a)
//		return ;
//	ft_bzero(tab, n);
///	median = 0;
	if ((*stack)->a)
		median = find_pivot(*stack, n, 'a');//	
//	median = (*stack)->a->nbr;//choose a median //it's up to you to determine the best way to do this
///	ft_printf("median de a = %d\n", median);
	tmp = (*stack)->a;
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
	}
	i = 1;
	k = 0;
//	ft_putstr("OK\n");
	int	ra = 0;
	int median2 = 0;
///	ft_putstr("OK\n");
	while (i <= l)//while (i < n && n != 1 && (*stack)->a) //////while (i <= l)//for 0 to n {    //filter all values above the median into list 2
	{
/*		if (n == 2)
		{
			push_arg(stack, "pb", 1);
			push_arg(stack, "pb", 1);
			lower_half_len = 2;
			break ; 
		}*/
		if ((*stack)->a->nbr == tab[k])//if ((*stack)->a->nbr < median)//////if ((*stack)->a->nbr == tab[k])
		{
			if (x == 0 && (*stack)->b)
			{
				median2 = find_pivot(*stack, ft_stacklen((*stack)->b), 'b');
				//ft_printf("median2 = %d\n", median2);
				if ((*stack)->b->nbr < median2)
					rotate_arg(stack, "rb", 1);
			}
			push_arg(stack, "pb", 1);//push list 1 top to list 2 //list 2 stores the larger half
			lower_half_len++;
			k++;
		}
		else //if (find_best_rotate(*stack, median) == 1)
		{
			rotate_arg(stack, "ra", 1);//rotate list 1 forward
			ra++;
		}
	//	else if (find_best_rotate(*stack, min) == 2)
	//		reverse_rotate_arg(stack, "rra", 1);
		i++;
	/////////////	if (stack_is_sorted((*stack)->a) && !(*stack)->b)
	///////////		return ;
//	ft_printf("tab[%d] = %d\n", k , tab[k]);
	}
///////////	int rra = 0;
/////////	while ((*stack)->a && (*stack)->a->nbr != median)
/////////	{
/////////		reverse_rotate_arg(stack, "rra", 1);
///////		rra++;
///////	}
	//ft_putstr("OK\n");
///	ft_printf("is_empty = %d\n", (*stack)->a_is_empty);
	/*while (ra-- && (*stack)->a_is_empty == 1)
		reverse_rotate_arg(stack, "rra", 1);*/
/*	ft_putstr("PUSH the median of A\n");
	push_arg(stack, "pb", 1);
	while (rra-- && !stack_is_sorted((*stack)->a))
		rotate_arg(stack, "ra", 1);*/
///	ft_printf("resut -> lhl =%d with index = %d\n", lower_half_len, x);
//	ft_putstr("OK\n");
	if ((*stack)->a)
	{
///		ft_putstr("START 2 A\n");
    	ft_quicksort_tab3(stack, n - (lower_half_len), x + 1);
///		ft_putstr("END 2 A\n");
	}
//	ft_putstr("OK2\n");
//	while (lower_half_len--)
//		push_arg(stack, "pa", 1);
///	ft_printf("n 2eme de a = %d\n", n);
///	ft_printf("lhl = %d et n - lhl = %d\n", lower_half_len, n - lower_half_len);
/*	ft_putstr("DEBUT QT FOR B1\n");
	ft_quicksort_for_b(stack, n - lower_half_len);
	ft_putstr("FIN QT FOR B1\n");
	ft_quicksort_for_b(stack, lower_half_len);
	ft_putstr("FIN AT FOR B2\n");*/
///	ft_putstr("MAIN DEBUT QT B2\n");
	///////////////////////////ft_quicksort_for_b2(stack, lower_half_len);
///	ft_putstr("MAIN FIN QT B2\n");
///	ft_putstr("end A\n");
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
	stack->a_is_empty = 0;
//	ft_putstr("A : ");
//	afficherPile1(stack->a);
//	ft_putchar('\n');
//	ft_printf("best = %d\n", find_best_rotate(stack, 1));
//	ft_quicksort(&stack, stack_len, 0);
//	ft_quicksort_tab(&stack, stack_len, 0);
	///if (stack_len <= 10)
	///	ft_selectsort3(&stack, stack_len);
	if (stack_len >= 300)
		ft_quicksort_tab2(&stack, stack_len, 0);
/*	else if (stack_len >= 150)
	{
		ft_quicksort_tab3(&stack, stack_len, 0);
		ft_quicksort_tab3_for_b(&stack, stack_len, 0);
		ft_quicksort_tab3(&stack, stack_len, 0);
		new_selectsort3(&stack, stack_len);
	}*/
	else
	{
		ft_quicksort_tab3(&stack, stack_len, 0);
		new_selectsort3(&stack, stack_len);
	}
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
//	ft_putstr("A : ");
//	afficherPile1(stack->a);
//	ft_putchar('\n');
//	ft_printf("flags->v = %d\n", flags.v);
//ft_printf("flags->f = %d\n", flags.f);
//	ft_printf("test = %s %sred%s\n", "TEST", RED, EOC);
	free_stack(stack);
	return (0);
}
