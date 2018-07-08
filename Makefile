#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elopukh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 12:37:05 by elopukh           #+#    #+#              #
#    Updated: 2018/07/01 15:56:18 by elopukh          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
LIB_NAME = libft.a
SRC_DIR = srcs/
OBJ_DIR = obj/
INC_DIR = includes/
LIB_DIR = libft/

LFT = $(addprefix $(LIB_DIR), $(LIB_NAME))

C_FILES =	main.c \
			mandelbrot.c \
			julia.c\
			ship.c\
			newton.c\
			biomorf.c\
			cellule.c\
			love.c\
			flower.c\
			arrows.c\
			get_fract.c\
			deal_key.c\
			init.c

HEADERS = $(INC_DIR)fract.h $(LIB_DIR)libft.h

SRC = $(addprefix $(SRC_DIR), $(C_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I $(INC_DIR) -I $(LIB_DIR)
FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit
C_RED = \033[31m
C_GREEN = \033[32m
C_MAGENTA = \033[35m
C_NONE = \033[0m

all: $(NAME)


$(NAME): $(HEADERS) $(OBJ_DIR) $(OBJ)
				@make -C $(LIB_DIR)
				@$(CC) $(CFLAGS) $(OBJ) $(LFT) $(FRAMEWORKS)  -o $(NAME)
				@printf "$(C_MAGENTA)FRACT'OL:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@
$(OBJ_DIR):
				@mkdir obj
				@@printf "$(C_MAGENTA)FRACT'OL:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
				@$(CC) $(CFLAGS) -c $(INC) $< -o $@
				@@printf "$(C_MAGENTA)FRACT'OL:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@
clean:
				@rm -rf $(OBJ_DIR)*
				@make clean -C $(LIB_DIR)
				@@printf "$(C_MAGENTA)FRACT'OL:$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
				@rm -rf $(NAME)
				@make fclean -C $(LIB_DIR)
				@@printf "$(C_MAGENTA)FRACT'OL:$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all
