/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:23:33 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 02:23:35 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_point *init(void)
{
	t_point *matrix;

	matrix = (t_point*)malloc(sizeof(t_point));
	matrix->height = 0;
	matrix->width = 0;
	matrix->matrix_values = NULL;
	return (matrix);
}

t_window *init_window(void)
{
	t_window *window;

	window = (t_window*)malloc(sizeof(t_window));
	window->w_height = WINDOW_HEIGHT;
	window->w_width = WINDOW_LENGTH;
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->w_height, window->w_width, "mlx 42");
	window->Xorigin = WINDOW_HEIGHT/2;
	window->Yorigin = WINDOW_LENGTH/2;
	window->color = 0xf0fff0;
	window->rot_x = 0;
	window->rot_y = 0;
	window->rot_z = 0;
	window->shift_x = WINDOW_HEIGHT/4;
	window->shift_y = WINDOW_LENGTH/4;
	window->matrix = init();
	return (window);
}

t_point *get_height_width(int fd, char **line, t_point *matrix)
{
	int height;
	int width;
	int x;
	
	x = 1;
	height = -1;
	while (x > 0)
	{
		x = get_next_line(fd, line);
		++height;
		if (x == 1) 
		{
			width = get_width(*line);
		}
	}
	matrix->width = width;
	matrix->height  = height;
	return (matrix);
}
