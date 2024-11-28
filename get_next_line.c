/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:48:13 by mlarioui          #+#    #+#             */
/*   Updated: 2024/11/11 19:39:39 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_read_errors(ssize_t bytes_read, char *remainder)
{
	if (bytes_read < 0)
	{
		free(remainder);
		return (NULL);
	}
	if (bytes_read == 0 && (!remainder || !*remainder))
	{
		free(remainder);
		return (NULL);
	}
	return (remainder);
}

char	*read_and_append(int fd, char *remainder)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*temp;

	if (BUFFER_SIZE <= 0)
	{
		free(remainder);
		return (NULL);
	}
	if (!remainder)
		remainder = ft_strdup("");
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (handle_read_errors(bytes_read, remainder));
		buffer[bytes_read] = '\0';
		temp = remainder;
		remainder = ft_strjoin(remainder, buffer);
		free(temp);
		if (ft_strchr(remainder, '\n'))
			return (remainder);
	}
}

char	*extract_line(char **remainder)
{
	char	*line;
	char	*temp;
	size_t	len;

	if (!*remainder || !**remainder)
		return (NULL);
	len = 0;
	while ((*remainder)[len] && (*remainder)[len] != '\n')
		len++;
	if ((*remainder)[len] == '\n')
		len++;
	line = ft_substr(*remainder, 0, len);
	temp = ft_strdup(*remainder + len);
	free(*remainder);
	*remainder = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_and_append(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(&remainder);
	return (line);
}
/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("blabla.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
} */
