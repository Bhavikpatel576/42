/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:36:11 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/09 14:36:13 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <fdf.h>
#define BUF_SIZE = 1000 //initially an arbitrary value

// t_list	save_points(char *file_name)
// {


// }

char 	*read_file(char *file_name)
{
	char buf[BUF_SIZE + 1];
	int fd; // currently unknown, but will be provided with the function open
	int bytes_read;

	fd = open(file_name, O_RDONLY); 
	if (fd == -1)
	{
		ft_putstring('something wrong happened when you opened the file!')
		return (NULL);
	}
	bytes_read = read(fd, buf, BUF_SIZE);
}


int main(int argc, char *argv)
{
	char *file_name;
	char **line;
	const int fd;

	if (argc != 2)
		return (0);
	file_name = argv[argc - 1];

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, line);
	printf("%s\n", line);
}

// int main()
// {
// 	void *mlx;
// 	void *win;
// 	char *string =  "Test this function";
// 	int color = 0xffdead;
// 	int window_l = 1000;
// 	int window_w = 1000;
// 	int length = 0;
// 	int width = 0;
// 	int test_point_1 = 50;
// 	int test_point_2 = 50;
// 	int i = 0;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, window_l,window_w, "mlx 42");
// 	mlx_string_put(mlx,win,length,width,color,string);
// 	while (i < window_l/2)
// 	{
// 		mlx_pixel_put(mlx,win,test_point_1 + i,test_point_2, color);
// 		mlx_pixel_put(mlx,win,test_point_1,test_point_2 + i, color);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < window_w/2)
// 	{
// 		mlx_pixel_put(mlx,win,test_point_1 + window_w/2,test_point_2 + i, color);
// 		mlx_pixel_put(mlx,win,test_point_1 + i,test_point_2 + window_l/2, color);
// 		i++;
// 	}

// 	mlx_loop(mlx);
// 	return(0);
// }
