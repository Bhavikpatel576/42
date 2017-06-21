/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv_c_and_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:24:02 by bpatel              #+#    #+#           */
/*   Updated: 2017/01/13 16:24:15 by bpatel             ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		p_char_zero(t_flag *f)
{
	f->output_len = 1;
	if (f->prec_f && f->zero_f)
		f->prec--;
	if (f->width_f && !f->minus_f)
		p_print_width(f);
	p_printer("\0", NULL, 1);
	if (f->width_f && f->minus_f)
		p_print_width(f);
}

void			p_conv_wstr(t_flag *f, wchar_t *s)
{
	if (s)
	{
		f->wide_f = 1;
		f->woutput = s;
		f->output_len = p_wstrlen(f->woutput);
		f->woutput_len = p_wlen(f->woutput);
		f->wide_dims_adj = p_wide_dims_adj(f);
		f->ascii_f = p_is_ascii(f->woutput);
		p_apply_width(f);
	}
	else
	{
		f->output = "(null)";
		f->output_len = 6;
		p_apply_width(f);
	}
}

void			p_conv_str(t_flag *f, char *s)
{
	if (s)
	{
		f->output = s;
		f->output_len = ft_strlen(s);
		p_apply_width(f);
	}
	else
	{
		f->output = "(null)";
		f->output_len = 6;
		p_apply_width(f);
	}
}

void			p_conv_wchar(t_flag *f, wchar_t n)
{
	if (n == 0)
	{
		p_char_zero(f);
		return ;
	}
	f->wide_f = 1;
	if (!(f->woutput = (wchar_t*)malloc(sizeof(wchar_t) * 2)))
	{
		g_ret = -1;
		return ;
	}
	f->woutput[0] = n;
	f->woutput[1] = '\0';
	f->output_len = p_wstrlen(f->woutput);
	f->woutput_len = 1;
	f->wide_dims_adj = p_wide_dims_adj(f);
	f->ascii_f = p_is_ascii(f->woutput);
	p_apply_width(f);
	free(f->woutput);
}

void			p_conv_char(t_flag *f, int n)
{
	if (n == 0)
	{
		p_char_zero(f);
		return ;
	}
	if (!(f->output = ft_strnew(1)))
	{
		g_ret = -1;
		return ;
	}
	f->output[0] = n;
	f->output_len = 1;
	p_apply_width(f);
	free(f->output);
}
