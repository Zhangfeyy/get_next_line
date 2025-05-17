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

char	*get_next_line(int fd)
{
	static unsigned char *buffer;
	unsigned char *sentence;
	size_t	length;
	size_t	count;

	buffer = (unsigned char*)ft_calloc(BUFFER_SIZE);
	if(!buffer)
		return(NULL);
	length = read(fd, buffer, BUFFER_SIZE);
	if(length == -1)
		return(NULL);
	if(length > 1)
	{
		sentence = (unsigned char *)ft_calloc(length);
		if(!sentence)
			return (NULL);
		count = 0;
		while(*buffer)
		{
			
		}
	}



	if(length == 0)
		



	
}
