# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 12:54:37 by dpalombo          #+#    #+#              #
#    Updated: 2018/12/09 11:54:07 by dpalombo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------------------------------ COLORS ---------------------------------------

_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m

# ------------------------------------ START ---------------------------------------

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# ------------------------------------ SRC PROG ------------------------------------
SRC		= main.c mandelbrot.c julia.c burningship.c event.c colors.c img.c

OBJFILE	= obj/
SRCFILE	= src/
INCFILE	= includes/

OBJ		= $(addprefix $(OBJFILE),$(SRC:.c=.o))

DEPS	= libfractol.h

# ------------------------------------- LIB FT -------------------------------------

SRCLIBFT	= libft/
LIB_FT		= $(addprefix $(SRCLIBFT),libft.a)
INCLIBFT	= -I libft
LIB_FT_LINK	= -L libft -l ft -l pthread 

# --------------------------------------- MLX --------------------------------------

SRCMLX			= minilibx_macos/
LIB_MLX			= $(addprefix $(SRCMLX),libmlx.a)
INCMLX			= -I minilibx_macos
LIB_MLX_LINK	= -L minilibx_macos -l mlx -framework OpenGL -framework AppKit


# --------------------------------------- RULES -------------------------------------

all: obj $(LIB_MLX) $(LIB_FT) $(NAME)

obj:
	@ mkdir -p $(OBJFILE)


$(OBJFILE)%.o: $(SRCFILE)%.c $(INCFILE)$(DEPS)
	@ $(CC) $(CFLAGS) $(INCMLX) $(INCLIBFT) -I $(INCFILE) -o $@ -c $<
	@ echo "$(_BOLD)$(_GREEN)------------------------------------------------------------------------------------------------>>> End check .c - .o > .h $(_END)"

$(LIB_FT):
	@ make -C $(SRCLIBFT)
	@ echo "$(_BOLD)$(_GREEN)------------------------------------------------------------------------------------------------>>> End Make LIB_FT $(_END)"

$(LIB_MLX):
	@ make -C $(SRCMLX)
	@ echo "$(_BOLD)$(_GREEN)------------------------------------------------------------------------------------------------>>> End Make MLX $(_END)"



$(NAME): $(OBJ)
	@ $(CC) $(OBJ) $(LIB_MLX_LINK) $(LIB_FT_LINK) -lm -o $(NAME)
	@ echo "$(_BOLD)$(_GREEN)------------------------------------------------------------------------------------------------>>> End ALL $(_END)"




clean:
	@ rm -rf $(OBJFILE)
	@ make -C $(SRCLIBFT) clean
	@ make -C $(SRCMLX) clean
	@ echo "$(_BOLD)$(_GREEN)------------------------------------------------------------------------------------------------>>> End Clean $(_END)"

fclean: clean
	@ rm -rf $(NAME)
	@ make -C $(SRCLIBFT) fclean
	@ echo "$(_BOLD)$(_GREEN)------------------------------------------------------------------------------------------------>>> End Fclean $(_END)"

re: fclean all

.PHONY = all clean fclean re
