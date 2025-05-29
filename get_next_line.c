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
static char	*read_file(char *temp, int fd)
{
	char *buffer;
	size_t length;

	//how to initialize temp???? also a check for temp ? = NULL
	buffer = (char*)ft_calloc(BUFFER_SIZE + 1); // treat it as a string
	if(!buffer)
		return(NULL);
	while(!ft_strchr(temp, '\n'))
	{
		length = read(fd, buffer, BUFFER_SIZE);
		temp = ft_strjoin_free(temp, buffer);
		//buffer !0? not necessary already calloc
		if(length == -1 || !temp)
		{
			free(buffer);
			return (NULL);
		}
		if(length == 0)
		{
			free(buffer);
			return(temp);
		}
	}
	free(buffer);
	return (temp);
}

char *read_line(char *temp)
{
	size_t	i;
	char *ttemp;
	int	check;

	if(!temp)
		return(NULL);
	i = 0;
	check = 1;
	while(temp[i] && temp[i] != '\n')
		i++;
	ttemp = (char *)ft_calloc(i + 1);
	if(!temp[i])
		check = 0;
	if(!ttemp)
		return(NULL);
	while(i >= 0)
	{
		ttemp[i] = temp[i];
		temp[i] = '\0';
		i--;
	}
	clean_temp(temp, &check);
	return(ttemp);
}

void	clean_temp(char *temp, int *check)
{
	size_t	i;
	size_t	j;

	if(!check)
		return;
	i = 0;
	while (!temp[i])
		i++;
	j = i;
	while(temp[i])
	{
		temp[i - j] = temp[i];
		temp[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char *temp;
	//  static int i = 4;  // only to initialize this way
	char *line;

	if(BUFFER_SIZE <= 0 || fd < 0) // 0 standard input(keyboard, terminal), 1 standard output, 2 std error
		return (NULL);
	temp = read_file(fd, temp);
	if(!temp)
		return (NULL);
	line = read_line(temp);
	return(line);
}