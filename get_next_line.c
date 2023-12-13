/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:01:35 by nmellal           #+#    #+#             */
/*   Updated: 2023/12/12 18:57:26 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 5

size_t	ft_strlen(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		;
	return (i);
}

char	*destalloc(char *str)
{
	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;
	char	*str;

	dest = destalloc(dest);
	if (!dest || !src)
		return (NULL);
	str = malloc(ft_strlen(dest) + ft_strlen(src) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (dest[i])
		str[i++] = dest[i++];
	j = 0;
	while (src[j])
	{
		str[i + j] = src[j];
		j++;
	}
	str[i + j] = '\0';
	free(dest);
	return (str);
}

int	charsearch(char *buffer, char c)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*return_and_free(size_t len, char *buffer, char *str)
{
	free(str);
	if (len == 0)
		return (buffer);
	else
		return (NULL);
}

char	*readline(int fd, char *buffer, size_t len)
{
	char	*str;
	char	*temp;

	str = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (charsearch(buffer, '\n') < 0)
	{
		len = read(fd, str, BUFFER_SIZE);
		if (len <= 0)
			return (return_and_free(len, buffer, str));
		str[len] = '\0';
		temp = ft_strcat(buffer, str);
		if (!temp)
		{
			free(str);
			return (NULL);
		}
		buffer = temp;
	}
	free(str);
	return (buffer);
}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	size_t		len;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = readline(fd, buffer, len);
	if (!buffer)
		return (NULL);
	return (buffer);
}

int	main(void)
{
	int		filed;
	char	*s;

	filed = open("douaa.txt", O_RDWR);
	s = get_next_line(filed);
	printf("%s\n", s);
}
