#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char    *ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, size_t start, size_t len);
void    free_memory(char **ptr);

#endif