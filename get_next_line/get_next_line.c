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
#define BUFFSIZE 1

/* 
** Niave Algo - will read in the file based off the number of bytes. Will search 
** the buffer to find a new line. If found it will return the location of the char
** before the newline else it will continue to search at the last location.
**
*/

/*
int get_next_line(const int fd, char **line)
{
//fd will be file to read
//char **line is the address to the line being read
//return value is 1,0,-1: read, complete, error 
//return value w/o '\n' 
}
*/

/*  1. Call the read function, search within the buf to see if '\n'
	2. If so, call another function to see what point in the string. 
	3. allocate memory. copy over the string, and concatinate the with orig string
*/

char buf[BUFFSIZE];

int	open_file_read_only(char *filename)
{
	int fd;
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_putstr("Open error");
	return (fd);
}

char *readfile(int fd)
{
	char *line;
	char *copyline; 
	int rf;
	int length = 0;
	int test = 0;

	line = ft_strdup("");
	copyline = ft_strdup("");
	while (test == 0)
	{
		rf = read(fd, buf, BUFFSIZE);
		while (length <= BUFFSIZE)
		{
			if (buf[length] == '\n')
			{
				test = 1;
				break;
			}
			length++;
		}
		copyline = ft_strdupn(buf, length);
		length = 0;
		line = ft_strjoin(line, copyline);
	}
	return (line);
}

int main(int argc, char *argv[])
{
	char *filename;
	char *output;
	int fd;

	if (argc != 2)
		return 0;
	filename = argv[argc - 1];

	fd = open_file_read_only(filename);
	if (fd == -1)
		printf("%s\n", "Open failed");
	output  = readfile(fd);
	printf("%s", output);
	return (0);
}

