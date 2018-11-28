/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:30:41 by ydemange          #+#    #+#             */
/*   Updated: 2018/11/28 16:37:15 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
	
int main()
{
	int 	retour;
	int 	fd;
	char 	*line;
	int i;

	i = 0;
	fd = open("aa",O_RDONLY);
	while ( (retour = get_next_line(fd, &line)) > 0)
	{
		printf("line =%s\n",line);
	//	printf("retour =%d\n",retour);
		ft_strdel(&line);
		i++;
	}
		printf("retourSortieBoucle =%d\n",retour);
	return (0);
}
