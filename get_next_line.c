/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:28:32 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/27 21:28:33 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_new_alloc(char **str, int size, char *buf)
{
	char	*tmp;
	int		len;

	if (*str == 0)
	{
		*str = (char *) malloc(sizeof(char) * (size + 1));
		if (*str == 0)
			return ;
		ft_strlcpy(*str, buf, size + 1);
		return ;
	}
	len = ft_strlen(*str);
	tmp = (char *) malloc(sizeof(char) * (len + 1));
	ft_strlcpy(tmp, *str, len + 1);
	free(*str);
	*str = (char *) malloc(sizeof(char) * (size + len + 1));
	ft_strlcpy(*str, tmp, len + 1);
	ft_strlcat(*str, buf, len + size + 1);
	free(tmp);
}

static int	ft_check(char s, int res, char **result)
{
	if (s == '\n')
	{
		ft_new_alloc(result, 1, "\n");
		return (1);
	}
	if (res <= 0)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char	buf[BUFF_SIZE];
	char	*result;
	char	s;
	int		res;
	int		i;

	i = 0;
	result = 0;
	res = read(fd, &s, 1);
	while (1)
	{
		while (res > 0 && i < BUFF_SIZE && s != '\n')
		{
			buf[i++] = s;
			res = read(fd, &s, 1);
		}
		if (i > 0)
			ft_new_alloc(&result, i, buf);
		if (ft_check(s, res, &result) == 1)
			break ;
		i = 0;
	}
	return (result);
}
