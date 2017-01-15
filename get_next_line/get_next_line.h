/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:25:51 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/19 22:27:09 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4
# define VAL p = ft_strchr(s[fd], '\n')
# define FD_PACK files.array[files.index]
# define PACK pack->array[pack->index]
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <libft.h>

int				get_next_line(const int fd, char **line);

#endif
