/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:24:47 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/12 17:45:26 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static void		prep_line(char **temp, char **line)
{
	char		*return_line;
	int			linelength;

	linelength = ft_strlen(*temp) - ft_strlen(ft_strchr(*temp, '\n'));
	return_line = ft_strdupn(*temp, (linelength + 1));
	return_line[linelength] = '\0';
	*line = return_line;
}

int				get_next_line(const int fd, char **line)
{
	char		*temp;
	char		buf[BUFF_SIZE + 1];
	static char *copyline = NULL;
	int			rf;
	char 		*test;

	ft_bzero(buf, BUFF_SIZE + 1);
	temp = NULL;
	temp = ft_strdup("");
	if (fd < 0 || !line || read(fd, buf, 0))
		return (-1);
	if (copyline)
	{
		temp = ft_strdup(&ft_strchr(copyline, '\n')[1]);
	}
	while (!(test = ft_strchr(buf, '\n')) && (rf = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rf] = '\0';
		//printf("buf:%s\n", buf);
		copyline = ft_strdup(buf);
		//printf("temp:%s\n", temp);
		temp = ft_strjoin(temp, copyline);
	}
	//printf("copyline:%s\n temp:%s\n\n\n",copyline,temp);
	if (rf > 0)
		prep_line(&temp, line);
	if (rf == 0)
	{
		*line = temp;
		return (0);
	}
	//free(temp);
	return (1);
}

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		res;

	if (argc != 2 || !argv[0])
		return (1);
	
	res = 0;
	
	fd = open(argv[1], O_RDONLY);
	
	if ((fd) > 0)
		while ((res = get_next_line(fd, &line)) > 0)
			printf("Res: %d, Line: %s\n", res, line);
	
	if (res == 0)
		printf("Res: %d, Line: %s\n", res, line);
	
	if ((fd > 0 && (close(fd) == -1 || res != 0)) || fd < 0)
	{
		if (!line)
			write(1, "error\n", 6);
		return (1);
	}
}