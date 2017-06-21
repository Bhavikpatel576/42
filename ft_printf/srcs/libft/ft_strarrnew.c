/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:17:54 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/13 16:21:15 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrnew(size_t size)
{
	char	**ptr;
	char	**result;

	if ((result = (char**)malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	ptr = result;
	while (size--)
		*ptr++ = 0;
	*ptr = 0;
	return (result);
}
