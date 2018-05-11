/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer_init_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:55:38 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/11 14:53:29 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_absmax(t_elem *elem, int len)
{
	int		i;
	int		max;
	t_elem	*tmp;

	tmp = elem;
	max = ft_abs(tmp->nbr);
	i = 0;
	while (tmp && i < len)
	{
		if (max <= ft_abs(tmp->nbr))
			max = ft_abs(tmp->nbr);
		i++;
		tmp = tmp->next;
	}
	return (max);
}

static void	ft_create_renderer(t_sdl **sdl)
{
	(*sdl)->ren = SDL_CreateRenderer((*sdl)->win, -1, SDL_RENDERER_ACCELERATED);
	if (!(*sdl)->ren)
	{
		SDL_Log("SDL_CreateRenderer Error : %s", SDL_GetError());
		SDL_DestroyRenderer((*sdl)->ren);
		SDL_DestroyWindow((*sdl)->win);
		SDL_Quit();
		return ;
	}
}

static void	ft_create_window(t_sdl **sdl)
{
	(*sdl)->win = SDL_CreateWindow("Push_Swap - oozkaya",
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				WIDTH, (*sdl)->height, SDL_WINDOW_RESIZABLE);
	if (!(*sdl)->win)
	{
		SDL_Log("SDL_CreateWindow Error : %s", SDL_GetError());
		SDL_DestroyWindow((*sdl)->win);
		SDL_Quit();
		return ;
	}
}

void		ft_displayer_init(t_sdl **sdl, t_stack *stack)
{
	if (!(*sdl = (t_sdl*)malloc(sizeof(t_sdl))))
		return ;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL_Init Error : %s", SDL_GetError());
		SDL_Quit();
		return ;
	}
	(*sdl)->quit = 0;
	(*sdl)->play = 0;
	(*sdl)->len = ft_stacklen(stack->a);
	(*sdl)->height = HEIGHT / (*sdl)->len;
	(*sdl)->height = (*sdl)->height * (*sdl)->len;
	(*sdl)->max = ft_find_absmax(stack->a, (*sdl)->len);
	ft_create_window(sdl);
	ft_create_renderer(sdl);
	ft_display(sdl, stack);
}

void		ft_displayer_free(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	SDL_Quit();
	ft_memdel((void**)&sdl);
}
