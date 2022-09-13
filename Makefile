NAME = Cub3D

SRC = parsing.c \

OBJS = ${SRC:.c=.o}

INCL_D	=	includes/

LIBFT_D	=	libft/

LIBX_D	=	minilibx/

LIBFT	=	${LIBFT_D}libft.a

LIBX	=	${LIBX_D}libmlx.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	${NAME}

%.o		:	%.c $(addprefix ${INCL_D}, cub3d.h)
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCL_D} -I ${LIBFT_D} -I ${LIBX_D}

${LIBFT}:
			make -C ${LIBFT_D}

${LIBX}	:
			make -C ${LIBX_D}

${NAME}	:	${LIBFT} ${OBJS} ${LIBX}
			${CC} ${OBJS} -o ${NAME} ${LIBFT} ${LIBX} -lXext -lX11 -lm

clean	:
			${RM} ${OBJS}
			make clean -C ${LIBFT_D}

fclean	:	clean
			${RM} ${NAME}
			make fclean -C ${LIBFT_D}
			make clean -C ${LIBX_D}

re		:	fclean all

.PHONY	:	all clean fclean re
