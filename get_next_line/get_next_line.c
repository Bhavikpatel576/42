/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:24:47 by bpatel            #+#    #+#             */
/*   Updated: 2016/12/19 23:01:32 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 2

/* 
** Niave Algo - will read in the file based off the number of bytes. Will search 
** the buffer to find a new line. If found it will return the location of the char
** before the newline else it will continue to search at the last location.
**
*/

int	open_file_read_only(char *filename)
{
	int fd;
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_putstr("Open error");
	return (fd);
}

static void prep_line(char **temp, char **line)
{
	char *return_line;
	int linelength;

	linelength = ft_strlen(*temp) - ft_strlen(ft_strchr(*temp, '\n'));
	return_line = ft_strdupn(*temp, linelength);
	*line = return_line;
}

int get_next_line(const int fd, char **line)
{
	char *temp = NULL;
	char buf[BUFFSIZE + 1];
	static char *copyline = NULL;
	int rf = 0;

	temp = ft_strdup("");
	if (copyline)
	{
		temp = ft_strdup(&ft_strchr(copyline, '\n')[1]); //might need to check for new line in here
		copyline = &ft_strchr(copyline, '\n')[1];
	}
	while (!ft_strchr(buf, '\n') && (rf = read(fd,buf,BUFFSIZE)))
	{
		copyline = ft_strdup(buf);
		temp = ft_strjoin(temp, copyline);
	}
	//printf("%s %s\n",temp,copyline);
	prep_line(&temp, line);
	free(temp);
	return (rf);
}

int main(int argc, char *argv[])
{
	char *filename;
	char *line;
	int fd;
	int v;

	if (argc != 2)
		return 0;
	filename = argv[argc - 1];
	fd = open_file_read_only(filename);
	if (fd == -1)
	{
		printf("%s\n", "Open failed");
		close(fd);
	}
	v = get_next_line(fd, &line);
	printf("First call: %s", line);
	free(line);
	v = get_next_line(fd, &line);
	printf("Second call: %s", line);
	free(line);
	v = get_next_line(fd, &line);
	printf("third call: %s", line);
	return (0);
}

