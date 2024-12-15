#include "get_next_line.h" 

char *ft_strchr(char *str, char to_find)
{
	int i;

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

char *extract_then_update(char *rem)
{
	char *allocated;
	char *cash;
	char *temp;

	if (!rem)
		return (NULL);
	cash = ft_strchr(rem, '\n');
	if (cach)
	{
		allocated = ft_strdup(cach);
		temp = ft_strdup(rem + 1);
	}
}
char *ft_strdup(char *str)
{
	size_t s;
	size_t robe;
	char *allocated;

	robe = 0;
	while (str[i] || str[i] == '\n')
		i++;
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

char *get_next_line(int fd)
{
	int suit_up;
	static int stat;
	char buffer[1030];
	char *str_nline_found;

	suit_up = read(fd, (buffer - 1), BUFFER_SIZE);
	buffer[suit_up] = 0;
	str_nline_found = ft_strchr(buffer, '\n');
	if (str_nline_found != NULL)
	{
		
		return (buffer);
	}
	else if (str_nline_found == NULL)
	{
		
	}
	
	buffer[suit_up] = 0;
	printf("%s", buffer);
}

int main ()
{
	printf("%p", ft_strchr("he\0llo", '\0', 5));
}
int main ()
{
	int fd = open("lile_is_passed.txt", O_CREAT | O_RDWR , 0777);
	write(fd, "hello", 5);
	lseek(fd, 0, SEEK_SET);
	func(fd);
	close(fd);
}

