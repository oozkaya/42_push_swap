/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:24:37 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/07 21:04:14 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "displayer.h"
# include <fcntl.h>

# define INT_MAXI 2147483647
# define INT_MINI -2147483648

#define NO_FLAG 0
#define FLAG_C 1
#define FLAG_F 2
#define FLAG_L 4
#define FLAG_V 8

typedef struct	s_elem
{
	int				nbr;
	int				index;
	struct s_elem	*next;
}				t_elem;

typedef struct	s_buff
{
	char	*str;
	int		index;
	int		len;
}				t_buff;

typedef struct	s_stack
{
	t_elem		*a;
	t_elem		*b;
	t_buff		*buf;
}				t_stack;

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
	int		l;
}				t_flags;


/*
** Instructions
*/
void			ft_push_stack(t_elem **elem, int new_nbr);
int				ft_pop_stack(t_elem **elem);
void			ft_swap_stack(t_elem **elem);
void			ft_rotate_stack(t_elem **elem);
void			ft_reverse_rotate_stack(t_elem **elem);

void			swap_arg(t_stack **stack, char *arg, int print);
void			push_arg(t_stack **stack, char *arg, int print);
void			rotate_arg(t_stack **stack, char *arg, int print);
void			reverse_rotate_arg(t_stack **stack, char *arg, int print);

/*
** Stacks and Buffer
*/
void			init_buffer(t_buff **buf);
void			add_buffer(t_buff **buf, char *str, size_t size);

t_stack			*ft_stack_initialize(void);
void			free_stack(t_stack *stack);

/*
** Main Tools
*/
int				stack_is_sorted(t_elem *elem);
int				ft_stacklen(t_elem *elem);
int				ft_tablen(char **tab);
void			refresh_index(t_elem **elem);
void			fill_stack(t_stack **stack, int ac, char **av, int start);
int				ft_flag_checker(int ac, char **av, int *flags, t_stack *stack);
char			*ft_filename(int ac, char **av, int flags, t_stack *stack);
int				ft_reader(t_stack **stack, int flags, const t_op *tab_op,
															char *filename);

/*
** Solvers
*/
void			ft_quicksort_a2b(t_stack **stack, int size);
void			ft_insertion_sort(t_stack **stack, int size);
int				low_part_sort(t_stack **stack, int size);

/*
** Finders
*/
int				ft_find_index(t_elem *elem, int nbr);
int				ft_find_max(t_elem *elem, int len);
int				ft_find_min(t_elem *elem, int len);
int				ft_find_next(t_elem *elem, int nbr, int max);
int				find_best_rotate(t_elem *elem, int nbr, int len);
int				find_median(t_stack *stack, int size, char c);

#endif
