/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv_s_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:24:25 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/13 16:24:36 by bpate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		p_early_sign_width(t_flag *f)
{
	if (f->width_f && ((f->plus_f && *f->output != '-') ||
		(f->space_f && *f->output != '-') || (f->prec_f &&
		f->prec >= f->output_len)))
		f->width--;
	p_print_width(f);
	f->width_f = 0;
}

static char		*p_sign_handle(t_flag *f)
{
	char	*new_s;

	if (f->width_f && !f->minus_f && !f->zero_f &&
		(*f->output == '-' || f->plus_f || f->space_f))
		p_early_sign_width(f);
	if (*f->output == '-')
	{
		p_printer("-", NULL, 1);
		if (!(new_s = ft_strnew(--f->output_len)))
			return (NULL);
		if (ft_strcpy(new_s, f->output + 1) && f->width_f)
			f->width--;
		free(f->output);
		return (new_s);
	}
	else if (f->plus_f || f->space_f)
	{
		p_printer((f->plus_f) ? "+" : " ", NULL, 1);
		if (f->width_f)
			f->width--;
	}
	return (f->output);
}

static char		*p_handle_z_llong_min(intmax_t n)
{
	char	*ret;
	char	*temp;

	if (!(ret = ft_strnew(20)))
		return (NULL);
	ret[0] = '-';
	temp = p_imtoa_base(0, (size_t)n, 10, 0);
	ft_strcpy(ret + 1, temp);
	free(temp);
	return (ret);
}

static char		*p_get_s_str(char len_mod, intmax_t n)
{
	if (!len_mod)
		return (p_imtoa_base((int)n, 0, 10, 0));
	else if (len_mod == 'H')
		return (p_imtoa_base((signed char)n, 0, 10, 0));
	else if (len_mod == 'h')
		return (p_imtoa_base((short)n, 0, 10, 0));
	else if (len_mod == 'l')
		return (p_imtoa_base((long)n, 0, 10, 0));
	else if (len_mod == 'L')
		return (p_imtoa_base((long long)n, 0, 10, 0));
	else if (len_mod == 'j')
		return (p_imtoa_base(n, 0, 10, 0));
	else if (len_mod == 'z' && n > LLONG_MIN)
		return (p_imtoa_base(0, (size_t)n, 10, 0));
	else
		return (p_handle_z_llong_min(n));
}

void			p_conv_s_num(t_flag *f, intmax_t n)
{
	if (!(f->output = p_get_s_str(f->len_mod, n)))
	{
		g_ret = -1;
		return ;
	}
	f->output_len = ft_strlen(f->output);
	if (f->zero_f && NUM(f->c) && f->width_f && f->prec_f &&
		f->prec < f->width)
		f->zero_f = 0;
	if (!(f->output = p_sign_handle(f)))
	{
		g_ret = -1;
		return ;
	}
	p_apply_width(f);
	free(f->output);
}
