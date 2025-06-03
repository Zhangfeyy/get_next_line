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

//temp check
//read lines till a new line appears
static char	*read_file(char *temp, int fd)
{
	char *buffer;
	size_t length;

	//how to initialize temp???? also a check for temp ? = NULL
	//*ft_chr must handle the case of null pointer! if null, should return an abnormal value and end the loop
	buffer = (char*)ft_calloc(BUFFER_SIZE + 1, 1); // treat it as a string
	if(!buffer)
		return(NULL);
	while(!ft_strchr(temp, '\n'))
	{
		length = read(fd, buffer, BUFFER_SIZE);
		//buffer !0? not necessary already calloc
		if(length == -1 || !temp)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		if(length == 0)
		{
			free(buffer);
			return(temp);
		}
		buffer[length] = '\0'; //to manually "clear" the buffer for the next call
		temp = ft_strjoin_free(temp, buffer);
		// also need a check for the new temp, here done by ft_strchr
	}
	free(buffer);
	return (temp);
}

static char *read_line(char *temp)
{
	size_t	i;
	char *ttemp;

	i = 0;
	while(temp[i] && temp[i] != '\n')
		i++;
	if(temp[i] == '\n')
		i++;
	ttemp = (char *)ft_calloc(i + 1, 1);
	if(!ttemp)
			return(NULL);
	while(i > 0)
	{
		ttemp[i-1] = temp[i-1];
		i--;
	}
	return(ttemp);
}

static void	update_temp(char *temp)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while(temp[i] && temp[i] != '\n')
		i++;
	if(temp[i] == '\n')
		i++;
	while(temp[i])
		temp[j++] = temp[i++];
	while(temp[j])
		temp[j++] = '\0';
}

char	*get_next_line(int fd)
{
	static char *temp;
	//  static int i = 4;  // only to initialize this way
	char *line;

	if(BUFFER_SIZE <= 0 || fd < 0) // 0 standard input(keyboard, terminal), 1 standard output, 2 std error
		return (NULL);
	if(!temp)
		temp = (char *)ft_calloc(1, 1);
	temp = read_file(fd, temp);
	//after reading the file, temp should be NULL(error case)/0/valued
	//handle the null case (error case)
	if(!temp)
		return (NULL);
	//temp can only be 0 or valued here
	line = read_line(temp);
	update_temp(temp);
	
	return(line);
}