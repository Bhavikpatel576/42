/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_width_and_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:26:54 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/13 16:26:59 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		p_prec_hash(t_flag *f)
{
	char	*new_s;
	int		temp;

	if (f->c == 'p' || (f->hash_f && *(f->output + 1)))
	{
		if ((temp = write(g_fd, f->output, (f->c == 'o' ? 1 : 2))) == -1
			|| !(new_s = ft_strnew((f->output_len -= temp))))
			g_ret = -1;
		else
		{
			if ((f->c == 'p' || f->c == 'x' || f->c == 'X') &&
				f->width_f)
				f->width -= temp;
			g_ret += temp;
			ft_strcpy(new_s, f->output + temp);
			free(f->output);
			f->output = new_s;
			if (f->c == 'o' && f->prec_f)
				f->prec--;
			f->hash_f = 0;
		}
	}
}

static void		p_apply_precision(t_flag *f)
{
	if (NUM(f->c) && f->prec_f && f->prec > f->output_len)
	{
		HASH(f->c) ? p_prec_hash(f) : 1;
		p_print_many_chars('0', f->prec - f->output_len);
		if (g_ret != -1)
			p_printer(f->output, NULL, f->output_len);
	}
	else if (NUM(f->c) && ((f->c == 'o' && f->hash_f) ||
				(*f->output != '0' || *(f->output + 1))))
		p_printer(f->output, NULL, f->output_len);
	else if ((STR(f->c) || NUM(f->c)) && f->prec_f &&
				f->prec < f->output_len)
	{
		if (f->wide_f)
			p_printer(NULL, f->woutput, f->wide_dims_adj);
		else
			p_printer(f->output, NULL, f->prec);
	}
	else
	{
		if (f->wide_f)
			p_printer(NULL, f->woutput, f->woutput_len);
		else
			p_printer(f->output, NULL, f->output_len);
	}
}

void			p_apply_width(t_flag *f)
{
	if ((f->c == 'p' || f->c == 'x' || f->c == 'X') && f->zero_f)
		p_prec_hash(f);
	if (f->width_f && !f->minus_f)
		p_print_width(f);
	p_apply_precision(f);
	if (f->width_f && f->minus_f)
		p_print_width(f);
}

/*
** Print out the width of the information?
*/

void			p_print_width(t_flag *f)
{
	size_t	len;
	size_t	width;

	len = f->output_len;
	if (STR(f->c))
	{
		if (f->wide_f && !f->ascii_f)
			len = ((f->prec_f && f->prec - f->wide_dims_adj < len) ?
					f->prec - f->wide_dims_adj : len);
		else
			len = ((f->prec_f && f->prec < len) ? f->prec : len);
	}
	else
		len = ((f->prec_f && f->prec > len) ? f->prec : len);
	width = f->width + ((NUM(f->c) && f->c != 'p' &&
			!*(f->output + 1) && f->prec_f && !f->prec &&
			!f->plus_f && !f->space_f && !f->zero_f) ? 1 : 0);
	if (len < width)
		p_print_many_chars((!f->minus_f && f->zero_f) ? '0' : ' ',
							width - len);
}
