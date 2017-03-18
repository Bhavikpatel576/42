/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:53:54 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/17 20:53:56 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	*transform_matrix(t_window *window, t_point *matrix)
{
	int x;
	int y;
	float mtx[4][4];

	x = -1;
	get_id_matrix(mtx);
	mtx_rotate(mtx, window->rot_x, window->rot_y, window->rot_z);

	while (++x < matrix->height)
	{
		y = -1;
		while (++y < matrix->width)
		{
			vec_mtx_mult(window->g_points[x][y].local, mtx, window->g_points[x][y].world);
		}
	}
	return (window->g_points);
}

void	*scale_matrix(t_window *window, t_point *matrix)
{
	int x;
	int y;
	float mtx[4][4];

	x = -1;
	mtx_scal(mtx ,30);
	while (++x < matrix->height)
	{
		y = -1;
		while (++y < matrix->width)
		{
			vec_mtx_mult(window->g_points[x][y].local, mtx, window->g_points[x][y].world);
		}
	}
	return (window->g_points);
}

void	*trans_matrix(t_window *window, t_point *matrix)
{
	int x;
	int y;

	x = -1;
	while (++x < matrix->height)
	{
		y = -1;
		while (++y < matrix->width)
		{
			window->g_points[x][y].world->x += window->shift_x;
			window->g_points[x][y].world->y += window->shift_y;
		}
	}
	return (window->g_points);
}


