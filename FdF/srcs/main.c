/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:36:11 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/09 14:36:13 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <fcntl.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <fdf.h>
#define ESC			53
#define UP			126
#define DOWN		125
#define RIGHT		124
#define LEFT		123

int		key_hooks(int keycode, void *param)
{
	printf("esc");
	return (0);
}

int main(int argc, char **argv)
{
	void *mlx;
	void *win;
	int i;
	int j;
	int offsetx = 400;
	int offsety = 400;
	int dbl = 20;
	int color = 0xf0fff0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "mlx 42");
	i = -1;
	while (++i < 100)
	{
		j = -1;
		while(++j < 100)
		{
			mlx_pixel_put(mlx,win,(i*dbl)+offsetx,(j*dbl)+offsety,color);
		}

	}

	mlx_key_hook(win, key_hooks, 0);
	mlx_loop(win);

	
	return(0);
}

