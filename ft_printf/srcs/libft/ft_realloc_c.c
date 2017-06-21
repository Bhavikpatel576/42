/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:17:54 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/13 16:21:15 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_c(char **s, char c)
{
	size_t	s_len;
	char	*s_ptr;
	char	*r_ptr;
	char	*result;

	if (!(*s))
		s_len = 0;
	else
		s_len = ft_strlen(*s);
	if ((result = ft_strnew(s_len + 1)) == NULL)
		return (NULL);
	s_ptr = *s;
	r_ptr = result;
	while (s_len--)
		*r_ptr++ = *s_ptr++;
	*r_ptr++ = c;
	ft_strdel(s);
	return (result);
}
