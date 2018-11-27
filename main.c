/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:30:41 by ydemange          #+#    #+#             */
/*   Updated: 2018/11/26 18:42:01 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int 	retour;
	int 	fd;
	char 	*line;

	fd = open("me",O_RDONLY);
	while ( (retour = get_next_line(fd, &line)) > 0)
	{
		printf("line =%s\n",line);
		printf("retour =%d\n",retour);
		free(line);
	}
		printf("retourSortieBoucle =%d\n",retour);
	return (0);
}
