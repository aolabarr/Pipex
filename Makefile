# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 09:34:43 by aolabarr          #+#    #+#              #
#    Updated: 2024/07/24 19:28:24 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NO_LINK = -c
CFLAGS = -Wall -Wextra -Werror -g3
SFLAGS =  -fsanitize=address

SRC_DIR = ./src
OBJ_DIR = ./obj
SRC_BONUS_DIR = ./src_bonus
OBJ_BONUS_DIR = ./obj_bonus

INC_DIR = .
LIBFT_DIR = ./lib/libft
LIBIO_DIR = ./lib/libio
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(LIBIO_DIR) -lio

SRC =	pipex_main.c \
		pipex_utils.c \
		pipex_exe.c \
		pipex_init.c \
		pipex_error.c \

SRC_BONUS =	pipex_main_bonus.c \
			pipex_utils_bonus.c \
			pipex_exe_bonus.c \
			pipex_init_bonus.c \
			pipex_init_2_bonus.c \
			pipex_error_bonus.c \
				
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_BONUS_DIR)/,$(SRC_BONUS:.c=.o))

all: lib $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	rm -f outfile.txt
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

bonus: lib $(OBJ_BONUS_DIR) $(OBJS_BONUS)
	rm -f outfile.txt
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(NAME)

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_BONUS_DIR):
	mkdir $(OBJ_BONUS_DIR)

lib:
	make -C $(LIBFT_DIR)
	make -C $(LIBIO_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBIO_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
	@if [ -d $(OBJ_BONUS_DIR) ]; then rm -rf $(OBJ_BONUS_DIR); fi
	make clean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all fclean clean re lib sanitizer

#.SILENT:
