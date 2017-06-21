/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:17:54 by bpatel              #+#    #+#             */
/*   Updated: 2017/01/13 16:21:15 by bpatel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define LLONG_MAX 9223372036854775807
# define LLONG_MIN -9223372036854775807
# define F(x) (x=='-'||x=='+'||x==' '||x=='0'||x=='#')
# define L(x) (x=='h'||x=='l'||x=='j'||x=='z')
# define SN(x) (x=='d'||x=='i')
# define UN(x) (x=='o'||x=='u'||x=='x'||x=='X'||x=='b'||x=='p')
# define CAP(x) (x=='D'||x=='O'||x=='U'||x=='S'||x=='C')
# define NUM(x) (x=='d'||x=='i'||x=='o'||x=='u'||x=='x'||x=='X'||x=='b'||x=='p')
# define STR(x) (x=='s'||x=='c')
# define HASH(x) (x=='o'||x=='x'||x=='X'||x=='p')

/*
** struct to keep track of key information to determine what to print out
** for example flag management, if a precision is needed,
**
** 
** type wchar_t is used for unicode characters. Unlike type char, which
** uses characters that are part of the ASCII character set.
*/

typedef struct	s_flag
{
	char		c;
	char		len_mod;
	char		*output;
	wchar_t		*woutput;
	int			wide_f;
	int			minus_f;
	int			plus_f;
	int			space_f;
	int			zero_f;
	int			hash_f;
	int			ascii_f;
	int			width_f;
	int			prec_f;
	size_t		wide_dims_adj;
	size_t		woutput_len;
	size_t		width;
	size_t		output_len;
	size_t		prec;
}				t_flag;

int				ft_printf(const char *format, ...);
void			p_conv_wstr(t_flag *flag, wchar_t *s);
void			p_conv_str(t_flag *flag, char *s);
void			p_conv_wchar(t_flag *flag, wchar_t n);
void			p_conv_char(t_flag *flag, int n);
void			p_conv_s_num(t_flag *flag, intmax_t n);
void			p_conv_u_num(t_flag *flag, uintmax_t n);
void			p_get_flag_info(const char **format, t_flag *flag);
void			p_get_conv_spec(const char **format, t_flag *flag);
void			p_conv_char(t_flag *flag, int n);
void			p_conv_wchar(t_flag *flag, wchar_t n);
void			p_conv_str(t_flag *flag, char *s);
void			p_conv_wstr(t_flag *flag, wchar_t *s);
char			*p_imtoa_base(intmax_t im, uintmax_t um,
								unsigned int base, int c);
size_t			p_wstrlen(wchar_t *s);
size_t			p_wlen(wchar_t *s);
size_t			p_wide_dims_adj(t_flag *flag);
int				p_is_ascii(wchar_t *s);
void			p_apply_width(t_flag *flag);
void			p_print_width(t_flag *flag);
void			p_print_many_chars(char c, size_t n);
void			p_printer(char *output, wchar_t *woutput, size_t len);

int				g_fd;
int				g_ret;
va_list			g_ap;

#endif
