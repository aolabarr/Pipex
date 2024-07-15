# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 09:34:43 by aolabarr          #+#    #+#              #
#    Updated: 2024/07/15 19:33:44 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NO_LINK = -c
CFLAGS = -Wall -Wextra -Werror -g3
SFLAGS =  -fsanitize=address

OBJ_DIR = ./obj
SRC_DIR = ./src

INC_DIR = .
LIBFT_DIR = ./lib/libft

SRC =	pipex_main.c \
		pipex_utils.c \
		pipex_exe.c \
		pipex_init.c \
				

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: lib $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

sanitizer: lib $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(SFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

lib:
	make -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
	make clean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all fclean clean re lib sanitizer

#.SILENT:
