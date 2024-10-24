/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:48:13 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/22 17:37:24 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 
char *init_remainder(char *remainder)
{
    if (!remainder)
    {
        remainder = ft_strdup("");
        if (!remainder)
            return (NULL);
    }
    return (remainder);
}

char *read_and_append(int fd, char *remainder)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    char *temp;

    remainder = init_remainder(remainder);
    if (!remainder)
        return (NULL);
    
    while (1)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            if (bytes_read < 0)
                perror("Error reading file");
            return (bytes_read == 0 && (!remainder || !*remainder)) ? free(remainder), NULL : remainder;
        }
        buffer[bytes_read] = '\0';
        temp = remainder;
        remainder = ft_strjoin(remainder, buffer);
        free(temp);
        if (ft_strchr(remainder, '\n'))
            return remainder;
    }
}


char *extract_line(char **remainder)
{
    char *line;
    char *temp;
    size_t len;

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
char *get_next_line(int fd)
{
    static char *remainder;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    remainder = read_and_append(fd, remainder);
    if (!remainder)
        return (NULL);
    line = extract_line(&remainder);
    return (line);
}
/*int	main(void)
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
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
/* int main(void)
{
    int     fd;
    char    *line;

    // Attempt to open the file
    fd = open("blabla.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    printf("File opened successfully. Reading lines...\n");

    // Read and print lines one by one
    while ((line = get_next_line(fd)) != NULL)
	{
    	printf("%s", line);
    	free(line);
	}
    // If get_next_line() returns NULL, check if it's due to an error
    if (line == NULL)
        printf("End of file or error encountered.\n");

    // Close the file
    if (close(fd) == -1)
    {
        perror("Error closing file");
        return (1);
    }

    printf("Finished reading file. File closed.\n");
    return (0);
} */
