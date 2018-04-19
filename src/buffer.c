/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 09:27:31 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/20 20:53:25 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initializes the buffer with a size equal to BUFFER_SIZE
** that can be modified in the "push_swap.h" header
**
** Return : void
*/

void	init_buffer(t_buff **buf)
{
	if (!(*buf = malloc(sizeof(t_buff*))))
		return ;
	if (!((*buf)->str = malloc(sizeof(char) * BUFFER_SIZE)))
		return ;
	(*buf)->index = 0;
	(*buf)->len = 0;
}

/*
** Adds a string in the buffer as big as the given "size"
** Thus a "size" smaller than the string's size will cut the string
** If BUFFER_SIZE is exceeded, we double the size of the buffer
**
** Return : void
*/

void	add_buffer(t_buff **buf, char *str, size_t size)
{
	size_t	new_size;

	if (((*buf)->index + size) >= BUFFER_SIZE)
	{
		new_size = BUFFER_SIZE;
		while (((*buf)->index + size) >= new_size)
			new_size *= 2;
		if (!((*buf)->str = ft_realloc((*buf)->str, new_size)))
			return ;
	}
	ft_memmove((*buf)->str + (*buf)->index, str, size);
	(*buf)->index += size;
	(*buf)->len += size;
	(*buf)->str[(*buf)->index] = '\0';
}
