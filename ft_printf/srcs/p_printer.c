/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:26:18 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/13 16:26:21 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print out what was written to the buffer and keep track of how many
** bytes were written out and add to g_ret. If there is an error, move
** g_ret back one.
*/ 

static void		p_print_the_wchar(char *buff)
{
	int		len;

	if ((len = write(g_fd, buff, ft_strlen(buff))) == -1)
		g_ret = -1;
	else
		g_ret += len;
}

/* 
** print out values that are not ascii (based off unsigned char)
** buffer will be up to length of 4 bytes. This handles whitecharacters
** also look for values that are not in ASCII table.
*/

static void		p_putwchar(wchar_t c)
{
	unsigned char	*buff;

	buff = (unsigned char*)ft_strnew(4);
	if (c <= 0x7F)
		buff[0] = (unsigned char)c;
	else if (c <= 0x7FF)
	{
		buff[0] = (unsigned char)((c >> 6) | 0xC0);
		buff[1] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		buff[0] = (unsigned char)((c >> 12) | 0xE0);
		buff[1] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		buff[2] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		buff[0] = (unsigned char)((c >> 18) | 0xF0);
		buff[1] = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		buff[2] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		buff[3] = (unsigned char)((c & 0x3F) | 0x80);
	}
	p_print_the_wchar((char*)buff);
	free(buff);
}

/*
** write out the pass in parameter output and keep track of the number
** of bytes written through g_ret. 
*/

/*
** print out the output and keep track of pointer location
*/

void			p_printer(char *output, wchar_t *woutput, size_t len)
{
	size_t	i;
	int		temp;

	if (output)
	{
		if ((temp = write(g_fd, output, len)) == -1)
			g_ret = -1;
		else
			g_ret += temp;
	}
	else
	{
		i = 0;
		while (i < len)
		{
			 p_putwchar(*woutput++);
			i++;
		}
	}
}

void			p_print_many_chars(char c, size_t n)
{
	char	*s;
	int		temp;

	if (!(s = ft_strnew(n)))
	{
		g_ret = -1;
		return ;
	}
	ft_memset(s, c, n);
	if ((temp = write(g_fd, s, n)) == -1)
		g_ret = -1;
	else
		g_ret += temp;
	free(s);
}
