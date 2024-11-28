/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:13:50 by mlarioui          #+#    #+#             */
/*   Updated: 2024/11/11 19:32:21 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int			ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_substr(const char *s, size_t start, size_t len);
char		*init_remainder(char *remainder);
char		*handle_read_errors(ssize_t bytes_read, char *remainder);
char		*read_and_append(int fd, char *remainder);
char		*extract_line(char **remainder);
char		*get_next_line(int fd);

#endif