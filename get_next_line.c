/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:15:17 by ydemange          #+#    #+#             */
/*   Updated: 2018/11/26 18:45:08 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_error(char **str,int fd, char **line)
{
	if (fd < 0 || !line)
		return (-1);
	if (!*str)
	{
		if (!(*str = ft_strdup("")))
			return (-1);
//		printf("OK=%s\n",*str);
	}
	return (1);
}

static char		*join(char *str, char *buff)
{
	char *tmp;
	tmp = ft_strjoin(str, buff);
	free(str);
	return (tmp);
}

static char		*readline(char *str, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = join(str, buff);
//		printf("buff =%s\n",buff);
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char *str;
	int			i;
	int a;

	a = 0;
	if (check_error(&str, fd, line) == -1)
		return (-1);
	i = 0;
	str = readline(str, fd);
	if (str[i])
	{
		printf("str=\n%s\n",str);
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (i == 0)
			*line = ft_strdup("");
		else
		{
			*line = ft_strsub(str, 0, i);
			str = &str[i + 1];
		}
		return (1);
	}
	else
	{
		str = NULL;
		free(str);
	}
//	printf("str=%s\n",str);
	return (0);
}
