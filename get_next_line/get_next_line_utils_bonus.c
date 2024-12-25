#include "get_next_line_bonus.h"

char *ft_strchr(char *str, char c)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (str + i);
        i++;
    }
    if (str[i] == c)
        return (str + i);
    return (NULL);
}
size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
char *ft_strdup_nln(const char *str)
{
    char *allocated;
    size_t i;
    size_t l;

    if (!str)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    allocated = malloc(sizeof(char) * i + 2);
    if (!allocated)
        return (NULL);
    l = 0;
    while (l <= i)
    {
        allocated[l] = str[l];
        l++;
    }
    allocated[l] = '\0';
    return (allocated);
}
char *ft_strdup(const char *str)
{
    char *allocated;
    size_t i;

    if (!str)
        return (NULL);

    allocated = malloc(sizeof(char) * ft_strlen(str) + 1);
    if (!allocated)
        return (NULL);
    i = 0;
    while (str[i])
    {
        allocated[i] = str[i];
        i++;
    }
    allocated[i] = '\0';
    return (allocated);
}
char    *ft_strjoin(const char *s1, const char *s2)
{
    char *joined;
    size_t i;
    size_t j;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!joined)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        joined[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
        joined[i++] = s2[j++];
    joined[i] = '\0';
    return (joined);
}
