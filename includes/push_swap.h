/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:24:37 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/19 16:38:56 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define BUFFER_SIZE 4096

typedef struct		s_elem
{
	int				nbr;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_buffer
{
	char	*str;
	int		index;
	int		len;
	int		fd;
}					t_buffer;

typedef struct		s_stack
{
	t_elem		*a;
	t_elem		*b;
	t_buffer	*buf;
}					t_stack;

typedef struct	s_op
{
	char	*op;
	void	(*arg)(t_stack **stack, char *arg, int print);
}				t_op;

t_stack *ft_stack_initialize(void);
void	free_stack(t_stack *stack);

void	ft_push_stack(t_elem **elem, int new_nbr);
int		ft_pop_stack(t_elem **elem);
void	ft_swap_stack(t_elem **elem);
void	ft_rotate_stack(t_elem **elem);
void	ft_reverse_rotate_stack(t_elem **elem);

void	swap_arg(t_stack **stack, char *arg, int print);
void	push_arg(t_stack **stack, char *arg, int print);
void	rotate_arg(t_stack **stack, char *arg, int print);
void	reverse_rotate_arg(t_stack **stack, char *arg, int print);

void	buffer_init(t_buffer **buf);
void	buffer_add_char(t_buffer **buf, char c, size_t size);
void	buffer_add_str(t_buffer **buf, char *str, size_t size);

void	afficherPile(t_elem *elem);
void	afficherPile1(t_elem *elem);
void	print_all(t_stack *stack);

int		stack_is_sorted(t_elem *elem);
int		ft_stacklen(t_stack *stack);
int		ft_tablen(char **tab);
void	ft_fill_stack(t_stack **stack, int ac, char **av);

#endif
