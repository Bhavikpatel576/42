Get Next Line leverages the Libft library to create a function that allows the client to retrieve a single line of a file passed in the standard input, each time it is called. The function will return 1 if successful, 0 if the entire project has been read, and -1 if an error occured. 


##Algorithm and Structure
The function will read the number of bytes based off the user's initialization of BUFF_SIZE. The function will continue to read the file and build up a string until a '\n' character in the file is found. The built up string will be returned.  

```C
while (!(SL) && (i = read(fd, buff, BUFF_SIZE)) > 0)
{
  buff[i] = '\0';
  join = string[fd];
  string[fd] = ft_strjoin(join, buff);
  ft_strdel(&join);
}
```

The pointer *line will point to the returned string and output a string that precedes the '\n' character. 
```C
if ((i = search(fd, buff, &*string)) == -1)
  return (-1);
*line = string[fd];
if (ft_strchr(string[fd], '\n'))
  *line = ft_strsub(string[fd], 0, S - string[fd]);
else
  *line = ft_strdup(string[fd]);
```
