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

size_t get_len(unsigned char *buffer)
{
	size_t	count;

	count = 0;
	while(buffer[count] != '\0')
		count++;
	return (count);
}



