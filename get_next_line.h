/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:17:45 by fzhang            #+#    #+#             */
/*   Updated: 2025/06/03 19:05:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

// 定义宏文件
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include "unistd.h"
#include "stdlib.h"

char	*get_next_line(int fd);
unsigned char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin_free(char *s1, char *s2);
size_t ft_strlen(const char *str);

#endif

