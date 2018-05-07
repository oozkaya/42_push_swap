/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:38:25 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/07 12:53:26 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYER_H
# define DISPLAYER_H

# include "SDL.h"
# include "push_swap.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_stack t_stack;

typedef struct	s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	SDL_Event		ev;
	SDL_Rect		rect_a;
	SDL_Rect		rect_b;
	int				min;
	int				max;
	int				len;
	int				play;
	int				done;
	int				quit;
	Uint32			delay;
	int				autoplay;
	int				height;
}				t_sdl;

void			ft_displayer_init(t_sdl **sdl, t_stack *stack);
void			ft_displayer_free(t_sdl *sdl);
void			ft_display(t_sdl **sdl, t_stack *stack);


int				ft_sdl_events(t_sdl **sdl);

#endif
