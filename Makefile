#------------------------------------------------------------------------------#
#                                                                              #
#                               DECLARATIONS                                   #
#                                                                              #
#------------------------------------------------------------------------------#

#------------------------------------#
#             COMPILATION            #
#------------------------------------#

NAME			=	cub3D

CC				=	clang
CFLAG			=	-Wall -Wextra -Werror -g3
PROJINC_FLAG	=	-I includes

#------------------------------------#
#                LIBFT               #
#------------------------------------#

LIBFT_DIR		=	libft/
LIBFT_A			=	$(LIBFT_DIR)libft.a

LIBFTINC_FLAG	=	-I $(LIBFT_DIR)

#------------------------------------#
#                MLX                 #
#------------------------------------#

LIBMLX_DIR		=	minilibx/
LIBMLX_A		=	$(LIBMLX_DIR)libmlx.a

LIBMLXINC_FLAG	=	-I $(LIBMLX_DIR)

#------------------------------------#
#               SOURCES              #
#------------------------------------#

SRC_DIR		=	src/

SRC_MAIN	=	main_mlx.c

SRC_RC		=	find_wall.c init_ray.c

SRC_MONITO	=	init_mlx.c del_mlx.c monitor.c hooks.c

SRC_UTILS	=	vector.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_MAIN))\
				$(addprefix $(SRC_DIR)raycasting/, $(SRC_RC))\
				$(addprefix $(SRC_DIR)monitor/, $(SRC_MONITO))\
				$(addprefix $(SRC_DIR)utils/, $(SRC_UTILS))\

#------------------------------------#
#               OBJECTS              #
#------------------------------------#

OBJ_DIR		=	obj/
OBJ			=	$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC:.c=.o))

#------------------------------------#
#               HEADER               #
#------------------------------------#

HEADER	=	includes/cub3d.h

#------------------------------------#
#              SUMMARY               #
#------------------------------------#

LIB_ARCHIVE	=	$(LIBFT_A) $(LIBMLX_A)
INC_FLAG	=	$(PROJINC_FLAG) $(LIBFTINC_FLAG) $(LIBMLXINC_FLAG)
LNK_FLAG	=	-lXext -lX11 -lm

#------------------------------------------------------------------------------#
#                                                                              #
#                                   RULES                                      #
#                                                                              #
#------------------------------------------------------------------------------#

all: $(LIBFT_A) $(LIBMLX_A) $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAG) $(OBJ) -o $(NAME) $(LIB_ARCHIVE) $(LNK_FLAG)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p `dirname $@`
	$(CC) $(CFLAG) -c $< -o $@ $(INC_FLAG)

$(LIBFT_A):
		make -C $(LIBFT_DIR)

$(LIBMLX_A):
		make -C $(LIBMLX_DIR)

clean:
		rm -rf $(OBJ_DIR)
		make -C $(LIBFT_DIR) clean
		make -C $(LIBMLX_DIR) clean

fclean: clean
		rm -rf $(NAME)
		rm -rf $(LIBFT_A)
		rm -rf $(LIBMLX_A)

re: fclean all

.PHONY: all clean fclean re
