
#include "get_next_line.h"
#include <stdio.h>

void ft_new_alloc(char **str, int size, char *buf)
{
	char	*tmp;
	int		len;
	
	if (*str == 0)
	{
		*str = (char *)malloc (sizeof(char) * (size + 1));
		if (*str == 0)
			return ;	
		ft_strlcpy(*str, buf, size + 1);
		return ;
	}
	len = ft_strlen(*str);
	//printf("len = %d\n",len);
	tmp = (char *) malloc(sizeof(char) * (len + 1));
	ft_strlcpy(tmp, *str, len + 1);
	//printf("tmp = %s\n",tmp);
	free(*str);
	*str = (char *) malloc (sizeof(char) * (size + len + 1));
	ft_strlcpy(*str, tmp, len + 1);
	ft_strlcat(*str, buf, len + size + 1);
	free(tmp);
}

char *get_next_line(int fd)
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
			buf[i] = s;
			i ++;
			res = read(fd, &s, 1);
		}
		//printf("%s\t %d\t %d\n",buf, strlen(buf), i);
		if (i > 0)
			ft_new_alloc(&result, i, buf);
		if (s == '\n' || res <= 0)
			break;
		i = 0;
	}
	return(result);
}

int main ()
{
	int fd;
	fd = open("text", O_RDONLY, 0);
	if (fd < 1)
		return (1);
	char *result;
	printf("%s\n",result = get_next_line(fd));
	printf("%s\n",result = get_next_line(fd));
	printf("%s\n",result = get_next_line(fd));
	printf("%s\n",result = get_next_line(fd));
	printf("%s\n",result = get_next_line(fd));
	printf("%s\n",result = get_next_line(fd));
	printf("%s\n",result = get_next_line(fd));
	printf("%s\n",result = get_next_line(fd));
	printf("%s\n",result = get_next_line(fd));
	return(0);
}