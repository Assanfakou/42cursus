#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int count_word (char *str, char c)
{
    int word;
    int chec;
    int i;

    word = 0;
    chec = 0;
    i = 0;
    while(str[i])
    {
        if (str[i] != c)
        {
            if (chec == 0)
            {
                word++;
                chec = 1;
            }
        }
        else
            chec = 0;
        i++;
    }
    return (word);
}
int strlens(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    return (i);
}
void ft_strcop(char *dest, char *src, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
void ft_free(char **ss, int i)
{
    while(i > 0)
        free(ss[i--]);
    free(ss);
}
char **ft_spli(char *str, char c)
{
    char **s;
    int i;
    int size;
    int word_len;

    size = count_word(str, c);
    s = malloc(sizeof(char *) * (size + 1));
    if (!s)
        return (NULL);
    i = 0;
    while (i < size)
    {
        while (*str == c)
            str++;
        word_len = strlens(str, c);
        s[i] = malloc(sizeof(char) * (word_len + 1));
        if(!str[i])
            return (ft_free(s, i), NULL);
        ft_strcop(s[i++], str, word_len);
        str += word_len;
    }
    s[i] = NULL;
    return (s); 
}
int main ()
{
    char *str = "hello assan how is things";
    char **str1 ;
    str1 = ft_spli(str, ' ');
    
    printf("%s\n", str1[0]);
    printf("%s\n", str1[1]);
    printf("%s\n", str1[2]);
    printf("%s\n", str1[3]);
    printf("%s\n", str1[4]);
    // printf("%s\n", str1[5]);
    // printf("%s\n", str1[6]);
}