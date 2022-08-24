SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = libft.a
LIB = ar rc
RANL = ranlib
GCC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

.c.o: 	
		${GCC} ${FlAGS} -c -I ${INCS} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		 ${LIB} ${NAME} ${OBJS}
		 ${RANL} ${NAME}

all:	 ${NAME}

clean:	 
		${RM} ${OBJS}

fclean:	 clean
		 ${RM} ${NAME}

re:		 fclean all
