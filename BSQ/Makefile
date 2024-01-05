SRCS = avg_ft.c in_out.c main.c noob_ft.c super_ft.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = bsq
GCC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

.c.o: 	
		 ${GCC} ${FlAGS} -I ${INCS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		 ${GCC} ${FLAGS} ${OBJS} -o ${NAME}

all:	 ${NAME}

clean:	 
		 ${RM} ${OBJS}

fclean:	 clean
		 ${RM} ${NAME}

re:		 fclean all
