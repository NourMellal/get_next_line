/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:01:35 by nmellal           #+#    #+#             */
/*   Updated: 2023/12/08 14:54:02 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	int		nb;

	nb = 1;
	buffer = malloc(sizeof(char) * 1024 + 1);
	while (nb > 0)
	{
		nb = read(fd, buffer, 1024);
		if (nb < 0)
		{
			perror("heheh\n");
			return ;
		}
	}
}

int	main(void)
{
	int	filed;

	filed = open("nouha.txt", O_RDWR);
	print_line();
}
