# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 09:34:43 by aolabarr          #+#    #+#              #
#    Updated: 2024/07/20 13:18:57 by aolabarr         ###   ########.fr        #
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
LIBIO_DIR = ./lib/libio
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(LIBIO_DIR) -lio

SRC =	pipex_main.c \
		pipex_utils.c \
		pipex_exe.c \
		pipex_init.c \
		pipex_init_2.c \
		print.c \
				

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: lib $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	rm -f outfile.txt
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

sanitizer: lib $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(SFLAGS) $(OBJS) $(LD_FLAGS) -o $(NAME)

lib:
	make -C $(LIBFT_DIR)
	make -C $(LIBIO_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBIO_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
	make clean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all fclean clean re lib sanitizer

#.SILENT:
