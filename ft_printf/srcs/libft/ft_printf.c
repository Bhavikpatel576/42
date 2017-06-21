
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:23:35 by bpatel              #+#    #+#             */
/*   Updated: 2017/01/13 16:23:47 by bpatel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Completed Bonuses:
** handles standard n conversion
** handles standard * flag for width and precision
** added b conversion to convert unsigned numbers to binary
** added w conversion to change fd to print to a file after the conversion
*/

/*
** initialize struct and set flags to zero. While loop will write
**
*/

static int		p_initialize_flag(const char **format)
{
	t_flag	*flag;

	if (!(flag = (t_flag*)malloc(sizeof(t_flag))))
		return ((g_ret = -1));
	flag->width_f = 0;
	flag->width = 0;
	flag->prec_f = 0;
	flag->prec = 0;
	flag->wide_f = 0;
	flag->minus_f = 0;
	flag->plus_f = 0;
	flag->space_f = 0;
	flag->zero_f = 0;
	flag->hash_f = 0;
	flag->len_mod = 0;
	while (F(**format) || ft_isdigit(**format) || **format == '*' ||
			**format == '.' || L(**format))
		p_get_flag_info(format, flag);
	p_get_conv_spec(format, flag);
	free(flag);
	return (1);
}

/*
** read through the passed in string and identify percisions
*/

static void		p_start_to_write(const char **format)
{
	char	*perc_loc;
	int		temp;

	while (**format)
	{
		if (!(perc_loc = ft_strchr(*format, '%')))
		{
			temp = g_ret;
			p_printer((char*)*format, NULL, ft_strlen(*format));
			if (g_ret == -1)
				return ;
			*format += g_ret - temp;
		}
		else
		{
			temp = g_ret;
			p_printer((char*)*format, NULL, perc_loc - *format);
			if (g_ret == -1)
				return ;
			*format += g_ret - temp + 1;
			p_initialize_flag(format);
			if (g_ret == -1)
				return ;
		}
	}
}

/*
** we will pass in a char pointer 'format' of what to print out. Parsing format
** will allows us determine what type of format & precision we need, and
** how many arguments we need
*/

int				ft_printf(const char *format, ...)
{
	g_ret = 0;
	g_fd = 1;
	va_start(g_ap, format);
	p_start_to_write(&format);
	va_end(g_ap);
	return (g_ret);
}
