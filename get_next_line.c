/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:13:32 by ydemange          #+#    #+#             */
/*   Updated: 2018/11/28 16:44:22 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		readline(char **str, int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		if (!*str)
			*str = ft_strnew(1);
		tmp = ft_strjoin(*str, buff);
		free(*str);
		*str = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ret);
}

int		new_line(char **str, int len, char **line)
{
	char *tmp;

	if (str[0][len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		tmp = ft_strdup(&str[0][len + 1]);
		free(*str);
		*str = tmp;
		if (*str[0] == '\0')
			ft_strdel(str);
	}
	else if (str[0][len] == '\0')
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str;
	int				ret;
	int				len;

	len = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	ret = readline(&str, fd);
	if (ret == -1)
		return (-1);
	if (ret == 0 && !str)
		return (0);
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (new_line(&str, len, line));
}
