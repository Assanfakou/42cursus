#include "get_next_line.h"

char *ft_strchr(const char *str, char to_find)
{
	int i;

	if (!str)
		return(NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0')
		return (&str[i]);
	return (NULL);
}

char *ft_strdup(const char *str)
{
	size_t s;
	size_t robe;
	char *allocated;

	robe = 0;
	while (str[robe])
		robe++;
	allocated = malloc(sizeof(char) * (robe + 1));
	if (allocated == NULL)
		return (NULL);
	s = 0;
	while (s < robe)
	{
		allocated[s] = str[s];
		s++;
	}
	allocated[s] = 0;
	return (allocated);
}

char *ft_strdup_nline(const char *str)
{
	size_t s;
	size_t robe;
	char *allocated;

	robe = 0;
	while (str[robe] || str[robe] == '\n')
		robe++;
	allocated = malloc(sizeof(char) * (robe + 1));
	if (allocated == NULL)
		return (NULL);
	s = 0;
	while (s < robe)
	{
		allocated[s] = str[s];
		s++;
	}
	allocated[s] = 0;
	return (allocated);
}
size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char *ft_strjoin(const char *s1, const char *s2)
{
	char *final_string;
	size_t i;
	size_t s;
	size_t total;

	if (!s1 || !s2)
		return(NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	final_string = malloc(sizeof(char) * (total + 1));
	if (!final_string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		final_string[i] = s1[i];
		i++;
	}
	s = 0;
	while (s2[s])
		final_string[i++] = s2[s++];
	final_string[i] = '\0';
	return (final_string);
}
