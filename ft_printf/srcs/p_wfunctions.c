/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_wfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:26:31 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/13 16:26:36 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_is_ascii(wchar_t *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] > 0x7F)
			return (0);
	return (1);
}

size_t	p_wide_dims_adj(t_flag *f)
{
	size_t	i;
	size_t	total;

	total = 0;
	i = 0;
	while (f->woutput[i])
	{
		if (f->woutput[i] <= 0x7F && ++i)
			total++;
		else if (f->woutput[i] <= 0x7FF && ++i)
			total += 2;
		else if (f->woutput[i] <= 0xFFFF && ++i)
			total += 3;
		else if (f->woutput[i] <= 0x10FFFF && ++i)
			total += 4;
		if (total > f->prec)
			break ;
	}
	return (--i);
}

size_t	p_wlen(wchar_t *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	p_wstrlen(wchar_t *s)
{
	size_t	i;
	size_t	total;

	total = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] <= 0x7F && ++i)
			total++;
		else if (s[i] <= 0x7FF && ++i)
			total += 2;
		else if (s[i] <= 0xFFFF && ++i)
			total += 3;
		else if (s[i] <= 0x10FFFF && ++i)
			total += 4;
	}
	return (total);
}
