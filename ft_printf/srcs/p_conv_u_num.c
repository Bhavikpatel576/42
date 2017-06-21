/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv_u_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:24:45 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/13 16:24:47 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				handle_hash(t_flag *f, uintmax_t n)
{
	char	*new_s;
	int		adj;

	if (f->c == 'p' || (f->hash_f && HASH(f->c)))
	{
		if (n == 0 && (f->c == 'x' || f->c == 'X'))
			return (1);
		adj = (f->c == 'o') ? 1 : 2;
		if (!(new_s = ft_strnew(f->output_len + adj)))
			return (0);
		new_s[0] = '0';
		if (f->c == 'x' || f->c == 'p')
			new_s[1] = 'x';
		else if (f->c == 'X')
			new_s[1] = 'X';
		if (n != 0 || (f->c == 'p' && (!f->prec_f ||
			(f->prec_f && f->prec != 0))))
			ft_strcpy(new_s + adj, f->output);
		else
			f->output_len--;
		free(f->output);
		f->output = new_s;
		f->output_len += adj;
	}
	return (1);
}

static unsigned int		p_get_base(t_flag *f)
{
	unsigned int	base;

	base = 10;
	if (f->c == 'o')
		base = 8;
	else if (f->c == 'x' || f->c == 'X' || f->c == 'p')
		base = 16;
	else if (f->c == 'b')
		base = 2;
	return (base);
}

static char				*p_get_u_str(t_flag *f, uintmax_t n,
										unsigned int base, int cap)
{
	if (!f->len_mod)
		return (p_imtoa_base(0, (unsigned int)n, base, cap));
	else if (f->len_mod == 'H')
		return (p_imtoa_base(0, (unsigned char)n, base, cap));
	else if (f->len_mod == 'h')
		return (p_imtoa_base(0, (unsigned short)n, base, cap));
	else if (f->len_mod == 'l')
		return (p_imtoa_base(0, (unsigned long)n, base, cap));
	else if (f->len_mod == 'L')
		return (p_imtoa_base(0, (unsigned long long)n, base, cap));
	else if (f->len_mod == 'j')
		return (p_imtoa_base(0, n, base, cap));
	else
		return (p_imtoa_base(0, (size_t)n, base, cap));
}

void					p_conv_u_num(t_flag *f, uintmax_t n)
{
	f->output = p_get_u_str(f, n, p_get_base(f),
								(f->c == 'X') ? 1 : 0);
	if (!f->output)
	{
		g_ret = -1;
		return ;
	}
	if (f->zero_f && NUM(f->c) && f->width_f && f->prec_f &&
		f->prec < f->width)
		f->zero_f = 0;
	f->output_len = ft_strlen(f->output);
	if (!(handle_hash(f, n)))
	{
		g_ret = -1;
		free(f->output);
		return ;
	}
	p_apply_width(f);
	free(f->output);
}
