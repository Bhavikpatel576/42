/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:51:44 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/17 20:51:46 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

double ft_abs(double value)
{
	if (value < 0)
	{
		value = -value;
	}
	return value;
}

int get_width(char *line)
{
	int width;

	width = 0;
	while (*line != '\0')
	{
		if (*line != ' ' && *line != '+' && *line != '-')
			width++;
		line++;
	}
	return (width);
}

int	swap_vars(t_3d *point0, t_3d *point1)
{
	float temp;

	if (fabs(point1->x - point0->x) > fabs(point1->y - point0->y))
		return (0);
	temp = point0->y;
	point0->y = point0->x;
	point0->x = temp;
	temp = point1->y;
	point1->y = point1->x;
	point1->x = temp;
	return (1);
}
