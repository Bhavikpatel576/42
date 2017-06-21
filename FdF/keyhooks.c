/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:05:18 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 16:05:19 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define ESC			53
#define UP			126
#define DOWN		125
#define RIGHT		124
#define LEFT		123
#define SHIFTRIGHT	2
#define SHIFTLEFT	0
#define SHIFTUP		13
#define SHIFTDOWN	1

int		key_hooks(int keycode, t_window *window)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == UP)
		window->rot_x += 5;
	else if (keycode == DOWN)
		window->rot_z += 5;
	else if (keycode == LEFT)
		window->rot_y += 5;
	else if (keycode == SHIFTRIGHT)
		window->shift_x += 5;
	else if (keycode == SHIFTLEFT)
		window->shift_x -= 5;
	else if (keycode == SHIFTUP)
		window->shift_y -= 5;
	else if (keycode == SHIFTDOWN)
		window->shift_y += 5;

	redraw(window);
	return (0);
}

void	run_fdf(t_window *window)
{
	mlx_key_hook(window->win, key_hooks, window);
	mlx_loop(window->mlx);
}