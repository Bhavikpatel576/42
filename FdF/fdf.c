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
#include <fcntl.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <fdf.h>

#define BSIZE 20

static void	save_points(char *file_name, t_point *matrix)
{
	char *line;
	char **line_to_copy;
	int fd;
	int output;
	int i;
	int j;

	output = 0;
	i = 0;
	j = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == - 1)
		ft_putstr("something went wrong with open");

	line = (char*)malloc(sizeof(char) * 4096);
	matrix = get_height_width(fd, &line, matrix);
	close(fd);
	fd = open(file_name, O_RDONLY);
	matrix->matrix_values = (char***)malloc(sizeof(char**) * matrix->height);
	while (i < matrix->height)
	{
		matrix->matrix_values[i] = (char**)malloc(sizeof(char*) * matrix->width);
		output = get_next_line(fd, &line);
		line_to_copy = ft_strsplit(line, ' ');
		while (j < matrix->width)
		{
			matrix->matrix_values[i][j] = line_to_copy[j];
			j++;
		}
		j = 0;
		i++;
	}
}

static void save_matrix_points(t_point *matrix, t_window *window)
{
	int i;
	int j;
	int z_value = 0;

	window->g_points = (t_vertex**)malloc(sizeof(t_vertex) * matrix->height);
	i = -1;
	while (++i < matrix->height)
	{
		window->g_points[i] = (t_vertex*)malloc(sizeof(t_vertex) * matrix->width);
		j = -1;
		while (++j < matrix->width)
		{
			z_value = atoi(matrix->matrix_values[i][j]);
			window->g_points[i][j] = *init_vertex(i,j,z_value);
		}
	}
}

int main(int argc, char **argv)
{
	char *file_name;
	t_point *matrix;
	t_window *window;

	if (argc != 2)
		return (0);
	file_name = argv[argc - 1];
	matrix = init();
	window = init_window();
	save_points(file_name, matrix);
	save_matrix_points(matrix, window);
	save_file_info(window,matrix);
	run_fdf(window);
	return(0);
}
