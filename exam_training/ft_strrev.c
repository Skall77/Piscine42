#include <stdio.h>
#include <stdlib.h>

char    *ft_strrev(char *str)
{
	char temp;
	int i = 0;
	int j = 0;

	while(str[i] != '\0')
		i++;
	str[i] = '\0';
	i--;
	while(i > j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	printf("%s", str);
	return(str);
}




int	main(void)
{
	char str[] = "Hello";
	ft_strrev(str);
	printf("%s", str);
}
