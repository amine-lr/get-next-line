#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;
	size_t	i;
	size_t	j;

	len1 = 0;
	len2 = 0;
	i = 0;
	j = 0;

	if (s1 || s2)
	{
		while (s1[len1])
			len1++;
		while (s2[len2])
			len2++;
		new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (!new_str)
			return (NULL);
		while (i < len1)
		{
			new_str[i] = s1[i];
			i++;
		}
		while (j < len2)
		{
			new_str[i + j] = s2[j];
			j++;
		}
		new_str[i + j] = '\0';
	}
		return (new_str);
}
/* int main()
{
	char *s1 = NULL;
	char *s2 = NULL;
	char *new_str;

	new_str = ft_strjoin(s1, s2);
	if (!new_str)
		printf("(NULL)\n");
	else {
		printf("s1: %s\ns2: %s\n",s1 ,s2);
		printf("new string: %s\n", new_str);
	}
} */
char *ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = (char)c;
	i = 0;
	if (!s)
		return(NULL);
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
		if (ch == '\0')
			return ((char *) &s[i]);
		return (NULL);
}
/* int main ()
{
	char *s = NULL;
	char	c = 'a';
	char *result;

	result = ft_strchr(s, c);
	if (!result)
		printf("(NULL)\n");
	else 
		printf("found: %c in %s\n", c, s);
} */

char	*ft_strdup(const char *s)
{
	int	len;
	int i;
	char	*dup_s;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	dup_s = (char *)malloc((sizeof(char))*(len + 1));
	if (!dup_s)
		return (NULL);
	while (i < len)
	{
		dup_s[i] = s[i];
		i++;
	}
	dup_s[len] = '\0';
	return	(dup_s);
}
/* int main()
{
	const char *s = "bfihqdbiuhdiugdfiudqigubidqvbifbiqbfibfibfiebgfibnef";
	char	*dup;
	dup = ft_strdup(s);
	if (!dup)
		printf("(NULL)\n");
	else
		printf("original: %s\ndup: %s\n", s, dup);
} */
char	*ft_substr(const char *s, size_t start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	i = 0;
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return(ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	sub = (char *)malloc((sizeof(char))*(len + 1));
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}
/* int	main()
{
	size_t start = 1;
	size_t len = 10;
	const char *s = "Brouno Black German SHeperd";
	char *sub;
	sub = ft_substr(s, start, len);
	if (!sub)
		printf("NULL\n");
	else
		printf("subs: %s\n", sub);
} */
void free_memory(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}