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

char	*read_lines(int fd)
{
	unsigned *buffer;
	size_t bytes_read = 1;

	// create a buffer
	buffer = (unsigned char*)ft_calloc(BUFFER_SIZE + 1);
	if(!buffer)
		return(NULL);
	while(!ft_strchr(temp, '\n') && bytes_read > 1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}



char	*get_next_line(int fd)
{
	static unsigned char *temp;
	unsigned char *line;

	if(BUFFER_SIZE <= 0 || fd < 0) // 0 standard input(keyboard, terminal), 1 standard output, 2 std error
		return (NULL);
	temp = read_lines(fd, temp);
	if(!temp)
		return (NULL);
	line = extract_line(temp);
	temp = clean_kine
}
