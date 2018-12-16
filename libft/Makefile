# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 10:40:54 by dpalombo          #+#    #+#              #
#    Updated: 2018/12/13 19:15:57 by dpalombo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
#								for opt  -O3 -march=native

SRC=	ft_isspace.c	ft_memchr.c		ft_putnbr.c \
		ft_strequ.c		ft_strnequ.c	ft_isupper.c \
		ft_memcmp.c		ft_putnbr_fd.c	ft_striter.c \
		ft_strnew.c		ft_atoi.c		ft_itoa.c \
		ft_memcpy.c		ft_putstr.c		ft_striteri.c \
		ft_strnstr.c	ft_bzero.c		ft_lstadd.c \
		ft_memdel.c		ft_putstr_fd.c	ft_strjoin.c \
		ft_strrchr.c	ft_strncpy.c	ft_lstdel.c \
		ft_memmove.c	ft_strcat.c		ft_strlcat.c \
		ft_strsplit.c	ft_isalnum.c	ft_lstdelone.c \
		ft_memset.c		ft_strchr.c		ft_strlen.c \
		ft_strstr.c		ft_isalpha.c	ft_lstiter.c \
		ft_nbrlen.c		ft_strclr.c		ft_strmap.c \
		ft_strsub.c		ft_isascii.c	ft_lstmap.c \
		ft_putchar.c	ft_strcmp.c		ft_strmapi.c \
		ft_strtrim.c	ft_isdigit.c	ft_lstnew.c \
		ft_putchar_fd.c	ft_strcpy.c		ft_strncat.c \
		ft_tolower.c	ft_islower.c	ft_memalloc.c \
		ft_putendl.c	ft_strdel.c		ft_strncmp.c \
		ft_toupper.c	ft_isprint.c	ft_memccpy.c \
		ft_putendl_fd.c	ft_strdup.c		ft_error.c \
		ft_strerror.c	ft_usage.c		get_next_line.c \
		ft_lstrev.c		ft_wordlen.c	ft_atohexp.c \
		ft_recursive_factorial.c

DEPS = libft.h
MDEPS = $(DEPS:.h=.h)

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.h: %.h

%.o: %.c
	@$(CC) -c $? -o $@

$(NAME): $(OBJ) $(MDEPS)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo "ok lib"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "sup + lib ok"

re: fclean all

.PHONY = all clean fclean re
