/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:12:42 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/01 22:07:44 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	ft_sdl_error(char *str, char *error)
{
		SDL_Log("%s %s\n", str, error);
		SDL_Quit();
		exit(EXIT_FAILURE);
}*/

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

static void	ft_create_texture(t_sdl **sdl)
{
	(*sdl)->tex = SDL_CreateTexture((*sdl)->ren,
	SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, WIDTH, (*sdl)->height);
	if (!(*sdl)->ren)
	{
		SDL_Log("SDL_CreateTexture Error : %s", SDL_GetError());
		SDL_DestroyTexture((*sdl)->tex);
		SDL_DestroyRenderer((*sdl)->ren);
		SDL_DestroyWindow((*sdl)->win);
		SDL_Quit();
		return ;
	}
}

void	ft_displayer_init(t_sdl **sdl, t_stack *stack)
{
	if (!(*sdl = (t_sdl*)malloc(sizeof(t_sdl))))
		return ; //ft_sdl_error("Malloc Error : ", "t_sdl *sdl");
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL_Init Error : %s", SDL_GetError());
		SDL_Quit();
		return ;
	}
	(*sdl)->len = ft_stacklen(stack->a);
	(*sdl)->height = HEIGHT / (*sdl)->len;
	(*sdl)->height = (*sdl)->height * (*sdl)->len;
	ft_create_window(sdl);
	ft_create_renderer(sdl);
	ft_create_texture(sdl);
}

static void	ft_window_background(t_sdl **sdl)
{
	(*sdl)->rect_a.x = 0;
	(*sdl)->rect_a.y = 0;
	(*sdl)->rect_a.w = WIDTH / 2;
	(*sdl)->rect_a.h = (*sdl)->height;
	(*sdl)->rect_b.x = WIDTH / 2;
	(*sdl)->rect_b.y = 0;
	(*sdl)->rect_b.w = WIDTH / 2;
	(*sdl)->rect_b.h = (*sdl)->height;
	SDL_SetRenderDrawColor((*sdl)->ren, 0, 0, 0, 0);
	SDL_RenderFillRect((*sdl)->ren, &(*sdl)->rect_a);
	SDL_SetRenderDrawColor((*sdl)->ren, 190, 0, 0, 0);
	SDL_RenderFillRect((*sdl)->ren, &(*sdl)->rect_b);
}

static void	ft_display_stick(t_sdl **sdl, int n, SDL_Rect stick, char c)
{
	if (n >= 0)
	{
		if (c == 'b')
			SDL_SetRenderDrawColor((*sdl)->ren, 0, 0, 0, 0);
		else
			SDL_SetRenderDrawColor((*sdl)->ren, 190, 0, 0, 0);
	}
	else if (n < 0)
		SDL_SetRenderDrawColor((*sdl)->ren, 255, 255, 255, 0);
	SDL_RenderFillRect((*sdl)->ren, &stick);
}
#include <stdio.h>

static void ft_display_a(t_sdl **sdl, t_stack *stack)
{
	t_elem		*tmp;
	SDL_Rect	stick;

	tmp = stack->a;
	stick.y = 0 - stick.h;
	while (tmp)
	{
		stick.w = (WIDTH / 2) * (tmp->nbr + 1) / (*sdl)->max;
		stick.h = (*sdl)->height / (*sdl)->len;
		stick.x = 0;
		stick.y += stick.h;
	//	ft_printf("stick.y = %d et stick.h = %d\n", stick.y, stick.h);
	//	ft_printf("stick.w = %d et stick.h = %d\n", stick.w, stick.h);
	//	ft_printf("tmp->nbr = %d\n", tmp->nbr);
		ft_display_stick(sdl, tmp->nbr, stick, 'a');
		tmp = tmp->next;
	}
}

static void ft_display_stacks(t_sdl **sdl, t_stack *stack, char c)
{
	t_elem		*tmp;
	SDL_Rect	stick;

	if (c == 'a')
		tmp = stack->a;
	else
		tmp = stack->b;
	stick.h = (*sdl)->height / (*sdl)->len;
	stick.y = 0 - stick.h;
	//stick.y = 0;
	//stick.h = (*sdl)->height * (*sdl)->len;
	//stick.w = 0;
	while (tmp)
	{
		//if ((stick.w = tmp->nbr * (WIDTH / 2) / ((*sdl)->max - (*sdl)->min)) == 0)
			//stick.w = 0.2 * (WIDTH / 2) / ((*sdl)->max - (*sdl)->min);
		stick.w = (WIDTH / 2) * (ft_abs(tmp->nbr) + 1) / ((*sdl)->max - (*sdl)->min);
	//ft_putstr("OKKKKKKK\n");
		/*if (tmp->nbr == (*sdl)->min)
		{
			ft_printf("miiiiiiiin = stick.w = %d et stick.h = %d\n", stick.w, stick.h);
			//getchar();
		}*/
		if ((stick.w -= ((WIDTH / 2) * 1 / ((*sdl)->max - (*sdl)->min))) == 0)//(*sdl)->max)) == 0)
			stick.w = 0.2 * (WIDTH / 2) / ((*sdl)->max - (*sdl)->min);
		/*if (tmp->nbr == (*sdl)->min)
		{
			ft_printf("miiiiiiiin = stick.w = %d et stick.h = %d\n", stick.w, stick.h);
			getchar();
		}*/
		if (c == 'a')
			stick.x = WIDTH / 4 - stick.w / 2;//stick.x = 0;
		else
			stick.x = WIDTH / 2 + WIDTH / 4 - stick.w / 2;//stick.x = WIDTH / 2;
		stick.y += stick.h;
		/*if (tmp->nbr == (*sdl)->max)
		{
			ft_printf("maaaaaaaax = stick.w = %d et stick.h = %d\n", stick.w, stick.h);
			//getchar();
		}
		ft_printf("stick.w = %d et stick.h = %d\n", stick.w, stick.h);*/
	//	ft_printf("tmp->nbr = %d\n", tmp->nbr);
	//	ft_printf("stick.y = %d et stick.h = %d\n", stick.y, stick.h);
		ft_display_stick(sdl, tmp->nbr, stick, c);
		tmp = tmp->next;
	}
}

void	ft_display(t_sdl **sdl, t_stack *stack)
{
//	t_sdl	*sdl;

	//ft_displayer_init(&sdl);
//	SDL_SetRenderDrawColor(sdl->ren, 255, 0, 0, 255);
	SDL_RenderClear((*sdl)->ren);
	ft_window_background(sdl);
	ft_display_stacks(sdl, stack, 'a');
	ft_display_stacks(sdl, stack, 'b');
//	SDL_SetRenderTarget(sdl->ren, NULL);
//	SDL_RenderCopy(sdl->ren, sdl->tex, NULL, NULL);
	//ft_printf("h = %d\n", (*sdl)->height);
	//ft_printf("w = %d\n", WIDTH);
	SDL_RenderPresent((*sdl)->ren);
	SDL_Delay(20);
		//SDL_Delay(4000);
	//SDL_DestroyRenderer(sdl->ren);
	//SDL_DestroyWindow(sdl->win);
//	SDL_Quit();
}
