# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 10:36:16 by aolabarr          #+#    #+#              #
#    Updated: 2024/07/20 16:43:04 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libio.a
PRINTF = libftprintf.a

CC = cc
NO_LINK = -c
CFLAGS = -Wall -Werror -Wextra


AR = ar
ARFLAGS = -rc

PRINTF_DIR = ./ftprintf
GNL_DIR = ./gnl
OBJ_DIR = ./obj
INC_DIR = .

GNL_SRC =	get_next_line.c \
			get_next_line_utils.c \

PF_OBJ_DIR = ./ftprintf/obj
PF_OBJ = $(PF_OBJ_DIR)/*.o

OBJ = $(addprefix $(OBJ_DIR)/, $(GNL_SRC:.c=.o))

all: $(NAME)

$(NAME): sublib $(OBJ_DIR) $(OBJ) 
	$(AR) $(ARFLAGS) $(NAME) $(PF_OBJ) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

sublib:
	make -C $(PRINTF_DIR)
	ranlib $(PRINTF_DIR)/$(PRINTF) 

clean:
	make clean -C $(PRINTF_DIR)
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi

fclean: clean
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME) *.out

re: fclean all

.PHONY: all clean fclean re sublib