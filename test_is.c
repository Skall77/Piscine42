/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:03:49 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/07 12:04:20 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>
#include <assert.h>
#include <limits.h>
#include "./includes/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


static char char_plus_one(unsigned int i, char c)
{
	char new_c;
	new_c = c + 1;
	(void)i;
	return (new_c);
}

static void char_minus_one(unsigned int i, char *s)
{
	*s = *s - 1;
    (void)i;
}

int main(void)
{
    char c = '1';
    char s[125] = "Hello World";
    //////////////////////////////////ft_isalpha/////////////////////////////////////////
    printf("ft_isalpha return : %d\n",ft_isalpha(c));
    printf("isalpha return : %d\n",isalpha(c));
    printf("\n");
    //////////////////////////////////ft_isdigit/////////////////////////////////////////
    printf("ft_isdigit return : %d\n",ft_isdigit(c));
    printf("isdigit return : %d\n",isdigit(c));
    printf("\n");
    //////////////////////////////////ft_isalnum/////////////////////////////////////////
    printf("ft_isalnum return : %d\n",ft_isalnum(c));
    printf("isalnum return : %d\n",isalnum(c));
    printf("\n");
    //////////////////////////////////ft_isascii/////////////////////////////////////////
    printf("ft_isascii return : %d\n",ft_isascii(c));
    printf("isascii return : %d\n",isascii(c));
    printf("\n");
    //////////////////////////////////ft_isprint/////////////////////////////////////////
    printf("ft_isprint return : %d\n",ft_isprint(c));
    printf("isprint return : %d\n",isprint(c));
    printf("\n");

    ///////////////////////////////////ft_strlen/////////////////////////////////////////
    printf("ft_strlen return : %ld\n",ft_strlen(s));
    printf("strlen return : %ld\n",strlen(s));
    printf("\n");
    ///////////////////////////////////ft_memset/////////////////////////////////////////
    printf("The return of ft_memset = %s\n", (unsigned char*)ft_memset(s,'a', 3));
    char s2[125] = "Hello World";
    printf("The return of memset    = %s\n", (unsigned char*)memset(s2,'a', 3));
    ///////////////////////////////////ft_bzero/////////////////////////////////////////
    char s3[125] = "Hello World";
    ft_bzero(s3,3);
    char s4[125] = "Hello World";
    bzero(s4,3);
    printf("\n");
    printf("using ft_bzero on s : %s\n", s3);
    printf("using bzero on s    : %s\n", s4);
    printf("\n");
    ///////////////////////////////////ft_memcpy/////////////////////////////////////////
    char s5[255] = "Hello World";
    char dest[] = "                     ";
    printf("The return of ft_memcpy = %s\n", (unsigned char*)ft_memcpy(dest,s5, 3));
    char dest2[] = "                     ";
    printf("The return of memcpy    = %s\n", (unsigned char*)memcpy(dest2,s5, 3));
    char dest3[255];
    char dest3b[255];
	printf("\n");
    ///////////////////////////////////ft_strlcpy/////////////////////////////////////////
    printf("The return of ft_strlcpy = %ld et dest deviens= %s\n", ft_strlcpy(dest3,s5,12), dest3);
    printf("The return of strlcpy = %ld et dest deviens= %s\n", strlcpy(dest3b,s5,12), dest3b);
	printf("\n");
    ///////////////////////////////////ft_strlcat/////////////////////////////////////////
	char dest4[]= "Hi ! and ";
    char dest4b[]= "Hi ! and ";
    char dest4c[]= "Hi ! and ";
	printf("The return of ft_strlcat = %ld et dest deviens= %s\n", ft_strlcat(dest4,s5,12), dest4);
    printf("The return of clement_strlcat = %ld et dest deviens= %s\n", strlcat(dest4c,s5,12), dest4c);
    printf("The return of strlcat = %ld et dest deviens= %s\n", strlcat(dest4b,s5,12), dest4b);
	printf("\n");
    ///////////////////////////////////ft_memmove/////////////////////////////////////////
    char dest5[155] = "This is dest";
    char s6[155] = "Hello World";
    printf("Before ft_memmove : %s\n",dest5);
    ft_memmove(dest5, s6, 30);
    printf("after ft_memmove : %s\n",dest5);
    char dest6[155] = "This is dest";
    printf("Before memmove : %s\n",dest6);
    memmove(dest6, s6, 30);
    printf("after memmove : %s\n",dest6);
    printf("\n");
	/////////////////////////////////////////ft_toupper//////////////////////////////////
	char c2 = 'a';
	char c3 = 'A';
	printf("ft_toupper return : %c\n",ft_toupper(c2));
    /////////////////////////////////////////ft_tolower//////////////////////////////////
	printf("ft_tolower return : %c\n",ft_tolower(c3));
    printf("\n");
    /////////////////////////////////////////ft_strchr//////////////////////////////////
    printf("ft_strchr return a pointer on the first character found : %s\n", ft_strchr(s6,'l'));
    printf("strchr return a pointer on the first character found : %s\n", strchr(s6,'l'));
    printf("\n");
    /////////////////////////////////////////ft_strrchr//////////////////////////////////
    printf("ft_strrchr return a pointer on the last character found : %s\n", ft_strrchr(s6,'l'));
    printf("strrchr return a pointer on the last character found    : %s\n", strrchr(s6,'l'));
    printf("\n");
    /////////////////////////////////////////ft_strncmp//////////////////////////////////
    char s7[155] = "Hello World";
    printf("The diff between s1 and s2, using ft_strncmp, is : %d\n", ft_strncmp(s6,s7,50));
    printf("The diff between s1 and s2 using strncmp, is : %d\n", strncmp(s6,s7,50));
    printf("\n");
    /////////////////////////////////////////ft_memchr//////////////////////////////////
    printf("The return of ft_memchr : %s\n", ((unsigned char *)ft_memchr(s6, 'l', 5)));
    printf("The return of memchr    : %s\n", ((unsigned char *)memchr(s6, 'l', 5)));
    printf("\n");
    /////////////////////////////////////////ft_memcmp//////////////////////////////////
    printf("The diff between s1 and s2, using ft_memcmp, is : %d\n", ft_memcmp(s6,s7,50));
    printf("The diff between s1 and s2, using memcmp, is : %d\n", memcmp(s6,s7,50));
    printf("\n");
    /////////////////////////////////////////ft_strntr//////////////////////////////////
    const char little[] = "? Y";
	const char big[] = "Does it work ? Yes it does work";
    printf("Let's test ft_strnstr : %s\n", ft_strnstr(big,little,16));
	printf("Let's test strnstr : %s\n", strnstr(big,little,16));
    printf("\n");
    /////////////////////////////////////////ft_strntr//////////////////////////////////
    const char nptr[]= "     -2147483647   ";
	printf("Test with ft_atoi: %d\n",ft_atoi(nptr));
	printf("Test with atoi: %d\n",atoi(nptr));
    printf("\n");
    /////////////////////////////////////////ft_calloc//////////////////////////////////
    int i = 0;
	int *ptr = (int *)ft_calloc(10, sizeof(int));
     assert(ptr != NULL );
	while (i < 10-3)
    {
		ptr[i]=i;
        i++;
    }
    i=0;
	while (i < 11)
    {
		printf("%d ", ptr[i]);
        i++;
    }
	printf("\n");
	free(ptr);
    i = 0;
	int *ptr2 = (int *)calloc(10, sizeof(int));
     assert(ptr2 != NULL );
	while (i < 10-3)
    {
		ptr2[i]=i;
        i++;
    }
    i=0;
	while (i < 11)
    {
		printf("%d ", ptr2[i]);
        i++;
    }
	printf("\n");
	free(ptr2);
    printf("\n");
    /////////////////////////////////////////ft_strdup//////////////////////////////////
    char *dup1 = ft_strdup(s7);
    char *dup2 = strdup(s7);
    printf("Let's test ft_strdup : %s\n", dup1);
	printf("Let's test strdup    : %s\n", dup2);
    free(dup1);
    free(dup2);
    printf("\n");
    /////////////////////////////////////////ft_substr//////////////////////////////////
	char *sub;
	sub = ft_substr(s7,7,3);
    printf("The substring of \"Hello World\" is : %s\n", sub);
	free(sub);
    printf("\n");
    /////////////////////////////////////////ft_strjoin//////////////////////////////////
    char s8[] = "Hello ";
	char s9[] = "World!";
	char *join;
	join = ft_strjoin(s8,s9);
    printf("Test of ft_strjoin : %s\n", join);
	free(join);
    printf("\n");
    /////////////////////////////////////////ft_strtrim//////////////////////////////////
    const char s1const[] = "___Let's test ft_strtrim___";
	const char set[] = "_";
	char *trim;
	printf("%s\n",s1const);
	trim = ft_strtrim(s1const,set);
    printf("The trimmed string is : %s\n", trim);
	free(trim);
    printf("\n");
    /////////////////////////////////////////ft_itoa///////////////////////////////////
    printf("ft_itoa \"0\" : %s\n", ft_itoa(0));
    printf("ft_itoa INT_MAX : %s\n", ft_itoa(INT_MAX));
	printf("ft_itoa INT_MIN : %s\n", ft_itoa(INT_MIN));
    printf("\n");
    /////////////////////////////////////////ft_split//////////////////////////////////
    char **split;
	char str[] ="     a b  c      d     e  11 '''  dznjldnfbfbej    ";
	i = 0;
	char sep = ' ';
	printf("Let's split with [%c] this string : %s\n",sep, str);
	split = ft_split(str, sep);
	while(split[i])
	{
		printf("[%s]\n",split[i]);
		i++;
	}
    printf("\n");
    /////////////////////////////////////////ft_strmapi//////////////////////////////////
	char str2[] = "abcdefg1234";
	char *new_str;
	new_str = ft_strmapi(str2, &char_plus_one);
	printf("str before ft_strmapi : %s\n", str2);
	printf("after ft_strmapi : %s\n", new_str);
    printf("\n");
    /////////////////////////////////////////ft_striteri//////////////////////////////////
    char str3[] = "abcdefg1234";
	printf("str before ft_striteri : %s\n", str3);
    ft_striteri(str3, &char_minus_one);
	printf("after ft_striteri : %s\n", str3);
    printf("\n");
    /////////////////////////////////////////ft_put_fd//////////////////////////////////
    int	fd;

	fd = open("test.txt", O_WRONLY, O_APPEND);
	if (fd == -1)
		return -1;
	ft_putchar_fd('a', fd);
    ft_putendl_fd("", fd);
	ft_putstr_fd("This is working", fd);
    ft_putendl_fd("", fd);
	ft_putnbr_fd(12548798,fd);
	close(fd);
}
