/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 00:31:21 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 00:31:25 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//you need to understand how this mtx mulp works
void mtx_mult(float mtx1[4][4], float mtx2[4][4], float dest[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			dest[i][j] = mtx1[i][0] * mtx2[0][j] +
						 mtx1[i][1] * mtx2[1][j] +
						 mtx1[i][2] * mtx2[2][j] +
						 mtx1[i][3] * mtx2[3][j];
		}
	}
}

void vec_mtx_mult(t_3d *src,float mtx[4][4],t_3d *dest)
{
	dest->x = src->x * mtx[0][0] + src->y * mtx[1][0] + src->z * mtx[2][0] + mtx[3][0];
	dest->y = src->x * mtx[0][1] + src->y * mtx[1][1] + src->z * mtx[2][1] + mtx[3][1];
	dest->z = src->x * mtx[0][2] + src->y * mtx[1][2] + src->z * mtx[2][2] + mtx[3][2];

}

void mtx_tran(float mtx[4][4], float x, float y, float z)
{
	float src[4][4];
	mtx_bezero(src);
	mtx[0][0] = 1;
	mtx[1][1] = 1;
	mtx[2][2] = 1;
	src[3][3] = 1;
	src[3][0] = x;
	src[3][1] = y;
	src[3][2] = z;
	mtx_mult(mtx,src,mtx);
}

void mtx_scal(float mtx[4][4], float b)
{
	float src[4][4];
	mtx_bezero(src);
	src[0][0] = b;
	src[1][1] = b;
	src[2][2] = b;
	src[3][3] = 1;
	mtx_mult(mtx, src, mtx);
}

void	get_id_matrix(float mat[4][4])
{
	mtx_bezero(mat);
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
}