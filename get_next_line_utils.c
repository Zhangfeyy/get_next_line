/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:17:32 by fzhang            #+#    #+#             */
/*   Updated: 2025/06/03 19:05:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if(!str)
		return (len);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}


void	*ft_memset(void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*copy;

	copy = s;
	count = 0;
	while (count < n)
	{
		copy[count++] = c;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*copy;

	if (nmemb * size > 0 && ((size_t)-1) / size < nmemb)
		return (NULL);
	copy = (void *)malloc(nmemb * size);
	if (!copy)
		return (NULL);
	ft_memset(copy, 0, nmemb * size);
	return (copy);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*join;

    	if (!s1 || !s2)
        	return (NULL);
	join = (char *)ft_calloc((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1), sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (join);
}

unsigned char *ft_strchr(const char *s, int c)
{
    size_t i = 0;

    if (!s)
        return (NULL);
    while (s[i] != '\0')
    {
        if (s[i] == (unsigned char)c)
            return ((unsigned char *)&s[i]); // Return pointer to first match
        i++;
    }
    if ((unsigned char)c == '\0') // Check for null terminator if c is 0
        return ((unsigned char *)&s[i]);
    return (NULL); // Character not found
}
