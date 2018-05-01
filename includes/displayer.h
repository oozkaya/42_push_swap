/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:38:25 by oozkaya           #+#    #+#             */
/*   Updated: 2018/05/01 21:51:16 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYER_H
# define DISPLAYER_H

# include "SDL.h"

# define WIDTH 1920
# define HEIGHT 1080

//# define WIDTH (*sdl)->width
//# define HEIGHT (*sdl)->height

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
	int				done;
	int				quit;
	int				delay;
	int				autoplay;
	int				height;
}				t_sdl;

void	ft_displayer_init(t_sdl **sdl, t_stack *stack);
void	ft_display(t_sdl **sdl, t_stack *stack);


int		ft_sdl_events(t_sdl **sdl);

#endif
