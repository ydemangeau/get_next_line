/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valgrind.user.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:14:39 by ydemange          #+#    #+#             */
/*   Updated: 2018/11/26 17:53:51 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("me", O_RDONLY);
	while (get_next_line(fd, &line))
		free(line);
	return (0);
}
