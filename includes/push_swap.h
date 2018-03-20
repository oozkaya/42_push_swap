/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:24:37 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/20 20:13:36 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <fcntl.h>

typedef struct		s_elem
{
	int				nbr;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_buff
{
	char	*str;
	int		index;
	int		len;
}					t_buff;

typedef struct		s_stack
{
	t_elem		*a;
	t_elem		*b;
	t_buff		*buf;
}					t_stack;

typedef struct	s_op
{
	char	*op;
	void	(*arg)(t_stack **stack, char *arg, int print);
}				t_op;

typedef struct	s_flags
{
	int		v;
	int		c;
	int		f;
}				t_flags;

t_stack *ft_stack_initialize(void);
void	free_stack(t_stack *stack);

int		ft_flag_checker(int ac, char **av, t_flags *flags);

void	ft_push_stack(t_elem **elem, int new_nbr);
int		ft_pop_stack(t_elem **elem);
void	ft_swap_stack(t_elem **elem);
void	ft_rotate_stack(t_elem **elem);
void	ft_reverse_rotate_stack(t_elem **elem);

void	swap_arg(t_stack **stack, char *arg, int print);
void	push_arg(t_stack **stack, char *arg, int print);
void	rotate_arg(t_stack **stack, char *arg, int print);
void	reverse_rotate_arg(t_stack **stack, char *arg, int print);

void	init_buffer(t_buff **buf);
void	add_buffer(t_buff **buf, char *str, size_t size);

void	afficherPile(t_elem *elem);
void	afficherPile1(t_elem *elem);
void	print_all(t_stack *stack);

int		stack_is_sorted(t_elem *elem);
int		ft_stacklen(t_stack *stack);
int		ft_tablen(char **tab);
void	ft_fill_stack(t_stack **stack, int ac, char **av, int start);

#endif
