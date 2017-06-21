/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handle_conv_specs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:25:28 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/13 16:25:52 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		p_conv_n(t_flag *f)
{
	if (!f->len_mod)
		*va_arg(g_ap, int*) = g_ret;
	else if (f->len_mod == 'H')
		*va_arg(g_ap, signed char*) = g_ret;
	else if (f->len_mod == 'h')
		*va_arg(g_ap, short*) = g_ret;
	else if (f->len_mod == 'l')
		*va_arg(g_ap, long*) = g_ret;
	else if (f->len_mod == 'L')
		*va_arg(g_ap, long long*) = g_ret;
	else if (f->len_mod == 'j')
		*va_arg(g_ap, intmax_t*) = g_ret;
	else if (f->len_mod == 'z')
		*va_arg(g_ap, intmax_t*) = (size_t)g_ret;
}

static void		p_read_from_va_arg(t_flag *f)
{
	if (SN(f->c))
		p_conv_s_num(f, va_arg(g_ap, intmax_t));
	else if (UN(f->c))
		p_conv_u_num(f, va_arg(g_ap, uintmax_t));
	else if (f->c == 's' && f->len_mod == 'l')
		p_conv_wstr(f, va_arg(g_ap, wchar_t*));
	else if (f->c == 's')
		p_conv_str(f, va_arg(g_ap, char*));
	else if (f->c == 'c' && f->len_mod == 'l')
		p_conv_wchar(f, va_arg(g_ap, wchar_t));
	else if (f->c == 'c')
		p_conv_char(f, va_arg(g_ap, int));
	else if (f->c == 'n')
		p_conv_n(f);
	else if (f->c == 'w')
		g_fd = va_arg(g_ap, int);
	else
	{
		if (!(f->output = ft_strnew(1)))
			return ;
		f->output[0] = f->c;
		f->output_len = 1;
		p_apply_width(f);
		free(f->output);
	}
}

void			p_get_conv_spec(const char **fmt, t_flag *f)
{
	if (!**fmt)
		return ;
	if ((f->c = *(*fmt)++) && CAP(f->c))
	{
		f->c = ft_tolower(f->c);
		f->len_mod = 'l';
	}
	else if (f->c == 'p')
		f->len_mod = 'l';
	p_read_from_va_arg(f);
}
