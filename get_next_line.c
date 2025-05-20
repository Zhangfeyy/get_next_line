/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:17:11 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/15 22:17:13 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//read lines till a new line appears
char	*read_file(unsigned char *temp, int fd)
{
	unsigned char *buffer;
	unsigned char *ttemp;
	size_t length;

	// create a buffer
	buffer = (unsigned char*)ft_calloc(BUFFER_SIZE + 1); // treat it as a string
	if(!buffer)
		return(NULL);
	temp = buffer;
	while(!ft_strchr(temp, '\n'))
	{
		length = read(fd, buffer, BUFFER_SIZE);
		if(length == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[length] = '\0';
		temp = ft_strjoin(temp, buffer);
		if(length == 0)
		{
			free(buffer);
			return(temp);
		}
	}
	free(buffer);
	return (temp);
}

char *read_line(unsigned char *temp)
{
	if(!temp)
		return(NULL);
	return(temp);
}




char	*get_next_line(int fd)
{
	static unsigned char *temp;
	unsigned char *line;

	if(BUFFER_SIZE <= 0 || fd < 0) // 0 standard input(keyboard, terminal), 1 standard output, 2 std error
		return (NULL);
	temp = read_file(fd, temp);
	if(!temp)
		return (NULL);
	temp = read_line(temp);
	clean(temp);
	return(temp);
}
