/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:12:42 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/10 16:59:38 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_delay(t_sdl **sdl)
{
	if ((*sdl)->ev.key.keysym.scancode == SDL_SCANCODE_KP_1)
		return (1000);
	if ((*sdl)->ev.key.keysym.scancode == SDL_SCANCODE_KP_2)
		return (100);
	if ((*sdl)->ev.key.keysym.scancode == SDL_SCANCODE_KP_3)
		return (30);
	if ((*sdl)->ev.key.keysym.scancode == SDL_SCANCODE_KP_4)
		return (15);
	if ((*sdl)->ev.key.keysym.scancode == SDL_SCANCODE_KP_5)
		return (7);
	if ((*sdl)->ev.key.keysym.scancode == SDL_SCANCODE_KP_6)
		return (1);
	return (100);
}

static void	ft_poll_events(t_sdl **sdl, int *run)
{
	if ((*sdl)->ev.type == SDL_KEYDOWN)
	{
		if ((*sdl)->ev.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			*run = 1;
		(*sdl)->quit |= (*sdl)->ev.key.keysym.scancode
				== SDL_SCANCODE_ESCAPE || SDL_QuitRequested();
		(*sdl)->delay = ft_delay(sdl);
		if ((*sdl)->ev.key.keysym.scancode == SDL_SCANCODE_SPACE
															&& (*sdl)->play)
			(*sdl)->play = 0;
		if ((*sdl)->ev.key.keysym.scancode == SDL_SCANCODE_KP_ENTER
															&& !(*sdl)->play)
			(*sdl)->play = 1;
	}
	if ((*sdl)->ev.type == SDL_QUIT)
		(*sdl)->quit = 1;
}

void		ft_display(t_sdl **sdl, t_stack *stack)
{
	int		run;

	SDL_RenderClear((*sdl)->ren);
	ft_window_background(sdl);
	ft_display_stacks(sdl, stack, 'a');
	ft_display_stacks(sdl, stack, 'b');
	SDL_RenderPresent((*sdl)->ren);
	run = 0;
	while (!run && !(*sdl)->quit)
	{
		while (SDL_PollEvent(&(*sdl)->ev) != 0)
			ft_poll_events(sdl, &run);
		run |= ((*sdl)->play || (*sdl)->quit);
	}
	SDL_Delay((*sdl)->delay);
	if (stack_is_sorted(stack->a) && !stack->b)
	{
		while (SDL_WaitEvent(&(*sdl)->ev) != 0 && !(*sdl)->quit)
		{
			(*sdl)->quit |= (*sdl)->ev.key.keysym.scancode
						== SDL_SCANCODE_ESCAPE || SDL_QuitRequested();
			if ((*sdl)->ev.type == SDL_QUIT)
				(*sdl)->quit = 1;
		}
	}
}
