/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:44:56 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/07 21:08:10 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_usage(void)
{
	ft_putstr("Usage: ./push_swap [options] [arg1] [arg2] ...\n");
	ft_putstr("Options : -f [filename] to write on a file\n");
	ft_putstr("\n\nUsage: ./checker [options] [arg1] [arg2] ...\n");
	ft_putstr("Options : -v to display the moves \n");
	ft_putstr("\t  -c to display the last move\n");
	ft_putstr("\t  -f [filename] to read on a file\n");
}

char	*ft_filename(int ac, char **av, int flags, t_stack *stack)
{
	int		i;

	if (flags & FLAG_F)
	{
		i = 1;
		while (i < ac)
		{
			if (ft_strend(av[i], ".txt"))
				return (av[i]);
			i++;
		}
	}
	ft_usage();
	free_stack(stack);
	exit(EXIT_FAILURE);
	return (NULL);
}

static void	ft_flag_parse(char *str, int *flags, t_stack *stack)
{
	int		i;


	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'v')
			*flags |= FLAG_V;
		else if (str[i] == 'c')
			*flags |= FLAG_C;
		else if (str[i] == 'f')
			*flags |= FLAG_F;
		else if (str[i] == 'l')
			*flags |= FLAG_L;
		else
		{
			ft_usage();
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int			ft_flag_checker(int ac, char **av, int *flags, t_stack *stack)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && !ft_isdigit(av[i][1]))
		{
			ft_flag_parse(av[i], flags, stack);
			i++;
		}
		else if (*flags & FLAG_F)
			return (i + 1);
		else
			return (i);
	}
	return (i);
}
