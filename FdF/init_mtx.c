/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mtx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:23:44 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 02:23:46 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_3d *init_mtx(float x, float y, float z)
{
	t_3d *temp;

	temp = (t_3d*)malloc(sizeof(t_3d));
	temp->x = x; 
	temp->y = y;
	temp->z = z;
	return (temp);
}

t_vertex *init_vertex(float x, float y, float z)
{
	t_vertex *temp;

	temp = (t_vertex*)malloc(sizeof(t_vertex));
	temp->local = init_mtx(x,y,z);
	temp->world = init_mtx(0,0,0);
	temp->aligned = init_mtx(0,0,0);
	return (temp);
}