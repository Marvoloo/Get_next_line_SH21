/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:28:42 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/27 21:28:44 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (*c != '\0')
	{
		c ++;
		len ++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	int	i;

	i = 0;
	if (dst_size > 0)
	{
		while (dst_size > 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			dst_size --;
			i ++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= dst_len)
		return (dstsize + ft_strlen(src));
	while (i < dstsize - dst_len - 1 && src[i] != '\0')
	{
		dst[i + dst_len] = src[i];
		i ++;
	}
	dst[i + dst_len] = '\0';
	return (ft_strlen(src) + dst_len);
}
