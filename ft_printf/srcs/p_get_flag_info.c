/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_get_flag_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:25:03 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/13 16:25:08 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Function will handle the length specifier for h l L j z
*/

static void		p_get_length_spec(const char **fmt, t_flag *f)
{
	if (**fmt == 'h' && f->len_mod < 'h' && f->len_mod != 'L')
	{
		f->len_mod = *(*fmt)++;
		if (**fmt == 'h')
		{
			f->len_mod = 'H';
			(*fmt)++;
		}
	}
	else if (**fmt == 'l' && f->len_mod < 'l' && f->len_mod != 'j')
	{
		f->len_mod = *(*fmt)++;
		if (**fmt == 'l')
		{
			f->len_mod = 'L';
			(*fmt)++;
		}
	}
	else if (**fmt == 'j' && (f->len_mod < 'j' ||
									f->len_mod == 'l'))
		f->len_mod = *(*fmt)++;
	else if (**fmt == 'z')
		f->len_mod = *(*fmt)++;
	else
		(*fmt)++;
}

/*
** return the length of the formated string when flag is an asterisk
** flag is initialized if 'w' to handle minus values in the format string
*/

static size_t	p_abs(t_flag *f, int n, char c)
{
	if (n < 0 && c == 'w')
	{
		f->minus_f = 1;
		return (n * -1);
	}
	else if (n < 0)
	{
		f->prec_f = 0;
		return (0);
	}
	return (n);
}

/*
** Input takes in the formatted string and the struct to assign values
** trigger the type of flag and keep track of the length of the format
** string and move the pointer forward after
*/

static void		p_get_width(const char **fmt, t_flag *f)
{
	while (ft_isdigit(**fmt) || **fmt == '*')
	{
		if (ft_isdigit(**fmt))
		{
			f->width_f = 1;
			f->width = ft_atoi(*fmt);
			while (ft_isdigit(**fmt))
				(*fmt)++;
		}
		if (**fmt == '*')
		{
			f->width_f = 1;
			f->width = p_abs(f, va_arg(g_ap, int), 'w');
			(*fmt)++;
		}
	}
}

/*
** if the string format value is a period, initialize the precision
** flag. the precision specifies the minimum number of digits to be written 
*/

static void		p_get_prec(const char **fmt, t_flag *f)
{
	f->prec_f = 1;
	(*fmt)++;
	f->prec = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
	if (**fmt == '*' && (*fmt)++)
		f->prec = p_abs(f, va_arg(g_ap, int), 'p');
}

/*
** initialize the type of flag the format string has. Struct value
** will be initialized to 1 if value is present and 0 if not. Helper
** functions get_width, get_prec, and get_length_spec additionally
** trigger flags and move pointer values
*/

void			p_get_flag_info(const char **fmt, t_flag *f)
{
	if (F(**fmt))
	{
		if (**fmt == '-')
			f->minus_f = 1;
		else if (**fmt == '+')
			f->plus_f = 1;
		else if (**fmt == ' ')
			f->space_f = 1;
		else if (**fmt == '0')
			f->zero_f = 1;
		else if (**fmt == '#')
			f->hash_f = 1;
		(*fmt)++;
	}
	else if (ft_isdigit(**fmt) || **fmt == '*')
		p_get_width(fmt, f);
	else if (**fmt == '.')
		p_get_prec(fmt, f);
	else
		p_get_length_spec(fmt, f);
}
