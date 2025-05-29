/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:17:32 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/15 22:17:33 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*join;

	join = (char *)malloc((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1) * sizeof(char));
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
	join[i + j] = '\0';
	free(s1);
	return (join);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*copy;

	copy = s;
	count = 0;
	while (count < n)
	{
		copy[count] = c;
		count++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*copy;

	if (nmemb * size > 0 && (nmemb * size / size != nmemb))
		return (NULL);
	copy = (void *)malloc(nmemb * size);
	if (!copy)
		return (NULL);
	copy = ft_memset(copy, 0, nmemb * size);
	return (copy);
}






