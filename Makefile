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

SRC_MAIN	=	main.c

SRC_RC		=	find_wall.c init_ray.c compute_distance.c draw_walls.c\
				draw_column.c

SRC_PARSING	=	parse_file.c utils.c create_env.c validate_env.c\
				errors.c valid_color.c valid_map.c valid_texture.c\
				init_character.c

SRC_MONITO	=	init_mlx.c movement.c hooks.c draw_background.c\

SRC_UTILS	=	vector.c show_env.c clean_global.c draw.c show_character.c\
				vector2.c

SRC_MAND	=	monitor.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_MAIN))\
				$(addprefix $(SRC_DIR)parsing/, $(SRC_PARSING))\
				$(addprefix $(SRC_DIR)raycasting/, $(SRC_RC))\
				$(addprefix $(SRC_DIR)monitor/, $(SRC_MONITO))\
				$(addprefix $(SRC_DIR)utils/, $(SRC_UTILS))\
				$(addprefix $(SRC_DIR)monitor/, $(SRC_MAND))

SRC_BONUS	=	$(addprefix $(SRC_DIR), $(SRC_MAIN))\
				$(addprefix $(SRC_DIR)parsing/, $(SRC_PARSING))\
				$(addprefix $(SRC_DIR)raycasting/, $(SRC_RC))\
				$(addprefix $(SRC_DIR)monitor/, $(SRC_MONITO))\
				$(addprefix $(SRC_DIR)utils/, $(SRC_UTILS))\
				$(addprefix $(SRC_DIR)bonus/, monitor_bonus.c minimap.c)\

#------------------------------------#
#               OBJECTS              #
#------------------------------------#

OBJ_DIR		=	obj/
OBJ			=	$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC:.c=.o))
OBJ_BONUS	=	$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC_BONUS:.c=.o))

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

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(CFLAG) $(OBJ) -o $(NAME) $(LIB_ARCHIVE) $(LNK_FLAG)

bonus: $(LIBFT_A) $(LIBMLX_A) $(OBJ_BONUS) $(HEADER)
		$(CC) $(CFLAG) $(OBJ_BONUS) -o $(NAME)_BONUS $(LIB_ARCHIVE) $(LNK_FLAG)

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
		rm -rf $(NAME)_BONUS
		rm -rf $(LIBFT_A)
		rm -rf $(LIBMLX_A)

re: fclean all

.PHONY: all clean fclean re
