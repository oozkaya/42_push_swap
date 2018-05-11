/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:56:27 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/11 12:17:14 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_window_background(t_sdl **sdl)
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

void		ft_display_stacks(t_sdl **sdl, t_stack *stack, char c)
{
	t_elem		*tmp;
	SDL_Rect	stick;

	if (c == 'a')
		tmp = stack->a;
	else
		tmp = stack->b;
	stick.h = (*sdl)->height / (*sdl)->len;
	stick.y = 0 - stick.h;
	while (tmp)
	{
		stick.w = (WIDTH / 2) *
					(tmp->nbr == 0 ? 0.4 : ft_abs(tmp->nbr)) / (*sdl)->max;
		if (c == 'a')
			stick.x = WIDTH / 4 - stick.w / 2;
		else
			stick.x = WIDTH / 2 + WIDTH / 4 - stick.w / 2;
		stick.y += stick.h;
		ft_display_stick(sdl, tmp->nbr, stick, c);
		tmp = tmp->next;
	}
}
