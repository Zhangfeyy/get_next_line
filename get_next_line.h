/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:17:45 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/15 22:17:46 by fzhang           ###   ########.fr       */
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
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin_free(char *s1, char *s2);

#endif

