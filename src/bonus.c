/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:44:56 by oozkaya           #+#    #+#             */
/*   Updated: 2018/04/26 18:59:14 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_usage(void)
{
	ft_putstr("Usage: ./push_swap [options] [arg1] [arg2] ...\n");
	ft_putstr("Options : -f to write on a file\n");
	ft_putstr("\n\nUsage: ./checker [options] [arg1] [arg2] ...\n");
	ft_putstr("Options : -v to display the moves \n");
	ft_putstr("\t  -c to display the last move\n");
	ft_putstr("\t  -f to read on a file\n");
}

static void	ft_flag_parse(char *str, t_flags *flags)
{
	int		i;

	flags->v = 0;
	flags->c = 0;
	flags->f = 0;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'v')
			flags->v = 1;
		else if (str[i] == 'c')
			flags->c = 1;
		else if (str[i] == 'f')
			flags->f = 1;
		else if (str[i] == 'l')
			flags->l = 1;
		else
		{
			ft_usage();
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int			ft_flag_checker(int ac, char **av, t_flags *flags)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && !ft_isdigit(av[i][1]))
		{
			ft_flag_parse(av[i], flags);
			i++;
		}
		else
			return (i);
	}
	return (i);
}
