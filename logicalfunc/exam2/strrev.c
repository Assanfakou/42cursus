#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strrev(char *str)
{
	int i;
	int len;
	char tmp;

	i = 0;
	len = strlen(str) - 1;
	while (len > i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

int main()
{
    char *st = "assan";
   printf("%s", ft_strrev(st));
}
