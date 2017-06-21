/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:58:37 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/09 18:01:39 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <libft.h>
#include <stdio.h>
#include <mlx.h>
#include <fcntl.h>
#include <math.h>

# define WINDOW_HEIGHT 1250
# define WINDOW_LENGTH 800

typedef struct s_point
{
	int 	height;
	int 	width;
	char	***matrix_values;
}				t_point;

typedef struct s_2d
{
	int x;
	int y;
}				t_2d;

typedef struct s_3d
{
	float x;
	float y;
	float z;
}				t_3d;

typedef struct s_vertex
{
	t_3d *local;
	t_3d *world;
	t_3d *aligned;
}				t_vertex;

typedef struct s_window
{
	int 	w_height;
	int 	w_width;
	void	*mlx;
	void	*win;
	t_vertex **g_points;
	int 	Xorigin;
	int 	Yorigin; 
	int 	color;
	float 	rot_x;
	float 	rot_y;
	float 	rot_z;
	float 	shift_x;
	float 	shift_y;
	t_point	*matrix;
	
}				t_window;

//draw.c
void	redraw(t_window *window);
void 	save_file_info(t_window *window, t_point *matrix);
void		draw_point(t_window *window, float x, float y);
void		drawline(t_window *window, t_3d point0, t_3d point1);
void	draw_projected(t_window *window, t_point *matrix);

//helper_func
double ft_abs(double value);
int get_width(char *line);
int	swap_vars(t_3d *point0, t_3d *point1);

void	*trans_matrix(t_window *window, t_point *matrix);
void	*scale_matrix(t_window *window, t_point *matrix);
void	*transform_matrix(t_window *window, t_point *matrix);

//mtx_mult
void mtx_mult(float mtx1[4][4], float mtx2[4][4], float dest[4][4]);
void vec_mtx_mult(t_3d *src,float mtx[4][4],t_3d *dest);
void mtx_tran(float mtx[4][4], float x, float y, float z);
void mtx_scal(float mtx[4][4], float b);
void	get_id_matrix(float mat[4][4]);

//matrix.c
void mtx_rotate(float mtx[4][4],float rot_x, float rot_y, float rot_z);
void mtx_bezero(float mat[4][4]);

//init files
t_point *init(void);
t_window *init_window(void);
t_point *get_height_width(int fd, char **line, t_point *matrix);
t_3d *init_mtx(float x, float y, float z);
t_vertex *init_vertex(float x, float y, float z);

//draw.c
void	draw_a_line_horiz(t_3d *point1, t_3d *point2, t_window *window);
void	draw_a_line_vert(int x1, int y1, int x2, int y2, t_window *window);
void	draw_grid_points(t_point *matrix, t_window *window);
void project(t_vertex *vertex);

//keyhooks.c
int	my_key_funct(int keycode, void *param);
void	run_fdf(t_window *window);

#endif
