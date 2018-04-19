/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:44:56 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/20 19:45:26 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		else
		{
			ft_putstr("Usage()\n");
			exit(EXIT_FAILURE);//ft_usage();
		}
		i++;
	}
}

int			ft_flag_checker(int ac, char **av, t_flags *flags)
{
	int i = 1;
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
