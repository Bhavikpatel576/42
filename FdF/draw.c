/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:42:14 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 01:42:16 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define FOCAL_DISTANCE 200

void	redraw(t_window *window)
{
	transform_matrix(window, window->matrix);
	scale_matrix(window, window->matrix);
	trans_matrix(window, window->matrix);
	mlx_clear_window(window->mlx, window->win);
 	draw_projected(window, window->matrix);
}

void 	save_file_info(t_window *window, t_point *matrix)
{
	window->matrix = matrix;
}

void		draw_point(t_window *window, float x, float y)
{
	unsigned int	color;

	if (x > 0 && y > 0 && x < window->w_width && y < window->w_height)
	{
		color = window->color;
		mlx_pixel_put(window->mlx, window->win, x, y, color);
	}
}

void		drawline(t_window *window, t_3d point0, t_3d point1)
{
	float	delta[3];
	float	error;
	float	slope;
	int		dir;

	dir = swap_vars(&point0, &point1);
	delta[0] = point1.x - point0.x;
	delta[1] = point1.y - point0.y;
	delta[2] = point1.z - point0.z;
	slope = fabs(delta[1] / delta[0]);
	error = -1.0;
	while ((int)point0.x != (int)point1.x)
	{
		draw_point(window, dir ? point0.y : point0.x, dir ? point0.x : point0.y);
		error += slope;
		if (error >= 0.0)
		{
			point0.y += (point0.y > point1.y) ? -1.0 : 1.0;
			error -= 1.0;
		}
		point0.z += delta[2] / fabs(delta[0]);
		point0.x += (point0.x > point1.x) ? -1.0 : 1.0;
	}
}

void	draw_projected(t_window *window, t_point *matrix)
{
	int		y;
	int		x;

	y = -1;
	while (++y < matrix->height)
	{
		x = -1;
		while (++x < matrix->width)
		{
			if (x < matrix->width - 1)
				drawline(window, *(window->g_points[y][x].world),
						*(window->g_points[y][x + 1].world));
			if (y < matrix->height - 1)
				drawline(window, *(window->g_points[y][x].world),
						*(window->g_points[y + 1][x].world));
		}
	}
}