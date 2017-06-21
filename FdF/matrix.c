/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 23:53:43 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/14 23:53:46 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	mtx_bezero(float mat[4][4])
{
	ft_bzero(mat[0], sizeof(float) * 4);
	ft_bzero(mat[1], sizeof(float) * 4);
	ft_bzero(mat[2], sizeof(float) * 4);
	ft_bzero(mat[3], sizeof(float) * 4);
}

static void mtx_rotx(float mtx[4][4], float rot_x)
{
	mtx_bezero(mtx);
	mtx[0][0] = 1;
	mtx[1][1] = cos(rot_x);
	mtx[1][2] = sin(rot_x);
	mtx[2][1] = -sin(rot_x);
	mtx[2][2] = cos(rot_x);
	mtx[3][3] = 1;
}

static void mtx_roty(float mtx[4][4], float rot_y)
{
	mtx_bezero(mtx);
	mtx[0][0] = cos(rot_y);
	mtx[0][2] = sin(rot_y);
	mtx[1][1] = 1;
	mtx[2][0] = sin(rot_y);
	mtx[2][2] = cos(rot_y);
	mtx[3][3] = 1;
}

static void mtx_rotz(float mtx[4][4], float rot_z)
{
	mtx_bezero(mtx);
	mtx[0][0] = cos(rot_z);
	mtx[0][1] = sin(rot_z);
	mtx[1][0] = -sin(rot_z);
	mtx[1][1] = cos(rot_z);
	mtx[2][2] = 1;
	mtx[3][3] = 1;
}

void mtx_rotate(float mtx[4][4],float rot_x, float rot_y, float rot_z)
{
	float mtx_x[4][4];
	float mtx_y[4][4];
	float mtx_z[4][4];
	float mtx_1[4][4];
	float mtx_2[4][4];

	mtx_rotx(mtx_x,rot_x);
	mtx_mult(mtx,mtx_x,mtx_1);
	mtx_roty(mtx_y,rot_y);
	mtx_mult(mtx_1,mtx_y,mtx_2);
	mtx_rotz(mtx_z,rot_z);
	mtx_mult(mtx_2,mtx_z,mtx);
}