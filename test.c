#include "get_next_line.h"

# include <stdlib.h>
int		ft_line(char **line, char *str, int ret, int fd)
{
	char *tmp;
	int len;
	
	printf("str=%s\n",str);
	printf("ret=%d\n",ret);
	len = 0;
	while (str[len] != '\n' &&  str[len] != '\0')
		len++;
	printf("len=%d\n",len);
	if (str[len] == '\n')
	{
		*line =  ft_strsub(str, 0, len);
		tmp = ft_strdup(&str[len + 1]);
		free(str);
		printf("ok\n");
		printf("TMP =%s\n",tmp);
		str = tmp;
		printf("STR =%s\n",str);
		if (str[0] == '\0')
			ft_strdel(&str);
	}
	else if (str[len] == '\0')
		{  
			if(ret == BUFF_SIZE)
				return (get_next_line(fd,line));
			*line = ft_strdup(str);
			ft_strdel(&str);
			return (0);
		}
	//printf("line=%s\n",*line);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

		printf("ENTREE STR =%s\n",str);
	if (fd < 0 || line  == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		if (!str)
		{
			str = ft_strnew(1);
			printf("okstr =%s\n",str);
		}
		tmp = ft_strjoin(str, buff);
		free(str);
		str = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret == 0 || !str) // remplacer par &&
	{
		printf("SORTIE STR =%s\n",str);
		printf("SORTIE ret=%d\n",ret);
		return (0);
	}
	printf("ft_line\n\n");
	return (ft_line(line, str, ret, fd));
}
